#include "ManagerModule.h"

bool ManagerModule::execute(Main& main, const string& command, const set<int>& ban)
{
    if (command == commands.at(0) && !ban.contains(0))  return true; 
    else if (command == commands.at(1) && !ban.contains(1)) {
        cout << main.logistics->manager << endl;
    }
    else if (command == commands.at(2) && !ban.contains(2)) {
        cout << "Please input the current password: ";
        string password;
        cin >> password;
        if (password == main.logistics->manager.getPassword()) {
            cout << "Please input the new password: ";
            cin >> password;
            while (password.size() > STRING_MAX_SIZE) {
                cout << "Password length should be less than " << STRING_MAX_SIZE << endl;
                cout << "Please input the new password: ";
                cin >> password;
            }
            main.logistics->manager.setPassword(password);
        }
        else {
            cout << "Password error" << endl;
        }
    }
    else if (command == commands.at(3) && !ban.contains(3)) {
        cout << "Please input the new name: ";
        string name;
        cin >> name;
        while (name.size() > STRING_MAX_SIZE) {
            cout << "Name length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Please input the new name: ";
            cin >> name;
        }
        main.logistics->manager.setName(name);
    }
    else if (command == commands.at(4) && !ban.contains(4)) {
        cout << "Please input the account information" << endl;
        string username;
        string password;
        string name;
        string phone;
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
        while (!regex_match(phone, r) || phone.length() > 11) {
            cout << "Format error, phone number consists of up to 11 digits" << endl;
            cout << "Phone Number: ";
            cin >> phone;
        }
        try {
            main.logistics->createCourierAccount(username, password, name, stoull(phone));
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(5) && !ban.contains(5)) {
        cout << "Please input the courier's username: ";
        string username;
        cin >> username;
        try {
            main.logistics->deleteCourierAccount(username);
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(6) && !ban.contains(6)) {
        cout << "Not assigned expresses:" << endl;
        try {
            main.logistics->displayNAExp();
        }
        catch (const char* msg) {
            cout << msg << endl;
            return false;
        }
        cout << endl;
        cout << "Please input the information of the express and the courier" << endl;
        cout << "Express's courier number: ";
        string courierNum;
        cin >> courierNum;
        regex r("[0-9]{10}");
        while (!regex_match(courierNum, r)) {
            cout << "Format error, courier number has 10 digits" << endl;
            cout << "Express's courier number: ";
            cin >> courierNum;
        }
        cout << "Courier's username: ";
        string username;
        cin >> username;
        try {
            main.logistics->assignExpress(main.logistics->findExpress(stoul(courierNum)), username);
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(7) && !ban.contains(7)) {
        try {
            main.logistics->displayUser();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(8) && !ban.contains(8)) {
        try {
            main.logistics->displayCourier();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(9) && !ban.contains(9)) {
        try {
            main.logistics->displayExpress();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(10) && !ban.contains(10)) {
        cout << "Please input the time information in format %Y-%m-%d %H:%M:%S" << endl;
        cout << "Lower Bound: ";
        struct tm lowerBound;
        cin >> get_time(&lowerBound, "%Y-%m-%d %H:%M:%S");
        cout << "Upper Bound: ";
        struct tm upperBound;
        cin >> get_time(&upperBound, "%Y-%m-%d %H:%M:%S");
        cout << endl;
        try {
            vector<const Express*> expresses = main.logistics->searchCreateTime(mktime(&lowerBound), mktime(&upperBound));
            for (auto temp : expresses) {
                cout << *((Express*) temp) << endl;
            }
        }   
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(11) && !ban.contains(11)) {
        string username;
        cout << "Please input the user's username: ";
        cin >> username;
        cout << endl;
        try {
            main.user = main.logistics->findUser(username);
            currentModule = 0;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(12) && !ban.contains(12)) {
        string username;
        cout << "Please input the courier's username: ";
        cin >> username;
        cout << endl;
        try {
            main.courier = main.logistics->findCourier(username);
            currentModule = 1;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(13) && !ban.contains(13)) {
        cout << "Please input the courier number: ";
        string courierNum;
        cin >> courierNum;
        regex r("[0-9]{10}");
        while(!regex_match(courierNum, r)) {
            cout << "Format error, courier number consists of 10 digits" << endl;
            cout << "Please input the courier number: ";
            cin >> courierNum;
        }
        cout << endl;
        try {
            cout << *main.logistics->findExpress(stoul(courierNum)) << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(14) && !ban.contains(14)) {
        cout << "Available commands:" << endl;
        if (!ban.contains(0))
            cout << "  " << commands.at(0) << ": return to the upper module" << endl;
        if (!ban.contains(1))
            cout << "  " << commands.at(1) << ": check the manager information" << endl;
        if (!ban.contains(2))
            cout << "  " << commands.at(2) << ": change the password" << endl;
        if (!ban.contains(3))
            cout << "  " << commands.at(3) << ": change the name" << endl;
        if (!ban.contains(4))
            cout << "  " << commands.at(4) << ": add a new courier account" << endl;
        if (!ban.contains(5))
            cout << "  " << commands.at(5) << ": delete a courier account" << endl;
        if (!ban.contains(6))
            cout << "  " << commands.at(6) << ": assign an express to a courier" << endl;
        if (!ban.contains(7))
            cout << "  " << commands.at(7) << ": display all the users' massage" << endl;
        if (!ban.contains(8))
            cout << "  " << commands.at(8) << ": display all the couriers' massage" << endl;
        if (!ban.contains(9))
            cout << "  " << commands.at(9) << ": display all the expresses' massage" << endl;
        if (!ban.contains(10))
            cout << "  " << commands.at(10) << ": search the related expresses by creating time" << endl;
        if (!ban.contains(11))
            cout << "  " << commands.at(11) << ": find the specific user and enter the user module" << endl;
        if (!ban.contains(12))
            cout << "  " << commands.at(12) << ": find the specific courier and enter the courier module" << endl;
        if (!ban.contains(13))
            cout << "  " << commands.at(13) << ": find the specific express by courier number" << endl;
        if (!ban.contains(14))
            cout << "  " << commands.at(14) << ": print this help" << endl;
    }
    else
        cout << "Unknown command" << endl;
    return false;
}