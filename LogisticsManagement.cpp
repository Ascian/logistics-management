#include <iostream>
#include<string>

#include"MainModule.h"

using namespace std;

#define SAVE_PATH "./data"

Main mainMember;
MainModule mainModule;

int main()
{
    try {
        mainMember.logistics->load(SAVE_PATH);
        cout << "Load existed logistics database" << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
        cout << "Creat new logistics database" << endl;
        cout << "Please input the manager information" << endl;
        cout << "Username: ";
        string username;
        cin >> username;
        while (username.size() > STRING_MAX_SIZE) {
            cout << "Username length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Username: ";
            cin >> username;
        }
        mainMember.logistics->manager.setUsername(username);
        cout << "Password: ";
        string password;
        cin >> password;
        while (password.size() > STRING_MAX_SIZE) {
            cout << "Password length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Password: ";
            cin >> password;
        }
        mainMember.logistics->manager.setPassword(password);
        cout << "Name: ";
        string name;
        cin >> name;
        while (name.size() > STRING_MAX_SIZE) {
            cout << "Name length should be less than " << STRING_MAX_SIZE << endl;
            cout << "Name: ";
            cin >> name;
        }
        mainMember.logistics->manager.setName(name);
    }
    cout << endl;

    bool ret = false;
    while (!ret) {
        time_t now = time(0);
        cout << "[" << put_time(localtime(&now), "%Y-%b-%d %H:%M:%S") << "] ";
        vector<string> commands = mainModule.getModuleCommand({});
        for (int i = 0; i < commands.size() - 1; i++) {
            cout << commands.at(i) << "/";
        }
        cout << commands.at(commands.size() - 1) << endl;

        cout << mainModule.getModuleName() << "> ";
        string command;
        cin >> command;
        ret = mainModule.parse(mainMember, command, {});
        cout << endl;
    }

    mainMember.logistics->save(SAVE_PATH);
    return 0;
}
