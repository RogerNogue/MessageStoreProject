#pragma once
#include <string>
#include <vector>
#include "../src/Controllers/CreateUser.h"


using namespace std;

class MessageStore
{
public:
	
	bool ProcessInput(Controllers::CreateUser createUser); // returns true when finished
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
