#include "ReceiveMessagesViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {
ReceiveMessagesViewCommand::ReceiveMessagesViewCommand(Controllers::ReceiveAllMessages receiveMessages)
:receiveMessages(std::move(receiveMessages))
{
}

void ReceiveMessagesViewCommand::PrintOperation(int operationIndex)
{
	cout << operationIndex << ". Receive All Messages For User" << endl;
}

void ReceiveMessagesViewCommand::Run()
{
	const string receiver = RequestReceiver();
	auto messages = receiveMessages.Run(receiver);

	if (!messages.has_value())
	{
		PrintUserDoesNotExistError();
		return;
	}

	PrintMessageSectionHeader();
	int messageNumber = 0;
	while (!messages->empty())
	{
		PrintMessageInfo(messageNumber, messages->front());
		messages->pop_front();
		++messageNumber;
	}
	PrintMessageSectionFooter();
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
void ReceiveMessagesViewCommand::PrintMessageInfo(int messageNumber, const Models::Message& message) const
{
	cout << "Message " << messageNumber << endl;
	cout << "From: " << message.GetSender().id << endl;
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