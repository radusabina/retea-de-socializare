//
// Created by Sabina on 4/30/2022.
//

#pragma once
#include "../TAD/list.h"
#include "../domain/user.h"

class RepositoryUser {
private:
    string users_file;
    List<User> users;
public:
    RepositoryUser();
    RepositoryUser(string);

    int add_user(User user);
    int remove_user(User user);
    int update_user(User user, User new_user);

    List<User> get_all_users();

    int get_nr_of_users();

    void save_to_file();

    ~RepositoryUser();
};
