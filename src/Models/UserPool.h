#pragma once

#include "User.h"
#include <unordered_set>
#include <string>

namespace Models {

class UserPool {
public:
    void Create(User user);
    bool Exists(const User& user) const;

private:
    std::unordered_set<std::string> users;
};

} // namespace Models
