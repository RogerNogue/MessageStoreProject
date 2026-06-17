#include "ReceiveMessagesView.h"
#include <iostream>

using namespace std;

namespace Views {
ReceiveMessagesView::ReceiveMessagesView(Controllers::ReceiveAllMessages receiveMessages)
:receiveMessages(std::move(receiveMessages))
{
}

void ReceiveMessagesView::Run() const
{
	std::cout << "Enter name of user to receive all messages for: " << std::endl;
	std::string receiver;
	std::getline(std::cin, receiver);
	std::cout << std::endl;
	if (receiveMessages.DoesUserExist(receiver) == true)
	{
		std::cout << std::endl << "===== BEGIN MESSAGES =====" << std::endl;
		std::deque<Models::Message> usersMessages = receiveMessages.Run(receiver);
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
}
}// namespace Views