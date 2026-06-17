#pragma once
#include "../Controllers/IRepository.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"

namespace Views {

class Repository : public Controllers::IRepository
{
public:
    ~Repository() = default;
    virtual void SaveUserPool(Models::UserPool pool) override;
    virtual void SaveMessagePool(Models::MessagePool pool) override;
    virtual Models::UserPool GetUserPool() const override;
    virtual Models::MessagePool GetMessagePool() const override;

private:
    Models::UserPool userPool;
    Models::MessagePool messagePool;
};

} // namespace Views