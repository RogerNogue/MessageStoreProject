#include "UserPool.h"

namespace Models {

void UserPool::Create(const std::string id) {
    users.insert(user.ID);
}

bool UserPool::Exists(const std::string id) const {
    return users.contains(user);
}

} // namespace Models
