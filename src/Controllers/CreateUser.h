#pragma once

#include <string>
#include <memory>

namespace Controllers {

class IRepository;

class CreateUser 
{
public:
    CreateUser() = delete;
    CreateUser(std::shared_ptr<IRepository> repository);
    bool DoesUserExist(std::string id) const;
    void Run(std::string id);

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
