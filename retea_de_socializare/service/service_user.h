//
// Created by Sabina on 4/30/2022.
//
#pragma once
#include "../repository/repository_user.h"

class ServiceUser {
private:
    RepositoryUser repo;
public:
    ServiceUser();
    explicit ServiceUser(RepositoryUser& repo);

    int add_user(int id, string nume);
    int remove_user(int id);
    int update_user(int id, string username, int new_id, string new_username);

    List<User> get_all_users();
    int get_number_of_users();

    User get_by_id(int id);

    ~ServiceUser();
};