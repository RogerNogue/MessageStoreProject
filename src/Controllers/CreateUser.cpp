#include "CreateUser.h"
#include "../Models/UserPool.h"
#include <iostream>

namespace Controllers {
	CreateUser::CreateUser(std::shared_ptr<IRepository> repository)
		: repository(std::move(repository))
	{
	}

	void CreateUser::Run(std::string id) const
	{
		Models::UserPool userPool = repository->GetUserPool();

		Models::User user(id);
		if (userPool.Exists(user))
		{
			std::cout << "ERROR: User already exists!" << std::endl;
		}
		else {
			userPool.Create(user);
			std::cout << "User " << id << " added!" << std::endl;
		}

		repository->SaveUserPool(userPool);
	}

} // namespace Controllers