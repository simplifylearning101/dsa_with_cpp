#include <iostream>  
#include <string>    
#include <cstring>   

using namespace std;

// Book class to represent a book with title, author, ID, and availability
class Book {
private:
    string title;      // Book title
    string author;     // Book author
    int id;                 // Unique book ID
    bool available;         // Availability status
public:
    
    Book(string t, string a, int i, bool avail = true) 
        : title(t), author(a), id(i), available(avail) {
        std::cout << "Book " << id << " created\n";
    }
    
    // Destructor (empty as no dynamic memory)
    ~Book() {
        std::cout << "Book " << id << " destroyed\n";
    }
    
    // Display book details
    void display() const {
        cout << "ID: " << id << ", Title: " << title 
             << ", Author: " << author 
            << ", Status: " << (available ? "Available" : "Checked Out") << "\n";
    }
    
    // Getters for search and comparison
    int getId() const { return id; }
    string getTitle() const { return title; }
    
    // Update availability
    void setAvailability(bool status) { available = status; }
};

// Library class to manage a collection of books
class Library {
private:
    Book** books;           // Dynamic array of book pointers
    int capacity;           // Total capacity
    int count;              // Current number of books
public:
    // Constructor to initialize dynamic array
    Library(int cap = 100) : capacity(cap), count(0) {
        books = new Book*[capacity];
        for (int i = 0; i < capacity; i++) books[i] = nullptr;
    }
    
    // Destructor to free dynamic memory
    ~Library() {
        for (int i = 0; i < count; i++) delete books[i];
        delete[] books;
        std::cout << "Library destroyed\n";
    }
    
    // Add a book to the library
    void addBook(string title, std::string author, int id) {
        if (count >= capacity) {
            cout << "Library full!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                std::cout << "ID " << id << " already exists!\n";
                return;
            }
        }
        books[count++] = new Book(title, author, id);
        cout << "Book added successfully\n";
    }
    
    // Remove a book by ID
    void removeBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                delete books[i];
                books[i] = books[count - 1];
                books[count - 1] = nullptr;
                count--;
                cout << "Book removed\n";
                return;
            }
        }
        cout << "Book not found\n";
    }
    
    // Search by title (overloaded function)
    void search(string title) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i]->getTitle().find(title) != string::npos) {
                books[i]->display();
                found = true;
            }
        }
        if (!found) cout << "No books found with title: " << title << "\n";
    }
    
    // Search by ID (overloaded function)
    void search(int id) const {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                books[i]->display();
                return;
            }
        }
        cout << "No book found with ID: " << id << "\n";
    }
    
    // Display all books
    void displayAll() const {
        if (count == 0) {
            cout << "Library is empty\n";
            return;
        }
        for (int i = 0; i < count; i++) books[i]->display();
    }
};

// Menu-driven interface
void menu(Library& lib) {
    while (true) {
        cout << "\n1. Add Book\n2. Remove Book\n3. Search by Title\n"
                  << "4. Search by ID\n5. Display All\n6. Exit\nOption: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear newline
        
        if (choice == 6) break;
        
        if (choice == 1) {
            string title, author;
            int id;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ID: ";
            cin >> id;
            lib.addBook(title, author, id);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            lib.removeBook(id);
        }
        else if (choice == 3) {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            lib.search(title);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            lib.search(id);
        }
        else if (choice == 5) {
            lib.displayAll();
        }
        else {
            cout << "Invalid option\n";
        }
    }
}

int main() {
    Library lib;  // Create library with default capacity
    menu(lib);    // Run menu-driven interface
    return 0;
}