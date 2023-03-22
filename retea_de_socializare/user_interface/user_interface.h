//
// Created by Sabina on 4/30/2022.
//

#pragma once
#include <iostream>
#include "../service/service_user.h"
#include "../service/service_friendship.h"

using namespace std;

class UserInterface {
private:
    ServiceUser service_user;
    ServiceFriendship service_friendship;

    void user_console();
    void add_user();
    void remove_user();
    void update_user();
    void show_all_users();

    void friendship_console();
    void add_friendship();
    void show_all_friendships();
    List<User> get_friends(User);
    void remove_friendship();

public:
    UserInterface();
    explicit UserInterface(ServiceUser&, ServiceFriendship&);

    void console();

    ~UserInterface();
};
