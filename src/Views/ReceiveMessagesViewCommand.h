#pragma once

#include <string>
#include <memory>
#include "../Controllers/ReceiveAllMessages.h"
#include "IMessageCommand.h"

namespace Views {

class ReceiveMessagesViewCommand : public IMessageCommand 
{
public:
    ReceiveMessagesViewCommand() = delete;
    ReceiveMessagesViewCommand(Controllers::ReceiveAllMessages receiveMessages);
    void Run() override;

private:
    void PrintUserDoesNotExistError() const;
    void PrintMessageSectionFooter() const;
    void PrintMessageSectionHeader() const;
    void PrintMessageInfo(int num, const Models::Message& message) const;
    std::string RequestReceiver() const;

    Controllers::ReceiveAllMessages receiveMessages;
};

} // namespace Views
