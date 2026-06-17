#include "Repository.h"

namespace Views {
	
void Repository::SaveUserPool(const Models::UserPool pool)
{
    userPool = pool;
}
void Repository::SaveMessagePool(const Models::MessagePool pool)
{
    messagePool = pool;
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