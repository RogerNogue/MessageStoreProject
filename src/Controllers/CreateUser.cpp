#include "CreateUser.h"
#include "../Models/UserPool.h"
#include "IRepository.h"

namespace Controllers {

CreateUser::CreateUser(std::shared_ptr<IRepository> repository)
	: repository(std::move(repository))
{
}

UseCaseResult CreateUser::Run(const std::string& id)
{
	Models::UserPool userPool = repository->GetUserPool();
	Models::User newUser(id);

	if (userPool.Exists(newUser))
		return UseCaseResult::UserAlreadyExists;

	userPool.Create(std::move(newUser));
	repository->SaveUserPool(std::move(userPool));
	return UseCaseResult::Success;
}

} // namespace Controllers