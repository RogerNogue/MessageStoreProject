#include "CreateUser.h"
#include "../Models/UserPool.h"
#include <iostream>

namespace Controllers {
	CreateUser::CreateUser(std::shared_ptr<IRepository> repository)
		: repository(std::move(repository))
	{
	}

	void CreateUser::Run() const
	{
		Models::UserPool userPool = repository->GetUserPool();

		std::cout << "Please enter name: ";
		std::string str;
		std::getline(std::cin, str);
		std::cout << std::endl;
		Models::User user(str);
		if (userPool.Exists(user))
		{
			std::cout << "ERROR: User already exists!" << std::endl;
		}
		else {
			userPool.Create(user);
			std::cout << "User " << str << " added!" << std::endl;
		}

		repository->SaveUserPool(userPool);
	}

} // namespace Controllers