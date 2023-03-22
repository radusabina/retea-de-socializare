//
// Created by Sabina on 5/1/2022.
//

#include <fstream>
#include "repository_user.h"

using namespace std;

RepositoryUser::RepositoryUser() = default;

int RepositoryUser::add_user(User user) {
    List<User> list_of_users = get_all_users();
    for (int i = 0; i < get_nr_of_users(); i++) {
        if (list_of_users[i].get_id() == user.get_id()) return 0;
    }
    this->users.add(user);
    save_to_file();
    return 1;
}

List<User> RepositoryUser::get_all_users() {
    return this->users;
}

int RepositoryUser::get_nr_of_users() {
    return this->users.get_nr_elems();
}

int RepositoryUser::remove_user(User user) {
    if (this->users.remove(user) == 1) {
        save_to_file();
        return 1;
    }
    return 0;
}

int RepositoryUser::update_user(User user, User new_user) {
    if (this->users.update(user, new_user) == 1) {
        save_to_file();
        return 1;
    }
    return 0;
}

RepositoryUser::RepositoryUser(string users_file) {
    this->users_file = users_file;

    ifstream f(users_file);

    while (!f.eof() && !f.fail()) {
        int id;
        string username;
        string password;
        f >> id >> username;
        User u(id, username);
        this->users.add(u);
    }
    f.close();
}

void RepositoryUser::save_to_file() {
    ofstream f(users_file);

    List<User> elems = this->get_all_users();
    for (int i = 0; i < get_nr_of_users(); i++)
        f << elems[i].get_id() << " " << elems[i].get_username() << endl;
    f.close();
}

RepositoryUser::~RepositoryUser() = default;
