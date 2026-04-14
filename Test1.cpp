#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "Test1.h"

using namespace std;

// Sort function by title
void sortBooksByTitle(array<Book*, 3>& books) {
    sort(books.begin(), books.end(), [](Book* a, Book* b) {
        return a->getTitle() < b->getTitle();
        });
}

void displayArray(const array<Book*, 3>& books, const string& heading) {
    cout << "\n" << heading << endl;
    cout << "=========================" << endl;
    for (const auto& book : books) {
        book->displayBook();
    }
}

void displayValidity(Book* book, const string& label) {
    cout << "\n" << label << endl;
    cout << "-------------------------" << endl;
    book->displayBook();
    cout << "Valid: " << (book->isValid() ? "Yes" : "No") << endl;
}

int main() {
    // 3 correct Book instances
    Book* correct1 = new HardcopyBook(
        "1984",
        { Author("George", "Orwell") },
        "ISBN001",
        "A1"
    );

    Book* correct2 = new EBook(
        "Good Omens",
        { Author("Neil", "Gaiman"), Author("Terry", "Pratchett") },
        "ISBN002",
        2.5,
        "PDF"
    );

    Book* correct3 = new HardcopyBook(
        "Dracula",
        { Author("Bram", "Stoker") },
        "ISBN003",
        "B2"
    );

    // 3 incorrect Book instances
    Book* incorrect1 = new HardcopyBook(
        "",
        { Author("Jane", "Austen") },
        "ISBN004",
        "C1"
    );

    Book* incorrect2 = new EBook(
        "Broken Book",
        { Author("", "Smith") },
        "12345",
        -2.0,
        ""
    );

    Book* incorrect3 = new HardcopyBook(
        "No Shelf Book",
        {},
        "ISBN006",
        ""
    );

    // Show correct initialisation
    displayValidity(correct1, "Correct Book 1");
    displayValidity(correct2, "Correct Book 2");
    displayValidity(correct3, "Correct Book 3");

    // Show incorrect initialisation
    displayValidity(incorrect1, "Incorrect Book 1");
    displayValidity(incorrect2, "Incorrect Book 2");
    displayValidity(incorrect3, "Incorrect Book 3");

    // Three arrays of 3 books each
    array<Book*, 3> ascendingBooks = {
        new HardcopyBook("Animal Farm", { Author("George", "Orwell") }, "ISBN101", "A2"),
        new EBook("Brave New World", { Author("Aldous", "Huxley") }, "ISBN102", 1.8, "EPUB"),
        new HardcopyBook("Catch-22", { Author("Joseph", "Heller") }, "ISBN103", "A3")
    };

    array<Book*, 3> descendingBooks = {
        new HardcopyBook("Zoo", { Author("James", "Patterson") }, "ISBN201", "D1"),
        new EBook("Yours Truly", { Author("Abby", "Jimenez") }, "ISBN202", 2.1, "PDF"),
        new HardcopyBook("Xenocide", { Author("Orson", "Card") }, "ISBN203", "D2")
    };

    array<Book*, 3> mixedBooks = {
        new HardcopyBook("Moby Dick", { Author("Herman", "Melville") }, "ISBN301", "M1"),
        new EBook("Animal Farm", { Author("George", "Orwell") }, "ISBN302", 1.2, "PDF"),
        new HardcopyBook("The Hobbit", { Author("J.R.R.", "Tolkien") }, "ISBN303", "M2")
    };

    // Show before sorting
    displayArray(ascendingBooks, "Ascending Order Array - Before Sort");
    displayArray(descendingBooks, "Descending Order Array - Before Sort");
    displayArray(mixedBooks, "Mixed Order Array - Before Sort");

    // Call sort function
    sortBooksByTitle(ascendingBooks);
    sortBooksByTitle(descendingBooks);
    sortBooksByTitle(mixedBooks);

    // Show after sorting
    displayArray(ascendingBooks, "Ascending Order Array - After Sort");
    displayArray(descendingBooks, "Descending Order Array - After Sort");
    displayArray(mixedBooks, "Mixed Order Array - After Sort");

    // Clean up
    delete correct1;
    delete correct2;
    delete correct3;
    delete incorrect1;
    delete incorrect2;
    delete incorrect3;

    for (auto book : ascendingBooks) delete book;
    for (auto book : descendingBooks) delete book;
    for (auto book : mixedBooks) delete book;

    return 0;
}