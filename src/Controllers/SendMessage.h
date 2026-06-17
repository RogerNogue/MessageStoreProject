#pragma once

#include <string>
#include <memory>
#include "IRepository.h"

namespace Controllers {

class SendMessage {
    public:
        SendMessage(std::shared_ptr<IRepository> repository);
        bool DoesUserExist(std::string id) const;
        void Run(std::string sender, std::string receiver, std::string messagetext) const;

    private:
        std::shared_ptr<IRepository> repository;
};

} // namespace Controllers
