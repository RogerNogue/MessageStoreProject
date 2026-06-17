#include "CreateUserView.h"
#include <iostream>

using namespace std;

namespace Views {
	CreateUserView::CreateUserView(Controllers::CreateUser createUser)
		:createUser(std::move(createUser))
	{
	}

	void CreateUserView::Run() const
	{
		cout << "Please enter name: ";
		string str;
		getline(cin, str);
		cout << endl;
		createUser.Run(str);
	}
}// namespace Views