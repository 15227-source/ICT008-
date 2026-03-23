#include <iostream>
#include <string>
#include <array>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book() {}

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
    }

    void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    array<Book, 5> books = {
        Book("The Great Gatsby", "F. Fitzgerald", "ISBN001"),
        Book("To Kill a Mockingbird", "Harper Lee", "ISBN002"),
        Book("1984", "George Orwell", "ISBN003"),
        Book("Pride and Prejudice", "Jane Austen", "ISBN004"),
        Book("Moby Dick", "Herman Melville", "ISBN005")
    };

    cout << "Library Books:\n" << endl;

    for (const auto& book : books) {
        book.displayBook();
    }

    return 0;
}