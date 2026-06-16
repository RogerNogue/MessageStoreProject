#pragma once

#include <string>
#include <memory>
#include "../Controllers/CreateUser.h"

namespace Views {

    class ConsoleView {
    public:
        ConsoleView(Controllers::CreateUser createUser);
        void Run() const;

    private:
        Controllers::CreateUser createUser;
    };

} // namespace Views
