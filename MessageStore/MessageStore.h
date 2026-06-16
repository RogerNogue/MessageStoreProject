#pragma once
#include <string>
#include <vector>
#include "../src/Views/ConsoleView.h"
#include "../src/Controllers/SendMessage.h"
#include "../src/Controllers/ReceiveAllMessages.h"


using namespace std;

class MessageStore
{
public:
	
	bool ProcessInput(Views::ConsoleView view, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages); // returns true when finished
	void terminate();
private:

	bool Exists(std::string u);
	std::vector<std::string> users;
	struct Message {
		std::string from;
		std::string to;
		std::string msg;
	};
	std::vector<Message*> messages;
};
