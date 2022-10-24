cmake_minimum_required(VERSION 3.17)
project(chat_project)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Chat.cpp Chat.h Message.h Observer.h Subject.h User.h User.cpp)
set(SOURCE_FILES Chat.cpp Chat.h Message.h Observer.h Subject.h User.h User.cpp MessageNotification.cpp MessageNotification.h)
add_executable(chat_project main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(chat_project core)