#include "MainModule.h"

bool MainModule::execute(Main& main, const string& command, const set<int>& ban){
    if (command == commands.at(0) && !ban.contains(0))
        return true;
    else if (command == commands.at(1) && !ban.contains(1)) {
        string username;
        string password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        try {
            main.user = main.logistics->loginUserAccount(username, password);
            currentModule = 0;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    } 
    else if (command == commands.at(2) && !ban.contains(2)) {
        string username;
        string password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        try {
            main.courier = main.logistics->loginCourierAccount(username, password);
            currentModule = 1;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(3) && !ban.contains(3)) {
        string username;
        string password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        try {
            main.logistics->loginManagerAccount(username, password);
            currentModule = 2;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }   
    else if (command == commands.at(4) && !ban.contains(4)) {
        cout << "Please input the account information" << endl;
        string username;
        string password;
        string name;
        string phone;
        string address;
        cout << "Username: ";
        cin >> username;
        while (username.size() > STRING_MAX_SIZE) {
            cout << "Username length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Username: ";
            cin >> username;
        }
        cout << "Password: ";
        cin >> password;
        while (password.size() > STRING_MAX_SIZE) {
            cout << "Password length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Password: ";
            cin >> password;
        }
        cout << "Name: ";
        cin >> name;
        while (name.size() > STRING_MAX_SIZE) {
            cout << "Name length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Name: ";
            cin >> name;
        }
        cout << "Phone Number: ";
        cin >> phone;
        regex r("^\\d+$");
        while (!regex_match(phone,r) || phone.length() > 11 ){
            cout << "Format error, phone number consists of up to 11 digits" << endl;
            cout << "Phone Number: ";
            cin >> phone;
        }
        cout << "Home Address: ";
        cin >> address;
        while (address.size() > STRING_MAX_SIZE) {
            cout << "Address length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Home Address: ";
            cin >> address;
        }
        try {
            main.logistics->createUserAccount(username, password, name, stoull(phone), address);
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(5) && !ban.contains(5)) {
        cout << "Available commands:" << endl;
        if (!ban.contains(0))
            cout << "  " << commands.at(0) << ": exit the program" << endl;
        if (!ban.contains(1))
            cout << "  " << commands.at(1) << ": enter the user module" << endl;
        if (!ban.contains(2))
            cout << "  " << commands.at(2) << ": enter the courier module" << endl;
        if (!ban.contains(3))
            cout << "  " << commands.at(3) << ": enter the manager module" << endl;
        if (!ban.contains(4))
            cout << "  " << commands.at(4) << ": register a new user account" << endl;
        if (!ban.contains(5))
            cout << "  " << commands.at(5) << ": print this help" << endl;
    }
    else
        cout << "Unknown command" << endl;
    return false;
}
