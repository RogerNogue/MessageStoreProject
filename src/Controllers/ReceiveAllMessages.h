#pragma once

#include "../Models/Message.h"
#include <string>
#include <memory>
#include <deque>

namespace Controllers {

class IRepository;

class ReceiveAllMessages 
{
public:
    ReceiveAllMessages() = delete;
    ReceiveAllMessages(std::shared_ptr<IRepository> repository);
    bool DoesUserExist(const std::string& id) const;
    std::deque<Models::Message> Run(std::string receiverId);

private:
    std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
