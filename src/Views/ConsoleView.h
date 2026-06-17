#pragma once

#include <memory>
#include <vector>
#include "IMessageCommand.h"
#include "../Controllers/CreateUser.h"
#include "../Controllers/SendMessage.h"
#include "../Controllers/ReceiveAllMessages.h"

namespace Views {

class ConsoleView {
public:
    ConsoleView(Controllers::CreateUser createUser, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages);
    void Run() const;

    void RequestOneExtraInput() const;

private:
    std::string ReadOption() const;
    void PrintFunctions() const;
    void ClearScreen() const;

    std::vector<std::unique_ptr<IMessageCommand>> commands;
    std::shared_ptr<bool> quit;
};

} // namespace Views
