#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {
    Library library;

    // Load existing book data from the file
    library.loadFromFile("data/library_data.txt");

    int choice;
    do {
        // Display the main menu
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Search Book\n3. Borrow Book\n4. Return Book\n5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add a new book
            string title, author, isbn;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            library.addBook(title, author, isbn);
            break;
        }
        case 2: {
            // Search for books by keyword
            string keyword;
            cout << "Enter keyword to search: ";
            cin.ignore();
            getline(cin, keyword);
            library.searchBook(keyword);
            break;
        }
        case 3: {
            // Borrow a book by ISBN
            string isbn;
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            library.borrowBook(isbn);
            break;
        }
        case 4: {
            // Return a book by ISBN
            string isbn;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            library.returnBook(isbn);
            break;
        }
        case 5:
            // Save the library data and exit the program
            library.saveToFile("data/library_data.txt");
            cout << "Exiting the system.\n";
            break;
        default:
            // Handle invalid choices
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
