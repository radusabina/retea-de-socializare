#include "service_user.h"

ServiceUser::ServiceUser() = default;

ServiceUser::ServiceUser(RepositoryUser &repo) {
    this->repo = repo;
}

int ServiceUser::add_user(int id, string username) {
    User u(id, username);
    return this->repo.add_user(u);
}

List<User> ServiceUser::get_all_users() {
    return this->repo.get_all_users();
}

int ServiceUser::get_number_of_users() {
    return this->repo.get_nr_of_users();
}

int ServiceUser::remove_user(int id) {
    User u;
    List<User> users = get_all_users();
    for (int i =0; i < get_number_of_users(); i++) {
        if (users[i].get_id() == id)
            u = users[i];
    }
     return this->repo.remove_user(u);
}

int ServiceUser::update_user(int id, string username,int new_id, string new_username) {
    User user(id, username);
    User new_user(new_id, new_username);
    return this->repo.update_user(user, new_user);
}

User ServiceUser::get_by_id(int id) {
    User u(0, "");
    List<User> users = get_all_users();
    for (int i =0; i < get_number_of_users(); i++) {
        if (users[i].get_id() == id)
            u = users[i];
    }
    return u;
}

ServiceUser::~ServiceUser() = default;