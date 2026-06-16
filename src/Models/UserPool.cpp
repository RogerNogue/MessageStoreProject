#include "UserPool.h"

namespace Models {

void UserPool::Create(User user) {
    users.insert(user.ID);
}

bool UserPool::Exists(const User& user) const {
    return users.contains(user.ID);
}

} // namespace Models
