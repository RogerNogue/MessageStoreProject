
#include "SendMessage.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "../Models/Message.h"
#include <iostream>

namespace Controllers {

SendMessage::SendMessage(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

bool SendMessage::DoesUserExist(std::string id) const
{
	const Models::UserPool userPool = repository->GetUserPool();

	return userPool.Exists(Models::User(id));
}

void SendMessage::Run(std::string sender, std::string receiver, std::string messagetext)
{
	const Models::UserPool userPool = repository->GetUserPool();
	Models::MessagePool messagePool = repository->GetMessagePool();

	const Models::User senderUser(sender);
	const Models::User receiverUser(receiver);
	Models::Message message(senderUser, receiverUser, messagetext);
	messagePool.StoreMessage(message);

	repository->SaveMessagePool(messagePool);
}

} // namespace Controllers