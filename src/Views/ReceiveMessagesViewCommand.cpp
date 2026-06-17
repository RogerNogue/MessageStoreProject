#include "ReceiveMessagesViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {
ReceiveMessagesViewCommand::ReceiveMessagesViewCommand(Controllers::ReceiveAllMessages receiveMessages)
:receiveMessages(std::move(receiveMessages))
{
}

void ReceiveMessagesViewCommand::Run()
{
	const string receiver = RequestReceiver();
	if (receiveMessages.DoesUserExist(receiver) == true)
	{
		PrintMessageSectionHeader();
		deque<Models::Message> usersMessages = receiveMessages.Run(receiver);
		int messageNumber = 0;
		while (!usersMessages.empty()) 
		{
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
	cout << "ERROR: User doesn't exist!" << endl;
}
void ReceiveMessagesViewCommand::PrintMessageSectionFooter() const
{
	cout << endl << "===== END MESSAGES =====" << endl;
}
void ReceiveMessagesViewCommand::PrintMessageSectionHeader() const
{
	cout << endl << "===== BEGIN MESSAGES =====" << endl;
}
void ReceiveMessagesViewCommand::PrintMessageInfo(int messageNumber, Models::Message& message) const
{
	cout << "Message " << messageNumber << endl;
	cout << "From: " << message.GetSender().ID << endl;
	cout << "Content: " << message.GetContent() << endl << endl;
}
string ReceiveMessagesViewCommand::RequestReceiver() const
{
	cout << "Enter name of user to receive all messages for: " << endl;
	string receiver;
	getline(cin, receiver);
	cout << endl;
	return receiver;
}
}// namespace Views