#pragma once

#include "User.h"
#include <string>

namespace Models {

class Message {
public:
    Message(User from, User to, std::string content);
    User GetDestination() const;
    User GetOrigin() const;
    std::string GetContent() const;
private:
    User from;
    User to;
    std::string content;
};

} // namespace Models
