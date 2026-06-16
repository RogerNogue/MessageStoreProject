#pragma once

#include "User.h"
#include "Message.h"
#include <deque>
#include <unordered_map>
#include <string>

namespace Models {

class MessagePool {
public:
    MessagePool();
    void StoreMessage(Message message);
    std::deque<Message> ReadMessages(const User& receiver);
private:
    //TODO: make User hashable (same as with the User pool)
    std::unordered_map<std::string, std::deque<Message>> messages;
};

} // namespace Models
