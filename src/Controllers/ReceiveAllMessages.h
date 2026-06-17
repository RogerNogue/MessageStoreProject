#pragma once

#include <string>
#include <memory>
#include "IRepository.h"

namespace Controllers {

class ReceiveAllMessages 
{
public:
    ReceiveAllMessages(std::shared_ptr<IRepository> repository);
    bool DoesUserExist(std::string id) const;
    std::deque<Models::Message> Run(std::string receiverId) const;

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
