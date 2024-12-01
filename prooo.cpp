#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
// Room structure to hold room information
struct Room {
    string status = "Available";
    string customerName = "";
    string phone = "";
    int days = 0;
    double totalCost = 0.0;
};

class HotelManagement {
private:
    map<int, Room> rooms; // Map of room number to room details
    const double costPerDay = 100.0;

public:
    HotelManagement() {
        // Initialize all rooms as available
        for (int i = 1; i <= 10; ++i) {
            rooms[i] = {};
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

        if (roomNo < 1 || roomNo > 10 || rooms[roomNo].status != "Available") {
            cout << "Room is not available. Please choose another room.\n";
            return;
        }

        double totalCost = days * costPerDay;
        double discount = 0;

        if (days > 5) {
            discount = 0.10; // 10% discount
        } else if (days > 3) {
            discount = 0.05; // 5% discount
        }

        double discountedCost = totalCost * (1 - discount);

        // Update room details
        rooms[roomNo] = {"Occupied", name, phone, days, discountedCost};

        cout << "Room " << roomNo << " successfully booked for " << name << ".\n";
        cout << "Total cost after discount: $" << fixed << setprecision(2) << discountedCost << endl;
    }

    // Display bill for a room
    void displayBill(int roomNo) {
        if (rooms.find(roomNo) == rooms.end() || rooms[roomNo].status == "Available") {
            cout << "Room " << roomNo << " is not booked yet.\n";
            return;
        }

        Room &room = rooms[roomNo];
        cout << "\nCustomer Bill:\n";
        cout << "Name: " << room.customerName << "\n";
        cout << "Phone: " << room.phone << "\n";
        cout << "Days Staying: " << room.days << "\n";
        cout << "Total Cost: $" << fixed << setprecision(2) << room.totalCost << "\n";
    }

    // Check out a customer
    void checkOut(int roomNo) {
        if (rooms.find(roomNo) == rooms.end() || rooms[roomNo].status == "Available") {
            cout << "Room " << roomNo << " is not occupied.\n";
            return;
        }

        Room &room = rooms[roomNo];
        cout << "Customer " << room.customerName << " has checked out from room " << roomNo << ".\n";
        room = {}; // Reset room details
    }

    // Show all customers
    void viewAllCustomers() {
        cout << "\nList of Occupied Rooms:\n";
        bool found = false;
        for (const auto &room : rooms) {
            if (room.second.status == "Occupied") {
                found = true;
                cout << "Room " << room.first << ": " << room.second.customerName 
                     << " (Phone: " << room.second.phone << ")\n";
            }
        }
        if (!found) {
            cout << "No occupied rooms at the moment.\n";
        }
    }

    // Show available rooms
    void showAvailableRooms() {
        cout << "\nAvailable Rooms:\n";
        for (const auto &room : rooms) {
            if (room.second.status == "Available") {
                cout << "Room " << room.first << "\n";
            }
        }
    }
};

int main() {
    HotelManagement hotel;
    int choice, roomNo;

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
            hotel.addCustomer();
            break;
        case 2:
            cout << "Enter room number to display bill: ";
            cin >> roomNo;
            hotel.displayBill(roomNo);
            break;
        case 3:
            cout << "Enter room number to check out: ";
            cin >> roomNo;
            hotel.checkOut(roomNo);
            break;
        case 4:
            hotel.viewAllCustomers();
            break;
        case 5:
            hotel.showAvailableRooms();
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
