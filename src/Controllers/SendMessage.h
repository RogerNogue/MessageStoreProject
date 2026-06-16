#pragma once

#include <string>
#include <memory>
#include "IRepository.h"

namespace Controllers {

class SendMessage {
    public:
        SendMessage(std::shared_ptr<IRepository> repository);
        void Run() const;

    private:
        std::shared_ptr<IRepository> repository;
    };

} // namespace Controllers
