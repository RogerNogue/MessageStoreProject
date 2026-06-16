
#include "MessageStore.h"
#include "../src/Controllers/CreateUser.h"
#include <memory>
#include "../src/Views/Repository.h"

int main(int, const char* [])
{
	
	MessageStore store;

	auto repository = std::make_shared<Views::Repository>();

	Controllers::CreateUser createUser(repository);
	
	while (store.ProcessInput(createUser) == false){
	
	}
	
	store.terminate();
	
	return 0;
}
