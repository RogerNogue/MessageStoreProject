#include "UserPool.h"

namespace Models {

void UserPool::Add(const User& user) {
    users.insert(user.ID);
}

bool UserPool::Exists(const User& user) const {
    return users.contains(user);
}

} // namespace Models
