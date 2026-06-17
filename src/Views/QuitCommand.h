#pragma once

#include "IMessageCommand.h"
#include <iostream>
#include <memory>

namespace Views {

class QuitCommand : public IMessageCommand 
{
public:
    QuitCommand() = delete;
    QuitCommand(std::shared_ptr<bool> quit)
        : quit(std::move(quit))
    { }
    void Run() const override 
    {
        std::cout << "Quitting!" << std::endl;
        *quit = true;
    }

private:
    std::shared_ptr<bool> quit;
};

} // namespace Views
