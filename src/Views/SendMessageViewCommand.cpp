#include "SendMessageViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {

SendMessageViewCommand::SendMessageViewCommand(Controllers::SendMessage sendMessage)
	:sendMessage(std::move(sendMessage))
{
}

void SendMessageViewCommand::Run()
{
	const string sender = RequestSender();
	const string receiver = RequestReceiver();
	const string content = RequestMessageContent();

	switch (sendMessage.Run(sender, receiver, content))
	{
		case Controllers::UseCaseResult::Success:
			PrintMessageSent();
			break;
		case Controllers::UseCaseResult::UserNotFound:
			PrintErrorUserDoesNotExist();
			break;
		default:
			break;
	}
}
void SendMessageViewCommand::PrintMessageSent() const
{
	cout << "Message Sent!" << endl;
}

void SendMessageViewCommand::PrintErrorUserDoesNotExist() const
{
	cout << "ERROR: User doesn't exist!" << endl;
}

string SendMessageViewCommand::RequestMessageContent() const
{
	cout << "Message: ";
	string content;
	getline(cin, content);
	cout << endl;
	return content;
}

string SendMessageViewCommand::RequestReceiver() const
{
	cout << "To: ";
	string receiver;
	getline(cin, receiver);
	cout << endl;
	return receiver;
}

string SendMessageViewCommand::RequestSender() const
{
	cout << "From: ";
	string sender;
	getline(cin, sender);
	cout << endl;
	return sender;
}

}// namespace Views