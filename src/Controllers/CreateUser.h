#pragma once

#include <string>
#include <memory>
#include "IRepository.h"

namespace Controllers {

class CreateUser {
public:
    CreateUser(std::shared_ptr<IRepository> repository);
    void Run(std::string id) const;

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
