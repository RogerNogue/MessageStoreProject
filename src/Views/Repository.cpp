#include "Repository.h"
#include <utility>

namespace Views {

void Repository::SaveUserPool(Models::UserPool pool)
{
    userPool = std::move(pool);
}
void Repository::SaveMessagePool(Models::MessagePool pool)
{
    messagePool = std::move(pool);
}
Models::UserPool Repository::GetUserPool() const
{
    return userPool;
}
Models::MessagePool Repository::GetMessagePool() const
{
    return messagePool;
}

}// namespace Views