#include "CreateUser.h"
#include "../Models/UserPool.h"
#include <iostream>

namespace Controllers {
	CreateUser::CreateUser(std::shared_ptr<IRepository> repository)
		: repository(std::move(repository))
	{
	}

	bool CreateUser::DoesUserExist(std::string id) const
	{
		Models::UserPool userPool = repository->GetUserPool();

		return userPool.Exists(Models::User(id));
	}

	void CreateUser::Run(std::string id) const
	{
		Models::UserPool userPool = repository->GetUserPool();

		Models::User user(id);
		userPool.Create(user);

		repository->SaveUserPool(userPool);
	}

} // namespace Controllers