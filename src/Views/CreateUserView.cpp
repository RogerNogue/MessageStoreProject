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
		//TODO: consider creating a result pattern to only do 1 call to the use case.
		if (createUser.DoesUserExist(str))
		{
			cout << "ERROR: User already exists!" << endl;
		}
		else
		{
			createUser.Run(str);
			cout << "User " << str << " added!" << endl;
		}
	}
}// namespace Views