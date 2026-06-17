#pragma once

#include <string>
#include <memory>
#include "../Controllers/CreateUser.h"
#include "IMessageCommand.h"

namespace Views {

class CreateUserView : public IMessageCommand {
public:
    CreateUserView(Controllers::CreateUser createUser);
    void Run() const override;

private:

    Controllers::CreateUser createUser;
};

} // namespace Views
