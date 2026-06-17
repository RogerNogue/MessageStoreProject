# Implementation information

I've implemented a refactor for the original project without the usage of tests. I love doing TDD and after having finished it would have helped me verify functionality. But due to time issues and following the test's description I decided to not add automated tests.

I've decided to implement a layered architecture in which the names of the layers are: Models, Views and Controllers. My idea has been to implement the solution following all the modern layered architectures' principles. Also this closely connected with one of the exercise's intentions: to decouple the UI from the rest of the application. 

Due to time concerns, I've left some TODOs in the code:
* Making the User entity hashable would have improved the decoupling between the User class and the std::string class.
* Implementing a result pattern for the use cases in the Controllers layer would have reduced the code duplication. I had to add the `DoesUserExist` function in all the use cases and decided to leave that code duplicated because the solution I probably would have gone with is to return a result and allow the use case to run only in one function call instead of unifying the code duplication.