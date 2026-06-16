
#include "MessageStore.h"
#include "../src/Controllers/CreateUser.h"
#include <memory>
#include "../src/Views/Repository.h"
#include "../src/Views/ConsoleView.h"

int main(int, const char* [])
{
	
	MessageStore store;

	auto repository = std::make_shared<Views::Repository>();

	Controllers::CreateUser createUser(repository);

	Views::ConsoleView view(createUser);
	
	while (store.ProcessInput(view) == false){
	
	}
	
	store.terminate();
	
	return 0;
}
