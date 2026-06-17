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
	switch (createUser.Run(userId))
	{
		case Controllers::UseCaseResult::Success:
			cout << "User " << userId << " added!" << endl;
			break;
		case Controllers::UseCaseResult::UserAlreadyExists:
			cout << "ERROR: User already exists!" << endl;
			break;
		default:
			break;
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