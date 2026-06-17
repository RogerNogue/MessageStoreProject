#pragma once

#include "User.h"
#include <string>

namespace Models {

class Message 
{
public:
    Message() = delete;
    Message(User sender, User receiver, std::string content);
    User GetReceiver() const;
    User GetSender() const;
    std::string GetContent() const;
private:
    User sender;
    User receiver;
    std::string content;
};

} // namespace Models
