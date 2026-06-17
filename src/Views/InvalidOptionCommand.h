#pragma once

#include "IMessageCommand.h"
#include <iostream>

using namespace std;

namespace Views {

class InvalidOptionCommand : public IMessageCommand 
{
public:
    void Run() const override
    {
        cout << "Invalid Option Selected" << endl;
    }

private:
};

} // namespace Views
