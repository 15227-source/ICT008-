#include <iostream>
#include <string>
#include <array>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isBorrowed;

public:
    Book() {
        isBorrowed = false;
    }

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isBorrowed = false;
    }

    void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
        cout << "-------------------------" << endl;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Book borrowed successfully." << endl;
        }
        else {
            cout << "Book is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "Book returned successfully." << endl;
        }
        else {
            cout << "Book is already available." << endl;
        }
    }

    string getISBN() const {
        return isbn;
    }
};

int findBook(const array<Book, 5>& books, string isbn) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

int main() {
    array<Book, 5> books = {
        Book("The Great Gatsby", "F. Fitzgerald", "ISBN001"),
        Book("To Kill a Mockingbird", "Harper Lee", "ISBN002"),
        Book("1984", "George Orwell", "ISBN003"),
        Book("Pride and Prejudice", "Jane Austen", "ISBN004"),
        Book("Moby Dick", "Herman Melville", "ISBN005")
    };

    int choice;
    string isbn;

    do {
        cout << "\n1. View Books\n2. Borrow Book\n3. Return Book\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (const auto& book : books) {
                book.displayBook();
            }
            break;

        case 2:
            cout << "Enter ISBN: ";
            cin >> isbn;
            {
                int index = findBook(books, isbn);
                if (index != -1)
                    books[index].borrowBook();
                else
                    cout << "Book not found.\n";
            }
            break;

        case 3:
            cout << "Enter ISBN: ";
            cin >> isbn;
            {
                int index = findBook(books, isbn);
                if (index != -1)
                    books[index].returnBook();
                else
                    cout << "Book not found.\n";
            }
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}