#include "UserModule.h"

bool UserModule::execute(Main& main, const string& command, const set<int>& ban)
{
    if (command == commands.at(0) && !ban.contains(0))  
        return true;
    else if (command == commands.at(1) && !ban.contains(1)) 
        cout << *main.user << endl;
    else if (command == commands.at(2) && !ban.contains(2)) {
        cout << "Please input your current password: ";
        string password;
        cin >> password;
        if (password == main.user->getPassword()) {
            cout << "Please input your new password: ";
            cin >> password;
            while (password.size() > STRING_MAX_SIZE) {
                cout << "Password length should be less than " << STRING_MAX_SIZE << endl;
                cout << "Please input your new password: ";
                cin >> password;
            }
            main.user->setPassword(password);
        }
        else {
            cout << "Password error" << endl;
        }
    }
    else if (command == commands.at(3) && !ban.contains(3)) {
        cout << "Please input your new name: ";
        string name;
        cin >> name;
        while (name.size() > STRING_MAX_SIZE) {
            cout << "Name length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Please input your new name: ";
            cin >> name;
        }
        main.user->setName(name);
    }
    else if (command == commands.at(4) && !ban.contains(4)) {
        cout << "Please input your new phone number: ";
        string phone;
        cin >> phone;
        regex r("^\\d+$");
        while (!regex_match(phone, r) || phone.length() > 11) {
            cout << "Format error, phone number consists of up to 11 digits" << endl;
            cout << "Phone Number: ";
            cin >> phone;
        }
        main.user->setPhone(stoull(phone));
    }
    else if (command == commands.at(5) && !ban.contains(5)) {
        cout << "Please input your new address: ";
        string address;
        cin >> address;
        while (address.size() > STRING_MAX_SIZE) {
            cout << "Address length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Please input your new address: ";
            cin >> address;
        }
        main.user->setAddress(address);
    }
    else if (command == commands.at(6) && !ban.contains(6)) {
        cout << "Please input the amount of money you want to recharge: ";
        string money;
        cin >> money;
        regex r("^\\d+$");
        while (!regex_match(money, r) || money.length() > 9 ) {
            if (!regex_match(money, r))
                cout << "Format error, please input a positive integer" << endl;
            else
                cout << "The amount of money exceeds the limit" << endl;
            cout << "Please input the amount of money you want to recharge: ";
            cin >> money;
        }
        main.user->addBalance(stoul(money));
    }
    else if (command == commands.at(7) && !ban.contains(7)) {
        cout << "Please input the express information" << endl;
        cout << "Receiver's username: ";
        string receiver;
        cin >> receiver;
        cout << "Condition: ";
        string condition;
        cin >> condition;
        cout << "Description: ";
        string description;
        cin >> description;
        cout << "Kind(";
        for (int i = 0; i < Express::subKind().size() - 1; i++) {
            cout << Express::subKind().at(i) << "/";
        }
        cout << Express::subKind().at(Express::subKind().size() - 1) << "): ";
        string kind;
        cin >> kind;
        cout << "Amount: ";
        string amount;
        cin >> amount;
        regex r("^\\d+$");
        while (!regex_match(amount, r) || amount.length() > 9 ) {
            if (!regex_match(amount, r))
                cout << "Format error, please input a positive integer" << endl;
            else
                cout << "The amount exceeds the limit" << endl;
            cout << "Amount: ";
            cin >> amount;
        }
        try {
            main.logistics->createLogistics(main.user->getUsername(), receiver, condition, description, stoul(amount), kind);
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(8) && !ban.contains(8)) {
        cout << "Not signed-for expresses:" << endl;
        try {
            main.user->displayNRExp();
        }
        catch (const char* msg) {
            cout << msg << endl;
            return false;
        }
        cout << endl;
        cout << "Please input the courier numbers of the expresses you want to sign for" << endl;
        cout << "Note: input '#' as the end" << endl;
        unsigned int i = 1;
        cout << i << ": ";
        string courierNum;
        cin >> courierNum;
        regex r("[0-9]{10}");
        while (!(regex_match(courierNum, r) || courierNum == "#")) {
            cout << "Format error, please input a 10-digits courier number or '#'" << endl;
            cout << i << ": ";
            cin >> courierNum;
        } 
        while (courierNum != "#") {
            try {
                Express* pExpress = main.logistics->findExpress(stoul(courierNum));
                if (pExpress->getReceiver() == main.user->getUsername())
                    main.logistics->signForExpress(pExpress);
                else
                    cout << "You can not sign for this express" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            i++;
            cout << i << ": ";
            cin >> courierNum;
            while (!(regex_match(courierNum, r) || courierNum == "#")) {
                cout << "Format error, please input a 10-digits courier number or '#'" << endl;
                cout << i << ": ";
                cin >> courierNum;
            }
        }
    }
    else if (command == commands.at(9) && !ban.contains(9)) 
        currentModule = 0;
    else if (command == commands.at(10) && !ban.contains(10)) 
        currentModule = 1;
    else if (command == commands.at(11) && !ban.contains(11)) {
        cout << "Please input the courier number: ";
        string courierNum;
        cin >> courierNum;
        regex r("[0-9]{10}");
        while(!regex_match(courierNum, r)) {
            cout << "Format error, courier number has 10 digits" << endl;
            cout << "Please input the courier number: ";
            cin >> courierNum;
        }
        try {
            cout << *main.logistics->findExpress(stoul(courierNum)) << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(12) && !ban.contains(12)) {
        cout << "Available commands:" << endl;
        if (!ban.contains(0))
            cout << "  " << commands.at(0) << ": return to the upper module" << endl;
        if (!ban.contains(1))
            cout << "  " << commands.at(1) << ": check your information" << endl;
        if (!ban.contains(2))
            cout << "  " << commands.at(2) << ": change your password" << endl;
        if (!ban.contains(3))
            cout << "  " << commands.at(3) << ": change your name" << endl;
        if (!ban.contains(4))
            cout << "  " << commands.at(4) << ": change your phone number" << endl;
        if (!ban.contains(5))
            cout << "  " << commands.at(5) << ": change your address" << endl;
        if (!ban.contains(6))
            cout << "  " << commands.at(6) << ": recharge your balance" << endl;
        if (!ban.contains(7))
            cout << "  " << commands.at(7) << ": send an express" << endl;
        if (!ban.contains(8))
            cout << "  " << commands.at(8) << ": sign for expresses" << endl;
        if (!ban.contains(9))
            cout << "  " << commands.at(9) << ": enter the sending information module" << endl;
        if (!ban.contains(10))
            cout << "  " << commands.at(10) << ": enter the receiving information module" << endl;
        if (!ban.contains(11))
            cout << "  " << commands.at(11) << ": find the specific expresses by courier number" << endl;
        if (!ban.contains(12))
            cout << "  " << commands.at(12) << ": print this help" << endl;
    }
    else
        cout << "Unknown command" << endl;
    return false;
}
