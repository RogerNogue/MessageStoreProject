#include "MessagePool.h"

namespace Models {

MessagePool::MessagePool()
{
}

void MessagePool::StoreMessage(Message message)
{
	messages[message.GetDestination().ID].emplace_back(std::move(message));
}

} // namespace Models