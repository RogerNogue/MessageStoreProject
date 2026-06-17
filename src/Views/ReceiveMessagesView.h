#pragma once

#include <string>
#include <memory>
#include "../Controllers/ReceiveAllMessages.h"

namespace Views {

class ReceiveMessagesView {
public:
    ReceiveMessagesView(Controllers::ReceiveAllMessages receiveMessages);
    void Run() const;

private:

    Controllers::ReceiveAllMessages receiveMessages;
};

} // namespace Views
