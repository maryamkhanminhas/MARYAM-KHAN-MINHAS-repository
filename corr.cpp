#include <iostream>
#include <string>
using namespace std;

const int MAX_ROOMS = 10;
string rooms[MAX_ROOMS];           // Room statuses ("Available" or customer name)
string customerDetails[MAX_ROOMS]; // Customer details (name and info)

const string ADMIN_PASSWORD = "MKM"; // Predefined admin password

// Function Prototypes
void initializeRooms();
void showMenu();
void bookRoom();
void checkOut();
void viewRoomStatuses();
bool authenticateUser();  // Function to authenticate user

// Initialize all rooms as "Available"
void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; ++i) {
        rooms[i] = "Available";
        customerDetails[i] = "";
    }
}

// Authenticate user by checking password
bool authenticateUser() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;

    if (password == ADMIN_PASSWORD) {
        return true;
    } else {
        cout << "Incorrect password. Access denied.\n";
        return false;
    }
}

int main() {
    // Authenticate before allowing access to the system
    if (!authenticateUser()) {
        return 0; // Exit the program if authentication fails
    }

    initializeRooms();
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                viewRoomStatuses();
                break;
            case 4:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Display menu
void showMenu() {
    cout << "\ncostomer portal\n";
    cout << "1. Book Room\n";
    cout << "2. Check-Out\n";
    cout << "3. View Room Statuses\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Book a room
void bookRoom() {
    int roomNum;
    string name, details;
    cout << "Enter room number to book (1-" << MAX_ROOMS << "): ";
    cin >> roomNum;

    if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
        if (rooms[roomNum - 1] == "Available") {
            cin.ignore(); // Clear input buffer
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your details (e.g., contact or ID): ";
            getline(cin, details);

            rooms[roomNum - 1] = name;
            customerDetails[roomNum - 1] = details;

            cout << "Room " << roomNum << " successfully booked for " << name << ".\n";
        } else {
            cout << "Room " << roomNum << " is already occupied.\n";
        }
    } else {
        cout << "Invalid room number. Please enter a number between 1 and " << MAX_ROOMS << ".\n";
    }
}

// Check out of a room
void checkOut() {
    int roomNum;
    cout << "Enter room number to check-out (1-" << MAX_ROOMS << "): ";
    cin >> roomNum;

    if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
        if (rooms[roomNum - 1] != "Available") {
            cout << "Room " << roomNum << " is checked out.\n";
            cout << "Customer Name: " << rooms[roomNum - 1] << "\n";
            cout << "Details: " << customerDetails[roomNum - 1] << "\n";

            rooms[roomNum - 1] = "Available";
            customerDetails[roomNum - 1] = "";
        } else {
            cout << "Room " << roomNum << " is already available.\n";
        }
    } else {
        cout << "Invalid room number. Please enter a number between 1 and " << MAX_ROOMS << ".\n";
    }
}

// View room statuses with customer details
void viewRoomStatuses() {
    cout << "\nRoom Statuses:\n";
    for (int i = 0; i < MAX_ROOMS; ++i) {
        cout << "Room " << i + 1 << " | ";
        cout << "Status: " << (rooms[i] == "Available" ? "Available" : "Occupied") << " | ";
        if (rooms[i] != "Available") {
            cout << "Customer: " << rooms[i] << " | ";
            cout << "Details: " << customerDetails[i];
        }
        cout << endl;
    }
}
