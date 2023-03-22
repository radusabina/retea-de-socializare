//
// Created by Sabina on 5/17/2022.
//

#include "service_friendship.h"

ServiceFriendship::ServiceFriendship() = default;

ServiceFriendship::ServiceFriendship(RepositoryFriendship &repo) {
    this->repo = repo;
}

void ServiceFriendship::add_friendship(int id_user1, int id_user2) {
    Friendship f1(id_user1, id_user2);
    Friendship f2(id_user2, id_user1);
    this->repo.add_friendship(f1);
    this->repo.add_friendship(f2);
}

vector<Friendship> ServiceFriendship::get_all() {
    return this->repo.get_all_friendships();
}

void ServiceFriendship::remove_friendship(int id_user1, int id_user2) {
    Friendship f1(id_user1, id_user2);
    Friendship f2(id_user2, id_user1);
    this->repo.remove_friendship(f1);
    this->repo.remove_friendship(f2);
}

ServiceFriendship::~ServiceFriendship() = default;
