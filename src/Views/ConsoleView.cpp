#include "ConsoleView.h"
#include "CreateUserViewCommand.h"
#include "SendMessageViewCommand.h"
#include "ReceiveMessagesViewCommand.h"
#include "QuitCommand.h"
#include "InvalidOptionCommand.h"
#include <iostream>

using namespace std;

namespace Views {

ConsoleView::ConsoleView(Controllers::CreateUser createUser, Controllers::SendMessage sendMessage, Controllers::ReceiveAllMessages receiveMessages)
{
	quit = std::make_shared<bool>(false);
	commands.reserve(5);
	commands.emplace_back(std::make_unique<CreateUserViewCommand>(std::move(createUser)));
	commands.emplace_back(std::make_unique<SendMessageViewCommand>(std::move(sendMessage)));
	commands.emplace_back(std::make_unique<ReceiveMessagesViewCommand>(std::move(receiveMessages)));
	commands.emplace_back(std::make_unique<QuitCommand>(quit));
	commands.emplace_back(std::make_unique<InvalidOptionCommand>());
}

void ConsoleView::Run() const
{
	while (true)
	{
		ClearScreen();
		PrintFunctions();
		uint8_t option = std::stoi(ReadOption());

		commands[option - 1]->Run();

		if (*quit)
			return;

		RequestOneExtraInput();
	}
}

void ConsoleView::RequestOneExtraInput() const
{
	cout << endl << "Enter any key and press return to continue.....";
	std::string extraInput;
	std::getline(std::cin, extraInput);
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

