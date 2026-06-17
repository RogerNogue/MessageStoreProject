cmake_minimum_required(VERSION 3.31)

project(ccss_test LANGUAGES CXX)

add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/MessageStore"
)

file(
    GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/MessageStore/*.cpp"
)
file(
    GLOB_RECURSE HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/MessageStore/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/MessageStore/*.hpp"
)

file(
    GLOB_RECURSE SRC_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE ${SOURCES}
    PRIVATE ${HEADERS}
    PRIVATE ${SRC_SOURCES}
    "src/Controllers/CreateUser.h" "src/Controllers/CreateUser.cpp" "src/Controllers/IRepository.h" "src/Views/Repository.h" "src/Models/UserPool.cpp"
 "src/Views/ConsoleView.h" "src/Views/ConsoleView.cpp" "src/Models/Message.h" "src/Models/Message.cpp" "src/Models/MessagePool.h" "src/Models/MessagePool.cpp" "src/Controllers/SendMessage.h" "src/Controllers/SendMessage.cpp" "src/Controllers/ReceiveAllMessages.h" "src/Controllers/ReceiveAllMessages.cpp" "src/Views/CreateUserView.h" "src/Views/CreateUserView.cpp" "src/Views/SendMessageView.h" "src/Views/SendMessageView.cpp" "src/Views/ReceiveMessagesView.h" "src/Views/ReceiveMessagesView.cpp" "src/Views/IMessageCommand.h" "src/Views/QuitCommand.h" "src/Views/InvalidOptionCommand.h")
