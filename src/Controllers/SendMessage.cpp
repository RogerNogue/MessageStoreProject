
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

	void SendMessage::Run() const
	{
		Models::UserPool userPool = repository->GetUserPool();
		Models::MessagePool messagePool = repository->GetMessagePool();

		std::cout << "From: ";
		std::string from;
		std::getline(std::cin, from);
		std::cout << std::endl;
		Models::User sender(from);
		if (userPool.Exists(sender) == false)
			std::cout << "ERROR: User doesn't exist!" << std::endl;
		else {
			std::cout << "To: ";
			std::string to;
			std::getline(std::cin, to);
			std::cout << std::endl;
			Models::User receiver(to);
			if (userPool.Exists(receiver) == false)
				std::cout << "ERROR: User doesn't exist!" << std::endl;
			else {
				std::cout << "Message: ";
				std::string msg;
				std::getline(std::cin, msg);
				std::cout << std::endl;
				std::cout << "Message Sent!" << std::endl;
				Models::Message message(sender, receiver, msg);
				messagePool.StoreMessage(message);
			}
		}

		repository->SaveMessagePool(messagePool);
	}

} // namespace Controllers