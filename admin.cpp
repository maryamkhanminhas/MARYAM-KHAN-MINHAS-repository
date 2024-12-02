#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_ROOMS = 10;
const int MAX_STAFF = 10;

// Structure to store customer details
struct Customer {
    string name;
    string phone;
    int days;
    double totalCost;
    bool isCheckedIn;
};

// Structure to store staff details
struct Staff {
    string name;
    string role;
    string phone;
};

// Arrays to store customer and staff information
Customer rooms[MAX_ROOMS];
Staff staffList[MAX_STAFF];

int staffCount = 0;

// Constants for the room rate
const double COST_PER_DAY = 100.0;

// Function to add a customer and book a room
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

    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].isCheckedIn) {
        cout << "Room is not available. Please choose another room.\n";
        return;
    }

    double totalCost = days * COST_PER_DAY;

    // Update customer details
    rooms[roomNo - 1] = {name, phone, days, totalCost, true};

    cout << "Room " << roomNo << " successfully booked for " << name << ".\n";
    cout << "Total cost: $" << totalCost << endl;
}

// Function to check out a customer
void checkOutCustomer() {
    int roomNo;

    cout << "Enter room number to check out: ";
    cin >> roomNo;

    if (roomNo < 1 || roomNo > MAX_ROOMS || !rooms[roomNo - 1].isCheckedIn) {
        cout << "Room is not occupied.\n";
        return;
    }

    cout << "Customer " << rooms[roomNo - 1].name << " has checked out from room " << roomNo << ".\n";

    // Reset room details
    rooms[roomNo - 1].isCheckedIn = false;
}

// Function to view all bookings
void viewBookings() {
    bool found = false;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (rooms[i].isCheckedIn) {
            found = true;
            cout << "Room " << (i + 1) << ": " << rooms[i].name << " (Phone: " << rooms[i].phone << ", Days: " << rooms[i].days << ", Total Cost: $" << rooms[i].totalCost << ")\n";
        }
    }

    if (!found) {
        cout << "No customers checked in at the moment.\n";
    }
}

// Function to add a staff member
void addStaff() {
    if (staffCount >= MAX_STAFF) {
        cout << "Staff capacity is full.\n";
        return;
    }

    cout << "Enter staff name: ";
    cin.ignore();
    getline(cin, staffList[staffCount].name);

    cout << "Enter staff role (e.g., Manager, Housekeeping, Chef): ";
    getline(cin, staffList[staffCount].role);

    cout << "Enter staff phone number: ";
    cin >> staffList[staffCount].phone;

    staffCount++;
    cout << "Staff member added successfully.\n";
}

// Function to view all staff
void viewAllStaff() {
    if (staffCount == 0) {
        cout << "No staff members added.\n";
        return;
    }

    cout << "\nList of Staff Members:\n";
    for (int i = 0; i < staffCount; ++i) {
        cout << "Staff ID: " << (i + 1) << "\n";
        cout << "Name: " << staffList[i].name << "\n";
        cout << "Role: " << staffList[i].role << "\n";
        cout << "Phone: " << staffList[i].phone << "\n";
        cout << "-------------------------\n";
    }
}

// Function to remove a staff member
void removeStaff() {
    int staffId;

    cout << "Enter Staff ID to remove (1 to " << staffCount << "): ";
    cin >> staffId;

    if (staffId < 1 || staffId > staffCount) {
        cout << "Invalid Staff ID.\n";
        return;
    }

    // Shift elements to remove the staff member
    for (int i = staffId - 1; i < staffCount - 1; ++i) {
        staffList[i] = staffList[i + 1];
    }

    staffCount--;
    cout << "Staff member removed successfully.\n";
}

// Main function for admin interface
int main() {
    int choice;

    do {
        cout << "\nHotel Management System - Admin Panel\n";
        cout << "1. Add Customer\n";
        cout << "2. Check Out Customer\n";
        cout << "3. View Bookings\n";
        cout << "4. Add Staff\n";
        cout << "5. View All Staff\n";
        cout << "6. Remove Staff\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            checkOutCustomer();
            break;
        case 3:
            viewBookings();
            break;
        case 4:
            addStaff();
            break;
        case 5:
            viewAllStaff();
            break;
        case 6:
            removeStaff();
            break;
        case 7:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
