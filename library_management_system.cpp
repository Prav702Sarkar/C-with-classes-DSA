#include <iostream>   // For input-output operations
#include <string>     // For using string data type
using namespace std;  // Avoid writing 'std::' again and again

// Define maximum number of books and members allowed
const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 50;

// Book class representing a single book
class Book {
public:
    string title;     // Book title
    string author;    // Author name
    bool available;   // Availability status (true = available, false = issued)

    // Default constructor initializes empty book with availability as true
    Book() : title(""), author(""), available(true) {}

    // Parameterized constructor for setting title and author
    Book(string t, string a) : title(t), author(a), available(true) {}

    // Display book information
    void display() {
        cout << "Title: " << title << "\nAuthor: " << author 
             << "\nStatus: " << (available ? "Available" : "Issued") << endl;
    }
};

// Member class representing a library member
class Member {
public:
    string name;  // Member's name
    int id;       // Member's ID

    // Default constructor
    Member() : name(""), id(0) {}

    // Parameterized constructor
    Member(string n, int i) : name(n), id(i) {}

    // Display member details
    void display() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

// Library class to manage books and members
class Library {
private:
    Book books[MAX_BOOKS];       // Array to store books
    Member members[MAX_MEMBERS]; // Array to store members
    int bookCount;               // Count of books currently in library
    int memberCount;             // Count of registered members

public:
    // Constructor initializes book and member counters
    Library() : bookCount(0), memberCount(0) {}

    // Function to add a new book
    void addBook() {
        if (bookCount < MAX_BOOKS) {
            string title, author;
            cout << "Enter book title: ";
            getline(cin, title);  // Read full line including spaces
            cout << "Enter author: ";
            getline(cin, author);

            books[bookCount] = Book(title, author); // Create and add new Book
            bookCount++;                            // Increment book counter
            cout << "Book added successfully!\n";
        } else {
            cout << "Library is full. Cannot add more books.\n";
        }
    }

    // Function to add a new member
    void addMember() {
        if (memberCount < MAX_MEMBERS) {
            string name;
            int id;
            cout << "Enter member name: ";
            getline(cin, name);   // Read member name
            cout << "Enter member ID: ";
            cin >> id;            // Read member ID
            cin.ignore();         // Clear buffer after numeric input

            members[memberCount] = Member(name, id); // Add new member
            memberCount++;                           // Increment member counter
            cout << "Member added successfully!\n";
        } else {
            cout << "Member list is full. Cannot add more members.\n";
        }
    }

    // Function to issue a book to a member
    void issueBook() {
        int bookIndex, memberIndex;

        cout << "\nAvailable Books:\n";
        // Show only books that are available
        for (int i = 0; i < bookCount; i++) {
            if (books[i].available) {
                cout << i << ". " << books[i].title << endl;
            }
        }

        cout << "Enter book number to issue: ";
        cin >> bookIndex;
        cin.ignore(); // Clear buffer

        // Check for valid book index and availability
        if (bookIndex < 0 || bookIndex >= bookCount || !books[bookIndex].available) {
            cout << "Invalid book selection.\n";
            return;
        }

        cout << "\nMembers:\n";
        // List all members
        for (int i = 0; i < memberCount; i++) {
            cout << i << ". " << members[i].name << endl;
        }

        cout << "Enter member number: ";
        cin >> memberIndex;
        cin.ignore(); // Clear buffer

        // Check for valid member index
        if (memberIndex < 0 || memberIndex >= memberCount) {
            cout << "Invalid member selection.\n";
            return;
        }

        books[bookIndex].available = false; // Mark book as issued
        cout << "Book '" << books[bookIndex].title 
             << "' issued to " << members[memberIndex].name << ".\n";
    }

    // Function to return an issued book
    void returnBook() {
        int bookIndex;

        cout << "\nIssued Books:\n";
        // Show only issued books
        for (int i = 0; i < bookCount; i++) {
            if (!books[i].available) {
                cout << i << ". " << books[i].title << endl;
            }
        }

        cout << "Enter book number to return: ";
        cin >> bookIndex;
        cin.ignore(); // Clear buffer

        // Check for valid selection and whether book is actually issued
        if (bookIndex < 0 || bookIndex >= bookCount || books[bookIndex].available) {
            cout << "Invalid book selection.\n";
            return;
        }

        books[bookIndex].available = true; // Mark book as returned
        cout << "Book '" << books[bookIndex].title << "' returned successfully.\n";
    }

    // Function to display all books
    void displayBooks() {
        cout << "\nLibrary Books:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << "Book " << i << ":\n";
            books[i].display();
            cout << endl;
        }
    }

    // Function to display all members
    void displayMembers() {
        cout << "\nLibrary Members:\n";
        for (int i = 0; i < memberCount; i++) {
            cout << "Member " << i << ":\n";
            members[i].display();
            cout << endl;
        }
    }
};

// Displays the menu options to the user
void showMenu() {
    cout << "\n===== Simple Library System =====\n";
    cout << "1. Add Book\n";
    cout << "2. Add Member\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. Display All Books\n";
    cout << "6. Display All Members\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Entry point of the program
int main() {
    system("cls"); // Clears the console screen (works on Windows)
    Library library;  // Create a Library object
    int choice;       // Store user menu choice

    // Loop until user chooses to exit
    do {
        showMenu();        // Display the menu
        cin >> choice;     // Read user input
        cin.ignore();      // Clear newline character from buffer

        // Perform actions based on user input
        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.addMember(); break;
            case 3: library.issueBook(); break;
            case 4: library.returnBook(); break;
            case 5: library.displayBooks(); break;
            case 6: library.displayMembers(); break;
            case 7: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7); // Continue until exit option is chosen

    return 0; // Exit the program
}
