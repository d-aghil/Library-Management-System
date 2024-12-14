#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <fstream>

using namespace std;

class Library {
private:
    vector<Book> books; // Collection of books in the library

public:
    // Add a new book to the library
    void addBook(string title, string author, string isbn) {
        books.push_back(Book(title, author, isbn));
        cout << "Book added successfully.\n";
    }

    // Search for books by keyword (title, author, or ISBN)
    void searchBook(string keyword) {
        for (auto& book : books) {
            if (book.getTitle().find(keyword) != string::npos ||
                book.getAuthor().find(keyword) != string::npos ||
                book.getISBN().find(keyword) != string::npos) {
                book.display();
            }
        }
    }

    // Borrow a book by its ISBN
    void borrowBook(string isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Return a book by its ISBN
    void returnBook(string isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.returnBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Save all library data to a file
    void saveToFile(string filename) {
        ofstream file(filename);
        for (auto& book : books) {
            file << book.getTitle() << "," << book.getAuthor() << ","
                 << book.getISBN() << "," << book.checkAvailability() << "\n";
        }
        file.close();
        cout << "Data saved to " << filename << endl;
    }

    // Load library data from a file
    void loadFromFile(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "File not found.\n";
            return;
        }
        string title, author, isbn, status;
        while (getline(file, title, ',') &&
               getline(file, author, ',') &&
               getline(file, isbn, ',') &&
               getline(file, status)) {
            books.push_back(Book(title, author, isbn, status == "1"));
        }
        file.close();
        cout << "Data loaded from " << filename << endl;
    }
};

#endif
