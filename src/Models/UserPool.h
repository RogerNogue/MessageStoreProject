#pragma once

#include "User.h"
#include <unordered_set>
#include <string>

namespace Models {

class UserPool {
public:
    void Create(const std::string id);
    bool Exists(const std::string id) const;

private:
    std::unordered_set<std::string> users;
};

} // namespace Models
