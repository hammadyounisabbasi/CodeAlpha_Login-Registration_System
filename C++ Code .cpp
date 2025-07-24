#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool userExists(string username) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }

    return false;
}


void registerUser() {
    string username, password;

    cout << "Enter a new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists. Please try another.\n";
        return;
    }

    cout << "Enter a new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app); 
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}


void loginUser() {
    string username, password;
    string u, p;
    bool found = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}


int main() {
    int choice;

    do {
        cout << "\n=== Login & Registration Menu ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Thank you for using the system. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
