
#include "ReceiveAllMessages.h"
#include "../Models/UserPool.h"
#include "../Models/MessagePool.h"
#include "../Models/User.h"
#include "../Models/Message.h"
#include <iostream>

namespace Controllers {
ReceiveAllMessages::ReceiveAllMessages(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

void ReceiveAllMessages::Run() const
{
	Models::UserPool userPool = repository->GetUserPool();
	Models::MessagePool messagePool = repository->GetMessagePool();

	std::cout << "Enter name of user to receive all messages for: " << std::endl;
	std::string user;
	std::getline(std::cin, user);
	std::cout << std::endl;
	Models::User receiver(user);
	if (userPool.Exists(receiver) == true)
	{
		std::cout << std::endl << "===== BEGIN MESSAGES =====" << std::endl;
		std::deque<Models::Message> usersMessages = messagePool.ReadMessages(receiver);
		int num = 0;
		while (!usersMessages.empty()) {
			Models::Message message = usersMessages.front();

			std::cout << "Message " << ++num << std::endl;
			std::cout << "From: " << message.GetOrigin().ID << std::endl;
			std::cout << "Content: " << message.GetContent() << std::endl << std::endl;

			usersMessages.pop_front();
		}

		std::cout << std::endl << "===== END MESSAGES =====" << std::endl;
	}
	else
		std::cout << "ERROR: User doesn't exist!" << std::endl;

	repository->SaveMessagePool(messagePool);
}

} // namespace Controllers