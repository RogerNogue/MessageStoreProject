#pragma once

#include <string>
#include <memory>
#include "CreateUserView.h"
#include "SendMessageView.h"
#include "../Controllers/CreateUser.h"
#include "../Controllers/SendMessage.h"
#include "../Controllers/ReceiveAllMessages.h"

namespace Views {

    class ConsoleView {
    public:
        ConsoleView(Controllers::CreateUser createUser, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages);
        void Run() const;

    private:
        std::string ReadOption() const;
        void PrintFunctions() const;
        void ClearScreen() const;

        CreateUserView createUserView;
        SendMessageView sendMessageView;
        Controllers::ReceiveAllMessages receiveMessages;
    };

} // namespace Views
