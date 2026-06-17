#pragma once

#include <string>
#include <memory>
#include "../Controllers/CreateUser.h"
#include "IMessageCommand.h"

namespace Views {

class CreateUserViewCommand : public IMessageCommand 
{
public:
    CreateUserViewCommand() = delete;
    CreateUserViewCommand(Controllers::CreateUser createUser);
    void PrintOperation(int operationIndex) override;
    void Run() override;

private:
    std::string ReadUserId() const;

    Controllers::CreateUser createUser;
};

} // namespace Views
