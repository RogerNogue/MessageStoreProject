#pragma once

#include <string>
#include <memory>
#include "../Controllers/CreateUser.h"

namespace Views {

class CreateUserView {
public:
    CreateUserView(Controllers::CreateUser createUser);
    void Run() const;

private:

    Controllers::CreateUser createUser;
};

} // namespace Views
