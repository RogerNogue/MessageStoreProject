#pragma once
#include "../Controllers/IRepository.h"
#include "../Models/UserPool.h"

namespace Views {

class Repository : public Controllers::IRepository{
public:
    ~Repository() = default;
    virtual void SaveUserPool(Models::UserPool pool)
    {
        userPool = pool;
    }
    virtual Models::UserPool GetUserPool() const
    {
        return userPool;
    }

private:
    Models::UserPool userPool = Models::UserPool();
};

} // namespace Views