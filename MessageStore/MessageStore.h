#pragma once
#include <string>
#include <vector>
#include "../src/Views/ConsoleView.h"


using namespace std;

class MessageStore
{
public:
	
	bool ProcessInput(Views::ConsoleView view); // returns true when finished
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
