#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_STAFF = 100;

// Structure to store staff details
struct Staff {
    string name;
    string role;
    string phone;
};

// Array to store staff information
Staff staffList[MAX_STAFF];
int staffCount = 0;

// Function to add a staff member
void addStaff() {
    if (staffCount >= MAX_STAFF) {
        cout << "Staff capacity is full. Cannot add more staff.\n";
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

// Function to view all staff members
void viewAllStaff() {
    if (staffCount == 0) {
        cout << "No staff members available.\n";
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
    int id;
    cout << "Enter Staff ID to remove (1 to " << staffCount << "): ";
    cin >> id;

    if (id < 1 || id > staffCount) {
        cout << "Invalid Staff ID.\n";
        return;
    }

    // Shift elements to the left to remove the staff
    for (int i = id - 1; i < staffCount - 1; ++i) {
        staffList[i] = staffList[i + 1];
    }
    staffCount--;

    cout << "Staff member removed successfully.\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\nHotel Management System - Staff Services\n";
        cout << "1. Add Staff\n";
        cout << "2. View All Staff\n";
        cout << "3. Remove Staff\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStaff();
            break;
        case 2:
            viewAllStaff();
            break;
        case 3:
            removeStaff();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
