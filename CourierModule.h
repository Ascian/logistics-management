#pragma once
#include "ConsoleModule.h"
class CourierModule :
    public ConsoleModule
{
public:
    CourierModule()
        :ConsoleModule("courier") {
        commands = { "return", "check", "password", "name", "phone", "pickup",
            "dsplynpexp", "dsplynrexp", "dsplyrexp", "srchsender", "srchreceiver",
            "srchpicktm", "findexp", "help" };
    }

    virtual bool execute(Main& main, const string& command, const set<int>& ban);
};

