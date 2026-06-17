
#include "SendMessage.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "../Models/Message.h"
#include "IRepository.h"
#include <iostream>

namespace Controllers {

SendMessage::SendMessage(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

bool SendMessage::DoesUserExist(const std::string& id) const
{
	const Models::UserPool userPool = repository->GetUserPool();

	return userPool.Exists(Models::User(id));
}

void SendMessage::Run(std::string sender, std::string receiver, std::string messagetext)
{
	Models::MessagePool messagePool = repository->GetMessagePool();

	const Models::User senderUser(std::move(sender));
	const Models::User receiverUser(std::move(receiver));
	Models::Message message(senderUser, receiverUser, std::move(messagetext));
	messagePool.StoreMessage(message);

	repository->SaveMessagePool(messagePool);
}

} // namespace Controllers