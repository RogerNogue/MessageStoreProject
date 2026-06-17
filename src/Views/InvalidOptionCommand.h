#pragma once

#include "IMessageCommand.h"
#include <iostream>

namespace Views {

class InvalidOptionCommand : public IMessageCommand 
{
public:
    void Run() override
    {
        std::cout << "Invalid Option Selected" << std::endl;
    }

private:
};

} // namespace Views
