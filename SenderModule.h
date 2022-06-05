#pragma once
#include "ConsoleModule.h"
class SenderModule :
    public ConsoleModule
{
public:
    SenderModule()
        :ConsoleModule("sender") {
        commands = { "return", "dsplynsexp", "dsplysexp", "srchreceiver", 
            "srchsendtm", "help" };
    }

    virtual bool execute(Main& main, const string& command, const set<int>& ban);
};

