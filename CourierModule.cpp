#include "CourierModule.h"

bool CourierModule::execute(Main& main, const string& command, const set<int>& ban)
{
    if (command == commands.at(0) && !ban.contains(0)) 
        return true;
    else if (command == commands.at(1) && !ban.contains(1)) 
        cout << *main.courier << endl;
    else if (command == commands.at(2) && !ban.contains(2)) {
        cout << "Please input your current password: ";
        string password;
        cin >> password;
        if (password == main.courier->getPassword()) {
            cout << "Please input your new password: ";
            cin >> password;
            while (password.size() > STRING_MAX_SIZE) {
                cout << "Password length should be less than " << STRING_MAX_SIZE << endl;
                cout << "Please input your new password: ";
                cin >> password;
            }
            main.courier->setPassword(password);
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
        main.courier->setName(name);
    }
    else if (command == commands.at(4) && !ban.contains(4)) {
        cout << "Please input your new phone number: ";
        string phone;
        cin >> phone;
        regex r("^\\d+$");
        while (!regex_match(phone, r) || phone.length() > 11) {
            cout << "Format error, phone number consists of up to 11 digits" << endl;
            cout << "Please input your new phone number: ";
            cin >> phone;
        }
        main.courier->setPhone(stoull(phone));
    }
    else if (command == commands.at(5) && !ban.contains(5)) {
        cout << "Not picked-up expresses:" << endl;
        try {
            main.courier->displayNPExp();
        }
        catch (const char* msg) {
            cout << msg << endl;
            return false;
        }
        cout << endl;
        cout << "Please input the courier numbers of not expresses you want to pick up" << endl;
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
                if (pExpress->getCourier() == main.courier->getUsername())
                    main.logistics->pickUpExpress(pExpress);
                else
                    cout << "You can not pick up this express" << endl;
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
    else if (command == commands.at(6) && !ban.contains(6)) {
        try {
            main.courier->displayNPExp();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(7) && !ban.contains(7)) {
        try {
            main.courier->displayNRExp();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(8) && !ban.contains(8)) {
        try {
            main.courier->displayRExp();
            cout << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(9) && !ban.contains(9)) {
        cout << "Please input the sender's username: ";
        string sender;
        cin >> sender;
        try {
            vector<const Express*> expresses = main.courier->searchSender(sender);
            for (auto temp : expresses)
                cout << *((Express*)temp) << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(10) && !ban.contains(10)) {
        cout << "Please input the receiver's username: ";
        string receiver;
        cin >> receiver;
        try {
            vector<const Express*> expresses = main.courier->searchReceiver(receiver);
            for (auto temp : expresses)
                cout << *((Express*)temp) << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(11) && !ban.contains(11)) {
        cout << "Please input the time information in format %Y-%m-%d %H:%M:%S" << endl;
        cout << "Lower Bound: ";
        struct tm lowerBound;
        cin >> get_time(&lowerBound, "%Y-%m-%d %H:%M:%S");
        cout << "Upper Bound: ";     
        struct tm upperBound;
        cin >> get_time(&upperBound, "%Y-%m-%d %H:%M:%S");
        cout << endl;
        try {
            vector<const Express*> expresses = main.courier->searchPickTime(mktime(&lowerBound), mktime(&upperBound));
            for (auto temp : expresses) {
                cout << *((Express*) temp) << endl;
            }
        }   
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    else if (command == commands.at(12) && !ban.contains(12)) {
        cout << "Please input the courier number: ";
        string courierNum;
        cin >> courierNum;
        regex r("[0-9]{10}");
        while (!regex_match(courierNum, r)) {
            cout << "Format error, courier number has 10 digits" << endl;
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
    else if (command == commands.at(13) && !ban.contains(13)) {
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
            cout << "  " << commands.at(5) << ": pick up expresses" << endl;
        if (!ban.contains(6))
            cout << "  " << commands.at(6) << ": display all not picked-up expresses' message" << endl;
        if (!ban.contains(7))
            cout << "  " << commands.at(7) << ": display all not received expresses' message" << endl;
        if (!ban.contains(8))
            cout << "  " << commands.at(8) << ": display all received expresses' message" << endl;
        if (!ban.contains(9))
            cout << "  " << commands.at(9) << ": search the related expresses by sender" << endl;
        if (!ban.contains(10))
            cout << "  " << commands.at(10) << ": search the related expresses by receiver" << endl;
        if (!ban.contains(11))
            cout << "  " << commands.at(11) << ": search the related expresses by pick-up time" << endl;
        if (!ban.contains(12))
            cout << "  " << commands.at(12) << ": find the specific expresses by courier number" << endl;
        if (!ban.contains(13))
            cout << "  " << commands.at(13) << ": print this help" << endl;
    }
    else
        cout << "Unknown command" << endl;
    return false;
}
