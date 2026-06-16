#pragma once

#include <string>
#include <memory>
#include "../Controllers/CreateUser.h"
#include "../Controllers/SendMessage.h"
#include "../Controllers/ReceiveAllMessages.h"

namespace Views {

    class ConsoleView {
    public:
        ConsoleView(Controllers::CreateUser createUser, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages);
        void Run() const;

        std::string ReadOption() const;

        void PrintFunctions() const;

        void ClearScreen() const;

    private:
        Controllers::CreateUser createUser;
        Controllers::SendMessage sendMessage;
        Controllers::ReceiveAllMessages receiveMessages;
    };

} // namespace Views
