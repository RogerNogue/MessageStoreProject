#include "SendMessageView.h"
#include <iostream>

using namespace std;

namespace Views {
	SendMessageView::SendMessageView(Controllers::SendMessage sendMessage)
		:sendMessage(std::move(sendMessage))
	{
	}

	void SendMessageView::Run() const
	{
		std::cout << "From: ";
		std::string sender;
		std::getline(std::cin, sender);
		std::cout << std::endl;
		//TODO: consider creating a result pattern to only do 1 call to the use case.
		if (sendMessage.DoesUserExist(sender) == false)
			std::cout << "ERROR: User doesn't exist!" << std::endl;
		else {
			std::cout << "To: ";
			std::string receiver;
			std::getline(std::cin, receiver);
			std::cout << std::endl;
			if (sendMessage.DoesUserExist(receiver) == false)
				std::cout << "ERROR: User doesn't exist!" << std::endl;
			else {
				std::cout << "Message: ";
				std::string msg;
				std::getline(std::cin, msg);
				std::cout << std::endl;
				std::cout << "Message Sent!" << std::endl;
				sendMessage.Run(sender, receiver, msg);
			}
		}
	}
}// namespace Views