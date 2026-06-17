#pragma once

#include "IMessageCommand.h"
#include <iostream>
#include <memory>
#include <iostream>

namespace Views {

class QuitCommand : public IMessageCommand 
{
public:
    QuitCommand() = delete;
    QuitCommand(std::shared_ptr<bool> quit)
        : quit(std::move(quit))
    { }
    void PrintOperation(int operationIndex) override
    {
        std::cout << operationIndex << ". Quit" << std::endl;
    }
    void Run() override 
    {
        std::cout << "Quitting!" << std::endl;
        *quit = true;
    }

private:
    std::shared_ptr<bool> quit;
};

} // namespace Views
