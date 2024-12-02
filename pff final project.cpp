#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ROOMS = 10;
const double COST_PER_DAY = 100.0;

struct Room {
    string status;        // Room status: "Available" or "Occupied"
    string customerName;  // Name of the customer
    string phone;         // Customer phone number
    int days;             // Number of days staying
    double totalCost;     // Total cost after discount
};

// Array to store room information
Room rooms[MAX_ROOMS];

// Function to initialize rooms
void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; ++i) {
        rooms[i].status = "Available";
        rooms[i].customerName = "";
        rooms[i].phone = "";
        rooms[i].days = 0;
        rooms[i].totalCost = 0.0;
    }
}

// Add a customer and book a room
void addCustomer() {
    string name, phone;
    int days, roomNo;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter customer phone number: ";
    cin >> phone;

    cout << "Enter number of days staying: ";
    cin >> days;

    cout << "Enter room number to book (1-10): ";
    cin >> roomNo;

    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].status != "Available") {
        cout << "Room is not available. Please choose another room.\n";
        return;
    }

    double totalCost = days * COST_PER_DAY;
    double discount = 0;

    if (days > 5) {
        discount = 0.10; // 10% discount
    } else if (days > 3) {
        discount = 0.05; // 5% discount
    }

    double discountedCost = totalCost * (1 - discount);

    // Update room details
    rooms[roomNo - 1].status = "Occupied";
    rooms[roomNo - 1].customerName = name;
    rooms[roomNo - 1].phone = phone;
    rooms[roomNo - 1].days = days;
    rooms[roomNo - 1].totalCost = discountedCost;

    cout << "Room " << roomNo << " successfully booked for " << name << ".\n";
    cout << "Total cost after discount: $" << fixed << setprecision(2) << discountedCost << endl;
}

// Display bill for a room
void displayBill(int roomNo) {
    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].status == "Available") {
        cout << "Room " << roomNo << " is not booked yet.\n";
        return;
    }

    Room &room = rooms[roomNo - 1];
    cout << "\nCustomer Bill:\n";
    cout << "Name: " << room.customerName << "\n";
    cout << "Phone: " << room.phone << "\n";
    cout << "Days Staying: " << room.days << "\n";
    cout << "Total Cost: $" << fixed << setprecision(2) << room.totalCost << "\n";
}

// Check out a customer
void checkOut(int roomNo) {
    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].status == "Available") {
        cout << "Room " << roomNo << " is not occupied.\n";
        return;
    }

    Room &room = rooms[roomNo - 1];
    cout << "Customer " << room.customerName << " has checked out from room " << roomNo << ".\n";

    // Reset room details
    room.status = "Available";
    room.customerName = "";
    room.phone = "";
    room.days = 0;
    room.totalCost = 0.0;
}

// Show all customers
void viewAllCustomers() {
    cout << "\nList of Occupied Rooms:\n";
    bool found = false;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (rooms[i].status == "Occupied") {
            found = true;
            cout << "Room " << (i + 1) << ": " << rooms[i].customerName 
                 << " (Phone: " << rooms[i].phone << ")\n";
        }
    }
    if (!found) {
        cout << "No occupied rooms at the moment.\n";
    }
}

// Show available rooms
void showAvailableRooms() {
    cout << "\nAvailable Rooms:\n";
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (rooms[i].status == "Available") {
            cout << "Room " << (i + 1) << "\n";
        }
    }
}

int main() {
    int choice, roomNo;

    initializeRooms();

    do {
        cout << "\nHotel Management System\n";
        cout << "1. Add Customer\n";
        cout << "2. Display Bill\n";
        cout << "3. Check Out Customer\n";
        cout << "4. View All Customers\n";
        cout << "5. Show Available Rooms\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            cout << "Enter room number to display bill: ";
            cin >> roomNo;
            displayBill(roomNo);
            break;
        case 3:
            cout << "Enter room number to check out: ";
            cin >> roomNo;
            checkOut(roomNo);
            break;
        case 4:
            viewAllCustomers();
            break;
        case 5:
            showAvailableRooms();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
