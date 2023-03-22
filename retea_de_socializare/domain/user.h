//
// Created by Sabina on 4/30/2022.
//

#pragma once
#include "../TAD/list.h"
#include <string>
#include <cstring>

using namespace std;

class User {
private:
    int id;
    string username;
public:
    User();
    User(int id, string username);
    User(User& u);

    int get_id();
    string get_username();
    void set_id(int new_id);
    void set_username(string new_username);

    User& operator=(const User& u);
    bool operator==(User& u);

    ~User();
};
