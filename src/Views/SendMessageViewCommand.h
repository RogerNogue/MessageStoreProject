#pragma once

#include <string>
#include <memory>
#include "../Controllers/SendMessage.h"
#include "IMessageCommand.h"

namespace Views {

class SendMessageViewCommand : public IMessageCommand {
public:
    SendMessageViewCommand(Controllers::SendMessage sendMessage);
    void Run() const override;

private:

    Controllers::SendMessage sendMessage;
};

} // namespace Views
