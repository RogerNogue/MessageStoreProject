#include "ReceiveMessagesViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {
ReceiveMessagesViewCommand::ReceiveMessagesViewCommand(Controllers::ReceiveAllMessages receiveMessages)
:receiveMessages(std::move(receiveMessages))
{
}

void ReceiveMessagesViewCommand::Run() const
{
	std::string receiver = RequestReceiver();
	if (receiveMessages.DoesUserExist(receiver) == true)
	{
		PrintMessageSectionHeader();
		std::deque<Models::Message> usersMessages = receiveMessages.Run(receiver);
		int messageNumber = 0;
		while (!usersMessages.empty()) {
			PrintMessageInfo(messageNumber, usersMessages.front());
			usersMessages.pop_front();
			++messageNumber;
		}
		PrintMessageSectionFooter();
	}
	else
		PrintUserDoesNotExistError();
}
void ReceiveMessagesViewCommand::PrintUserDoesNotExistError() const
{
	std::cout << "ERROR: User doesn't exist!" << std::endl;
}
void ReceiveMessagesViewCommand::PrintMessageSectionFooter() const
{
	std::cout << std::endl << "===== END MESSAGES =====" << std::endl;
}
void ReceiveMessagesViewCommand::PrintMessageSectionHeader() const
{
	std::cout << std::endl << "===== BEGIN MESSAGES =====" << std::endl;
}
void ReceiveMessagesViewCommand::PrintMessageInfo(int messageNumber, Models::Message& message) const
{
	std::cout << "Message " << messageNumber << std::endl;
	std::cout << "From: " << message.GetSender().ID << std::endl;
	std::cout << "Content: " << message.GetContent() << std::endl << std::endl;
}
std::string ReceiveMessagesViewCommand::RequestReceiver() const
{
	std::cout << "Enter name of user to receive all messages for: " << std::endl;
	std::string receiver;
	std::getline(std::cin, receiver);
	std::cout << std::endl;
	return receiver;
}
}// namespace Views