cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp domain/user.h repository/repository_user.h service/service_user.h user_interface/user_interface.h repository/repository_user.cpp service/service_user.cpp user_interface/user_interface.cpp domain/user.cpp TAD/list.h TAD/BST.h TAD/nodeBST.h TAD/set.h tests/tests.h domain/friendship.cpp domain/friendship.h tests/tests.cpp repository/repository_friendship.cpp repository/repository_friendship.h service/service_friendship.cpp service/service_friendship.h domain/message.cpp domain/message.h)
