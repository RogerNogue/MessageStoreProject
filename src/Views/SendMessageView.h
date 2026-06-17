#pragma once

#include <string>
#include <memory>
#include "../Controllers/SendMessage.h"
#include "IMessageCommand.h"

namespace Views {

class SendMessageView : public IMessageCommand {
public:
    SendMessageView(Controllers::SendMessage sendMessage);
    void Run() const override;

private:

    Controllers::SendMessage sendMessage;
};

} // namespace Views
