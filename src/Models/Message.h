#pragma once

#include "User.h"
#include <string>

namespace Models {

class Message {
public:
    Message(User sender, User receiver, std::string content);
    User GetDestination() const;
    User GetOrigin() const;
    std::string GetContent() const;
private:
    User sender;
    User receiver;
    std::string content;
};

} // namespace Models
