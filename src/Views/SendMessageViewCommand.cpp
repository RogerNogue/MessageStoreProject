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
	//TODO: consider creating a result pattern to only do 1 call to the use case.
	if (sendMessage.DoesUserExist(sender) == false)
		PrintErrorUserDoesNotExist();
	else {
		string receiver = RequestReceiver();
		if (sendMessage.DoesUserExist(receiver) == false)
			PrintErrorUserDoesNotExist();
		else {
			string content = RequestMessageContent();
			sendMessage.Run(sender, receiver, content);
			PrintMessageSent();
		}
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