//
// Created by Sabina on 5/1/2022.
//

#include "user.h"
#include <utility>

User::User() {
    this->id = 0;
    this->username = "";
}

User::User(int id, string username) {
    this->id = id;
    this->username = std::move(username);
}

string User::get_username(){
    return this->username;
}

void User::set_username(string new_username) {
    this->username = std::move(new_username);

}

User &User::operator=(const User &u) {
    if(this != &u){
        this->id = u.id;
        this->username = u.username;
        }
        return * this;
    }

User::User( User &u) {
    this->id = u.id;
    this->username = u.username;
}

bool User::operator==( User &u) {
    return (this->id == u.id && this->username == u.username);
}

User::~User() {
    this->id = 0;
    this->username = "";
}

int User::get_id() {
    return this->id;
}

void User::set_id(int new_id) {
    this->id = new_id;
}

