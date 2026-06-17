#pragma once

#include "IMessageCommand.h"
#include <iostream>
#include <memory>

using namespace std;

namespace Views {

class QuitCommand : public IMessageCommand {
public:
    QuitCommand(std::shared_ptr<bool> quit)
        : quit(std::move(quit))
    { }
    void Run() const override
    {
        cout << "Quitting!" << endl;
        *quit = true;
    }

private:
    std::shared_ptr<bool> quit;
};

} // namespace Views
