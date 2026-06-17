#include "SendMessage.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "../Models/Message.h"
#include "IRepository.h"

namespace Controllers {

SendMessage::SendMessage(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

bool SendMessage::DoesUserExist(const std::string& user) const
{
	const Models::UserPool userPool = repository->GetUserPool();
	return userPool.Exists(Models::User(user));
}

UseCaseResult SendMessage::Run(std::string sender, std::string receiver, std::string messagetext)
{
	const Models::UserPool userPool = repository->GetUserPool();
	Models::User senderUser(std::move(sender));
	Models::User receiverUser(std::move(receiver));

	if (!userPool.Exists(senderUser) || !userPool.Exists(receiverUser))
		return UseCaseResult::UserNotFound;

	Models::MessagePool messagePool = repository->GetMessagePool();
	Models::Message message(std::move(senderUser), std::move(receiverUser), std::move(messagetext));
	messagePool.StoreMessage(std::move(message));
	repository->SaveMessagePool(std::move(messagePool));
	return UseCaseResult::Success;
}

} // namespace Controllers
