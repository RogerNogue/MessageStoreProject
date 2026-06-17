# Implementation information

I've implemented a refactor for the original project without the usage of tests. I love doing TDD and after having finished it would have helped me verify functionality. But due to time issues and following the test's description I decided to not add automated tests.

I've decided to implement a layered architecture in which the names of the layers are: Models, Views and Controllers. My idea has been to implement the solution following all the modern layered architectures' principles. Also this closely connected with one of the exercise's intentions: to decouple the UI from the rest of the application. 

Due to time concerns, I've left some TODOs in the code:
* Making the User entity hashable would have improved the decoupling between the User class and the std::string class.
* `quit` pointer in ConsoleView. This could be improved by either using an event, directly closing the app, or using a return value for the commands.