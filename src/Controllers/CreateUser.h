#pragma once

#include <string>
#include <memory>
#include "IRepository.h"

namespace Controllers {

class CreateUser 
{
public:
    CreateUser() = delete;
    CreateUser(std::shared_ptr<IRepository> repository);
    bool DoesUserExist(std::string id) const;
    void Run(std::string id) const;

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
