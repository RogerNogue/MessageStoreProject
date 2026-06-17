#pragma once

#include <string>
#include <memory>
#include "../Controllers/ReceiveAllMessages.h"
#include "IMessageCommand.h"

namespace Views {

class ReceiveMessagesView : public IMessageCommand {
public:
    ReceiveMessagesView(Controllers::ReceiveAllMessages receiveMessages);
    void Run() const override;

private:

    Controllers::ReceiveAllMessages receiveMessages;
};

} // namespace Views
