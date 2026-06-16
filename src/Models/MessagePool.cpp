#include "MessagePool.h"

namespace Models {

MessagePool::MessagePool()
{
}

void MessagePool::StoreMessage(Message message)
{
	if (messages.contains(message.GetDestination()))
	{
		messages.at(message.GetDestination()).emplace_back(message);
	}
	else
	{
		messages.emplace(message.GetDestination(), message);
	}
}

} // namespace Models