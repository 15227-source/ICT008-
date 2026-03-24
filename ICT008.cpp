#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Author {
private:
    string firstName;
    string lastName;

public:
    Author(string f, string l) {
        firstName = f;
        lastName = l;
    }

    string getFullName() const {
        return firstName + " " + lastName;
    }
};

class Book {
protected:
    string title;
    vector<Author> authors;
    string isbn;
    bool isBorrowed;

public:
    Book(string t, vector<Author> a, string i) {
        title = t;
        authors = a;
        isbn = i;
        isBorrowed = false;
    }

    virtual void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (int i = 0; i < authors.size(); i++) {
            cout << authors[i].getFullName();
            if (i < authors.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Book borrowed successfully.\n";
        }
        else {
            cout << "Already borrowed.\n";
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "Book returned successfully.\n";
        }
        else {
            cout << "Already available.\n";
        }
    }

    string getISBN() const {
        return isbn;
    }
};

class HardcopyBook : public Book {
private:
    string shelfLocation;

public:
    HardcopyBook(string t, vector<Author> a, string i, string shelf)
        : Book(t, a, i), shelfLocation(shelf) {
    }

    void displayBook() const override {
        Book::displayBook();
        cout << "Shelf Location: " << shelfLocation << endl;
        cout << "-------------------------" << endl;
    }
};

class EBook : public Book {
private:
    double fileSize;
    string format;

public:
    EBook(string t, vector<Author> a, string i, double size, string f)
        : Book(t, a, i), fileSize(size), format(f) {
    }

    void displayBook() const override {
        Book::displayBook();
        cout << "File Size: " << fileSize << "MB" << endl;
        cout << "Format: " << format << endl;
        cout << "-------------------------" << endl;
    }
};

int findBook(const array<Book*, 5>& books, string isbn) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

int main() {
    array<Book*, 5> books = {
        new HardcopyBook("1984", {Author("George","Orwell")}, "ISBN001", "A1"),
        new EBook("Good Omens", {Author("Neil","Gaiman"), Author("Terry","Pratchett")}, "ISBN002", 2.5, "PDF"),
        new HardcopyBook("Dracula", {Author("Bram","Stoker")}, "ISBN003", "B2"),
        new EBook("The Hobbit", {Author("J.R.R.","Tolkien")}, "ISBN004", 3.1, "EPUB"),
        new HardcopyBook("Pride and Prejudice", {Author("Jane","Austen")}, "ISBN005", "C3")
    };

    int choice;
    string isbn;

    do {
        cout << "\n1. View Books\n2. Borrow Book\n3. Return Book\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (auto book : books) {
                book->displayBook();
            }
            break;

        case 2:
            cout << "Enter ISBN: ";
            cin >> isbn;
            {
                int index = findBook(books, isbn);
                if (index != -1)
                    books[index]->borrowBook();
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
                    books[index]->returnBook();
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