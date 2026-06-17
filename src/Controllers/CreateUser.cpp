#include "CreateUser.h"
#include "../Models/UserPool.h"
#include "IRepository.h"

namespace Controllers {

CreateUser::CreateUser(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

UseCaseResult CreateUser::Run(std::string id)
{
	Models::UserPool userPool = repository->GetUserPool();
	Models::User newUser(std::move(id));

	if (userPool.Exists(newUser))
		return UseCaseResult::UserAlreadyExists;

	userPool.Create(newUser);
	repository->SaveUserPool(userPool);
	return UseCaseResult::Success;
}

} // namespace Controllers