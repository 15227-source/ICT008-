#ifndef TEST1_H
#define TEST1_H

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
    Author() : firstName(""), lastName("") {}

    Author(string f, string l) {
        firstName = f;
        lastName = l;
    }

    string getFullName() const {
        return firstName + " " + lastName;
    }

    bool isValid() const {
        return !firstName.empty() && !lastName.empty();
    }
};

class Book {
protected:
    string title;
    vector<Author> authors;
    string isbn;
    bool isBorrowed;

public:
    Book() : title(""), isbn(""), isBorrowed(false) {}

    Book(string t, vector<Author> a, string i) {
        title = t;
        authors = a;
        isbn = i;
        isBorrowed = false;
    }

    virtual ~Book() {}

    virtual void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (size_t i = 0; i < authors.size(); i++) {
            cout << authors[i].getFullName();
            if (i < authors.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
        }
    }

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    virtual bool isValid() const {
        if (title.empty() || isbn.empty() || authors.empty()) {
            return false;
        }

        for (const auto& author : authors) {
            if (!author.isValid()) {
                return false;
            }
        }

        return isbn.rfind("ISBN", 0) == 0;
    }
};

class HardcopyBook : public Book {
private:
    string shelfLocation;

public:
    HardcopyBook() : Book(), shelfLocation("") {}

    HardcopyBook(string t, vector<Author> a, string i, string shelf)
        : Book(t, a, i), shelfLocation(shelf) {
    }

    void displayBook() const override {
        Book::displayBook();
        cout << "Shelf Location: " << shelfLocation << endl;
        cout << "-------------------------" << endl;
    }

    bool isValid() const override {
        return Book::isValid() && !shelfLocation.empty();
    }
};

class EBook : public Book {
private:
    double fileSize;
    string format;

public:
    EBook() : Book(), fileSize(0.0), format("") {}

    EBook(string t, vector<Author> a, string i, double size, string f)
        : Book(t, a, i), fileSize(size), format(f) {
    }

    void displayBook() const override {
        Book::displayBook();
        cout << "File Size: " << fileSize << "MB" << endl;
        cout << "Format: " << format << endl;
        cout << "-------------------------" << endl;
    }

    bool isValid() const override {
        return Book::isValid() && fileSize > 0 && !format.empty();
    }
};

#endif