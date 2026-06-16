#include "MessagePool.h"

namespace Models {

MessagePool::MessagePool()
{
}

void MessagePool::StoreMessage(Message message)
{
	messages[message.GetDestination().ID].emplace_back(std::move(message));
}

std::deque<Message> MessagePool::ReadMessages(User receiver)
{
	std::deque<Message> usersMessages = std::move(messages[receiver.ID]);
	messages[receiver.ID].clear();
	return usersMessages;
}

} // namespace Models