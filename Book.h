#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author, isbn; // Book attributes
    bool isAvailable;           // Availability status of the book

public:
    // Constructor to initialize a book object
    Book(string t, string a, string i, bool available = true)
        : title(t), author(a), isbn(i), isAvailable(available) {}

    // Getters for book attributes
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }
    bool checkAvailability() { return isAvailable; }

    // Mark the book as borrowed
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is currently unavailable.\n";
        }
    }

    // Mark the book as returned
    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully.\n";
    }

    // Display book details
    void display() {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << isbn
             << ", Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

#endif
