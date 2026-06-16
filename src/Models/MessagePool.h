#pragma once

#include "User.h"
#include "Message.h"
#include <deque>
#include <unordered_map>

namespace Models {

class MessagePool {
public:
    MessagePool();
private:
    std::unordered_map<User, std::deque<Message>> messages;
};

} // namespace Models
