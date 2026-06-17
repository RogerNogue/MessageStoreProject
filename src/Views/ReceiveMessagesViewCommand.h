#pragma once

#include <string>
#include <memory>
#include "../Controllers/ReceiveAllMessages.h"
#include "IMessageCommand.h"

namespace Views {

class ReceiveMessagesViewCommand : public IMessageCommand {
public:
    ReceiveMessagesViewCommand(Controllers::ReceiveAllMessages receiveMessages);
    void Run() const override;

private:
    std::string RequestReceiver() const;

    Controllers::ReceiveAllMessages receiveMessages;
};

} // namespace Views
