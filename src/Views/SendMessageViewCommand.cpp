#include "SendMessageViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {
SendMessageViewCommand::SendMessageViewCommand(Controllers::SendMessage sendMessage)
	:sendMessage(std::move(sendMessage))
{
}

void SendMessageViewCommand::Run() const
{
	std::string sender = RequestSender();
	//TODO: consider creating a result pattern to only do 1 call to the use case.
	if (sendMessage.DoesUserExist(sender) == false)
		PrintErrorUserDoesNotExist();
	else {
		std::string receiver = RequestReceiver();
		if (sendMessage.DoesUserExist(receiver) == false)
			PrintErrorUserDoesNotExist();
		else {
			std::string content = RequestMessageContent();
			sendMessage.Run(sender, receiver, content);
			PrintMessageSent();
		}
	}
}
void SendMessageViewCommand::PrintMessageSent() const
{
	std::cout << "Message Sent!" << std::endl;
}
void SendMessageViewCommand::PrintErrorUserDoesNotExist() const
{
	std::cout << "ERROR: User doesn't exist!" << std::endl;
}
std::string SendMessageViewCommand::RequestMessageContent() const
{
	std::cout << "Message: ";
	std::string content;
	std::getline(std::cin, content);
	std::cout << std::endl;
	return content;
}
std::string SendMessageViewCommand::RequestReceiver() const
{
	std::cout << "To: ";
	std::string receiver;
	std::getline(std::cin, receiver);
	std::cout << std::endl;
	return receiver;
}
std::string SendMessageViewCommand::RequestSender() const
{
	std::cout << "From: ";
	std::string sender;
	std::getline(std::cin, sender);
	std::cout << std::endl;
	return sender;
}
}// namespace Views