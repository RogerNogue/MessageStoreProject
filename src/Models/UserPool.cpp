#include "UserPool.h"

namespace Models {

void UserPool::Create(User user) {
    users.insert(std::move(user.id));
}

bool UserPool::Exists(const User& user) const {
    return users.contains(user.id);
}

} // namespace Models
