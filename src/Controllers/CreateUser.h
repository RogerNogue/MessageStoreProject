#pragma once

#include <string>
#include <memory>
#include "UseCaseResult.h"

namespace Controllers {

class IRepository;

class CreateUser
{
public:
    CreateUser() = delete;
    CreateUser(std::shared_ptr<IRepository> repository);
    UseCaseResult Run(std::string id);

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
