#pragma once
#include "../Models/UserPool.h"

namespace Controllers {

class IRepository {
    public:
        virtual ~IRepository() {}
        virtual void SaveUserPool(Models::UserPool pool) = 0;
        virtual Models::UserPool GetUserPool() const = 0;
    };

} // namespace Controllers