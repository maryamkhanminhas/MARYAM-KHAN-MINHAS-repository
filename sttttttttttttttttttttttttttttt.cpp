#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Constants
const int MAX_ROOMS = 10;
const double COST_PER_DAY = 100.0;

// Room structure for hotel management
struct Room {
    string status;        // Room status: "Available" or "Occupied"
    string customerName;  // Name of the customer
    string phone;         // Customer phone number
    int days;             // Number of days staying
    double totalCost;     // Total cost after discount
};

// Staff structure
struct Staff {
    string name;
    string position;
    string username;
    string password;
};

// Global variables
Room rooms[MAX_ROOMS];
vector<Staff> staffList; // List of staff members

// Function Prototypes
void initializeRooms();
bool loginAuthentication();
void adminPortal();
void customerPortal();
void staffPortal();
void addCustomer();
void displayBill(int roomNo);
void checkOut(int roomNo);
void viewAllCustomers();
void showAvailableRooms();
void manageStaff();
void addStaff();
void removeStaff();
void listStaff();
void adminMenu();
void customerMenu();
void staffMenu();
bool staffLogin();
void updateRoomStatus(int roomNo);
void generateReport();
void initializeStaff();

// Initialize rooms
void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; ++i) {
        rooms[i].status = "Available";
        rooms[i].customerName = "";
        rooms[i].phone = "";
        rooms[i].days = 0;
        rooms[i].totalCost = 0.0;
    }
}

// Initialize staff members
void initializeStaff() {
    staffList.push_back({"admin", "Manager", "admin", "1234"});
    staffList.push_back({"john_doe", "Receptionist", "john", "abcd"});
    // Add more staff as needed
}

// Authentication for Admin
bool loginAuthentication() {
    string username;
    int password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == 1234) {
        cout << "Admin login successful!\n";
        return true;
    } else {
        cout << "Invalid username or password. Access denied.\n";
        return false;
    }
}

// Admin Portal
void adminPortal() {
    char choice;
    do {
        adminMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                manageStaff();
                break;
            case '2':
                viewAllCustomers();
                break;
            case '3':
                showAvailableRooms();
                break;
            case '4':
                generateReport();
                break;
            case '5':
                cout << "Exiting Admin Portal.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != '5');
}

// Customer Portal
void customerPortal() {
    char choice;
    do {
        customerMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                addCustomer();
                break;
            case '2':
                {
                    int roomNo;
                    cout << "Enter room number to view bill: ";
                    cin >> roomNo;
                    displayBill(roomNo);
                }
                break;
            case '3':
                {
                    int roomNo;
                    cout << "Enter room number to check out: ";
                    cin >> roomNo;
                    checkOut(roomNo);
                }
                break;
            case '4':
                cout << "Exiting Customer Portal.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != '4');
}

// Staff Portal
void staffPortal() {
    char choice;
    do {
        staffMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                viewAllCustomers();
                break;
            case '2':
                showAvailableRooms();
                break;
            case '3':
                {
                    int roomNo;
                    cout << "Enter room number to update status: ";
                    cin >> roomNo;
                    updateRoomStatus(roomNo);
                }
                break;
            case '4':
                cout << "Exiting Staff Portal.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != '4');
}

// Show the available rooms for booking
void showAvailableRooms() {
    cout << "Available Rooms:\n";
    bool found = false;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (rooms[i].status == "Available") {
            cout << "Room " << i + 1 << " is available.\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No rooms available.\n";
    }
}

// Admin Menu
void adminMenu() {
    cout << "\nAdmin Menu:\n";
    cout << "1. Manage Staff\n";
    cout << "2. View All Customers\n";
    cout << "3. Show Available Rooms\n";
    cout << "4. Generate Report\n";
    cout << "5. Exit Admin Portal\n";
    cout << "Enter your choice: ";
}

// Customer Menu
void customerMenu() {
    cout << "\nCustomer Menu:\n";
    cout << "1. Book a Room\n";
    cout << "2. View Bill\n";
    cout << "3. Check Out\n";
    cout << "4. Exit Customer Portal\n";
    cout << "Enter your choice: ";
}

// Staff Menu
void staffMenu() {
    cout << "\nStaff Menu:\n";
    cout << "1. View All Customers\n";
    cout << "2. Show Available Rooms\n";
    cout << "3. Update Room Status\n";
    cout << "4. Exit Staff Portal\n";
    cout << "Enter your choice: ";
}

// Add customer to the room
void addCustomer() {
    string name, phone;
    int days, roomNo;

    cout << "Enter customer name: ";
    cin.ignore(); // To handle leftover newline character
    getline(cin, name);

    cout << "Enter customer phone number: ";
    cin >> phone;

    cout << "Enter number of days staying: ";
    cin >> days;

    cout << "Enter room number to book (1-10): ";
    cin >> roomNo;

    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].status == "Occupied") {
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

// Display the bill for a customer
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

// Check out the customer from the room
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

// View All Customers
void viewAllCustomers() {
    cout << "\nList of All Customers:\n";
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (rooms[i].status == "Occupied") {
            cout << "Room " << i + 1 << ": " << rooms[i].customerName << " (" << rooms[i].phone << ")\n";
        }
    }
}

// Update room status by staff
void updateRoomStatus(int roomNo) {
    if (roomNo < 1 || roomNo > MAX_ROOMS) {
        cout << "Invalid room number.\n";
        return;
    }

    cout << "Updating status of room " << roomNo << ".\n";
    // Update room status as cleaned or ready by staff
    cout << "Enter room status (Available/Occupied): ";
    string status;
    cin >> status;
    rooms[roomNo - 1].status = status;
    cout << "Room " << roomNo << " status updated to " << status << ".\n";
}

// Generate Report
void generateReport() {
    cout << "Generating report of all customers:\n";
    viewAllCustomers();
}

int main() {
    initializeRooms();
    initializeStaff();

    cout << "Hotel Management System\n";
    char mainChoice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Admin Portal\n";
        cout << "2. Customer Portal\n";
        cout << "3. Staff Portal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case '1':
                if (loginAuthentication()) {
                    adminPortal();
                }
                break;
            case '2':
                customerPortal();
                break;
            case '3':
                if (staffLogin()) {
                    staffPortal();
                }
                break;
            case '4':
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (mainChoice != '4');

    return 0;
}
