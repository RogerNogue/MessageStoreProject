
#include "ReceiveAllMessages.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "../Models/Message.h"
#include "IRepository.h"
#include <iostream>

namespace Controllers {
ReceiveAllMessages::ReceiveAllMessages(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

bool ReceiveAllMessages::DoesUserExist(const std::string& id) const
{
	const Models::UserPool userPool = repository->GetUserPool();

	return userPool.Exists(Models::User(id));
}

std::deque<Models::Message> ReceiveAllMessages::Run(std::string receiverId)
{
	const Models::UserPool userPool = repository->GetUserPool();
	Models::MessagePool messagePool = repository->GetMessagePool();

	Models::User receiver(receiverId);
	std::deque<Models::Message> messages = messagePool.ReadMessages(receiver);

	repository->SaveMessagePool(messagePool);

	return messages;
}

} // namespace Controllers