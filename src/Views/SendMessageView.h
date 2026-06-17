#pragma once

#include <string>
#include <memory>
#include "../Controllers/SendMessage.h"

namespace Views {

class SendMessageView {
public:
    SendMessageView(Controllers::SendMessage sendMessage);
    void Run() const;

private:

    Controllers::SendMessage sendMessage;
};

} // namespace Views
