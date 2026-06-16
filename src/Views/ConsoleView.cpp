#include "ConsoleView.h"
#include <iostream>

using namespace std;

namespace Views {

ConsoleView::ConsoleView(Controllers::CreateUser createUser)
	: createUser(std::move(createUser))
{
}

void ConsoleView::Run() const
{
	cout << "Please enter name: ";
	string str;
	getline(cin, str);
	cout << endl;
	createUser.Run(str);
}

} // namespace Views

