
#include "MessageStore.h"
#include "../src/Controllers/CreateUser.h"
#include "../src/Controllers/SendMessage.h"
#include "../src/Views/Repository.h"
#include "../src/Views/ConsoleView.h"
#include <memory>

int main(int, const char* [])
{
	
	MessageStore store;

	auto repository = std::make_shared<Views::Repository>();

	Controllers::CreateUser createUser(repository);
	Controllers::SendMessage sendMessage(repository);

	Views::ConsoleView view(createUser);
	
	while (store.ProcessInput(view, sendMessage) == false){
	
	}
	
	store.terminate();
	
	return 0;
}
