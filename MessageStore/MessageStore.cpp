
#include "MessageStore.h"

#include <iostream>

bool MessageStore::ProcessInput(Views::ConsoleView view, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages) {
	bool ret = false;
	// clear screen
	for (int i = 0; i < 80; ++i) cout << endl;
	// show options
	cout << "Please select an option:" << endl;
	cout << "1. Create User" << endl;
	cout << "2. Send Message" << endl;
	cout << "3. Receive All Messages For User" << endl;
	cout << "4. Quit" << endl;
	std::string in;
	std::getline(std::cin, in);
	cout << endl;
	if (in == "1")
	{
		view.Run();
	} else if (in == "2"){
		sendMessage.Run();
	} else if (in == "3") {
		receiveMessages.Run();
	} else if (in == "4") {
		cout << "Quitting!" << endl;
		ret=true;
	} else
	{
		cout << "Invalid Option Selected" << endl;
	}
	cout << endl <<"Enter any key and press return to continue.....";
	std::string str;
	std::getline(std::cin, str);
	return ret;
}

void MessageStore::terminate()
{
	for (unsigned int i = 0; i < messages.size(); ++i)
		delete messages[i];
}

bool MessageStore::Exists(std::string u)
{
	for (unsigned int i = 0; i < users.size(); ++i)
		if (users[i] == u)
			return true;
	return false;
}
