#pragma once

#include <string>
#include <memory>
#include "UseCaseResult.h"

namespace Controllers {

class IRepository;

class SendMessage
{
public:
    SendMessage() = delete;
    SendMessage(std::shared_ptr<IRepository> repository);
    UseCaseResult Run(std::string sender, std::string receiver, std::string messagetext);

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
