#pragma once

#include "User.h"
#include <unordered_set>
#include <string>

namespace Model {

class UserPool {
public:
    void Add(const User& user);
    bool Exists(const User& user) const;

private:
    std::unordered_set<std::string> users;
};

} // namespace Model
