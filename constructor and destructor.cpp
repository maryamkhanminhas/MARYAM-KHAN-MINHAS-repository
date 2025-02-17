#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
   
    Book(string t, string a, string i) {
        cout << "Book \"" << title << "\" by " << author << " added to the system.\n";
    }

    // Method to display book details
    void displayDetails() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn << "\n";
    }

    // Destructor to display a message when the book is removed
    ~Book() {
        cout << "Book \"" << title << "\" has been removed from the system.\n";
    }
};

int main() {
    // Creating a book object
    Book book1("1984", "George Orwell", "978-0451524935");
    
    // Display book details
    book1.displayDetails();

    // The destructor is automatically called when the object goes out of scope
    return 0;
}
