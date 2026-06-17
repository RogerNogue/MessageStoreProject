#include "ReceiveAllMessages.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "IRepository.h"

namespace Controllers {

ReceiveAllMessages::ReceiveAllMessages(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

std::optional<std::deque<Models::Message>> ReceiveAllMessages::Run(std::string receiverId)
{
	const Models::UserPool userPool = repository->GetUserPool();
	const Models::User receiver(std::move(receiverId));

	if (!userPool.Exists(receiver))
		return std::nullopt;

	Models::MessagePool messagePool = repository->GetMessagePool();
	std::deque<Models::Message> messages = messagePool.ReadMessages(receiver);
	repository->SaveMessagePool(messagePool);
	return messages;
}

} // namespace Controllers
