#pragma once

#include <string>
#include <memory>
#include "../Controllers/SendMessage.h"
#include "IMessageCommand.h"

namespace Views {

class SendMessageViewCommand : public IMessageCommand 
{
public:
    SendMessageViewCommand() = delete;
    SendMessageViewCommand(Controllers::SendMessage sendMessage);
    void Run() override;

private:
    void PrintMessageSent() const;
    void PrintErrorUserDoesNotExist() const;
    std::string RequestMessageContent() const;
    std::string RequestReceiver() const;
    std::string RequestSender() const;

    Controllers::SendMessage sendMessage;
};

} // namespace Views
