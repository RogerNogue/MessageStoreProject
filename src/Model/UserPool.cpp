#include "UserPool.h"

namespace Model {

void UserPool::Add(const User& user) {
    users.insert(user.ID);
}

bool UserPool::Exists(const User& user) const {
    return users.contains(user);
}

} // namespace Model
