#include "MessagePool.h"

namespace Models {

void MessagePool::StoreMessage(Message message)
{
	messages[message.GetReceiver().ID].emplace_back(std::move(message));
}

std::deque<Message> MessagePool::ReadMessages(const User& receiver)
{
	std::deque<Message> usersMessages = std::move(messages[receiver.ID]);
	messages[receiver.ID].clear();
	return usersMessages;
}

} // namespace Models