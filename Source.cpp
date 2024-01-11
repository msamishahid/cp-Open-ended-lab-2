#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_BOOKS = 6;

struct Book {
    string title, author, genre;
    int publicationYear;
};

void inputDetails(Book books[]) {
    cout << "Enter details for six books:\n";
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "Title: "; getline(cin, books[i].title);
        cout << "Author: "; getline(cin, books[i].author);
        cout << "Publication Year: "; cin >> books[i].publicationYear; cin.ignore();
        cout << "Genre: "; getline(cin, books[i].genre);
        cout << endl;
    }
}

void categorizeBooks(Book books[], Book fiction[], int& fCount, Book nonFiction[], int& nfCount) {
    for (int i = 0; i < NUM_BOOKS; ++i) {
        (books[i].genre == "Fiction") ? fiction[fCount++] = books[i] : nonFiction[nfCount++] = books[i];
    }
}

Book findEarliestBook(Book books[], int count) {
    Book earliestBook = books[0];
    for (int i = 1; i < count; ++i) if (books[i].publicationYear < earliestBook.publicationYear) earliestBook = books[i];
    return earliestBook;
}

void displayBooks(Book books[], int count, string category) {
    cout << "\nDetails for " << category << " books:\n";
    for (int i = 0; i < count; ++i) {
        cout << "--------------------------\n";
        cout << "Title: " << books[i].title << "\nAuthor: " << books[i].author
            << "\nPublication Year: " << books[i].publicationYear << "\nGenre: " << books[i].genre << "\n\n";
    }
}

int main() {
    Book books[NUM_BOOKS], fiction[NUM_BOOKS], nonFiction[NUM_BOOKS];
    int fCount = 0, nfCount = 0;

    inputDetails(books);
    categorizeBooks(books, fiction, fCount, nonFiction, nfCount);

    cout << "\n************ Book Library ************\n";
    displayBooks(fiction, fCount, "Fiction");
    displayBooks(nonFiction, nfCount, "Non-Fiction");

    Book earliestFiction = findEarliestBook(fiction, fCount);
    Book earliestNonFiction = findEarliestBook(nonFiction, nfCount);

    cout << "\n***** Earliest Published Books *****\n";
    cout << "Fiction: " << earliestFiction.title << " (" << earliestFiction.publicationYear << ")\n";
    cout << "Non-Fiction: " << earliestNonFiction.title << " (" << earliestNonFiction.publicationYear << ")\n";

    return 0;
}
