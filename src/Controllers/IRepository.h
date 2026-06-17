#pragma once
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"

namespace Controllers {

class IRepository 
{
    public:
        virtual ~IRepository() {}
        virtual void SaveUserPool(Models::UserPool pool) = 0;
        virtual void SaveMessagePool(Models::MessagePool pool) = 0;
        virtual Models::UserPool GetUserPool() const = 0;
        virtual Models::MessagePool GetMessagePool() const = 0;
};

} // namespace Controllers