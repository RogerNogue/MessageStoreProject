#include "ConsoleView.h"
#include <iostream>

using namespace std;

namespace Views {

ConsoleView::ConsoleView(Controllers::CreateUser createUser, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages)
	: createUserView(std::move(createUser)), sendMessageView(std::move(sendMessage)), receiveMessages(std::move(receiveMessages))
{
}

void ConsoleView::Run() const
{
	while (true)
	{
		ClearScreen();
		PrintFunctions();
		std::string option = ReadOption();

		if (option == "1")
		{
			createUserView.Run();
		}
		else if (option == "2") {
			sendMessageView.Run();
		}
		else if (option == "3") {
			receiveMessages.Run();
		}
		else if (option == "4") {
			cout << "Quitting!" << endl;
			return;
		}
		else
		{
			cout << "Invalid Option Selected" << endl;
		}
		cout << endl << "Enter any key and press return to continue.....";
		std::string str;
		std::getline(std::cin, str);
	}
}

std::string ConsoleView::ReadOption() const
{
	std::string option;
	std::getline(std::cin, option);
	cout << endl;
	return option;
}

void ConsoleView::PrintFunctions() const
{
	cout << "Please select an option:" << endl;
	cout << "1. Create User" << endl;
	cout << "2. Send Message" << endl;
	cout << "3. Receive All Messages For User" << endl;
	cout << "4. Quit" << endl;
}

void ConsoleView::ClearScreen() const
{
	for (int i = 0; i < 80; ++i) cout << endl;
}

} // namespace Views

