#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoggingIn() {
    string username, password, user, pass;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: "; 
    cin >> password;
    
    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "Error" << endl;
        return false;
    }
    
    getline(file, user);
    getline(file, pass);
    file.close();
    
    return (username == user && password == pass);
}

void RegisterUser() {
    string username, password;
    
    cout << "Select username: ";
    cin >> username;
    cout << "Select password: ";
    cin >> password;
    
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    
    cout << "Registration successful." << endl;
}

int main() {
    int choice;
    
    while (true) {
        cout << "1. Register\n2. Login\n3. Exit" << endl;
        cin >> choice;
        
        if (choice == 1) {
            RegisterUser();
        } else if (choice == 2) {
            bool status = LoggingIn();
            if (status) {
                cout << "Login successful." << endl;
            } else {
                cout << "Incorrect information." << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }
    
    return 0;
}