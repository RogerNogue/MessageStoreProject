#include "CreateUserViewCommand.h"
#include <iostream>

using namespace std;

namespace Views {
CreateUserViewCommand::CreateUserViewCommand(Controllers::CreateUser createUser)
	:createUser(std::move(createUser))
{
}

void CreateUserViewCommand::Run()
{
	const string userId = ReadUserId();
	//TODO: consider creating a result pattern to only do 1 call to the use case.
	if (createUser.DoesUserExist(userId))
	{
		cout << "ERROR: User already exists!" << endl;
	}
	else
	{
		createUser.Run(userId);
		cout << "User " << userId << " added!" << endl;
	}
}

string CreateUserViewCommand::ReadUserId() const
{
	cout << "Please enter name: ";
	string userId;
	getline(cin, userId);
	cout << endl;
	return userId;
}
}// namespace Views