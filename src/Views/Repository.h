#pragma once
#include "../Controllers/IRepository.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"

namespace Views {

class Repository : public Controllers::IRepository{
public:
    ~Repository() = default;
    virtual void SaveUserPool(const Models::UserPool pool) override
    {
        userPool = pool;
    }
    virtual void SaveMessagePool(const Models::MessagePool pool) override
    {
        messagePool = pool;
    }
    virtual Models::UserPool GetUserPool() const override
    {
        return userPool;
    }
    virtual Models::MessagePool GetMessagePool() const override
    {
        return messagePool;
    }

private:
    Models::UserPool userPool;
    Models::MessagePool messagePool;
};

} // namespace Views