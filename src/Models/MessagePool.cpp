#include "MessagePool.h"

namespace Models {

void MessagePool::StoreMessage(Message message)
{
	messages[message.GetReceiver().id].emplace_back(std::move(message));
}

std::deque<Message> MessagePool::ReadMessages(const User& receiver)
{
	std::deque<Message> usersMessages = std::move(messages[receiver.id]);
	messages[receiver.id].clear();
	return usersMessages;
}

} // namespace Models