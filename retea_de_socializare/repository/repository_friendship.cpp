#include <fstream>
#include "repository_friendship.h"

RepositoryFriendship::RepositoryFriendship() {
    this->friendship_file = "";
}

RepositoryFriendship::RepositoryFriendship(string friendship_file) {
    this->friendship_file = friendship_file;

    ifstream f(friendship_file);

    while (!f.eof() && !f.fail()) {
        int id_user1;
        int id_user2;
        f >> id_user1 >> id_user2;
        Friendship friendship(id_user1, id_user2);
        this->friendships.adauga(friendship);
    }
    f.close();
}

void RepositoryFriendship::add_friendship(Friendship f) {
    this->friendships.adauga(f);
    save_to_file();
}

vector<Friendship> RepositoryFriendship::get_all_friendships() {
    return this->friendships.get_all();
}

void RepositoryFriendship::save_to_file() {
    ofstream f(friendship_file);

    vector<Friendship> elems = friendships.get_all();
    for (Friendship friendship: elems)
        f << friendship.get_id_user1() << " " << friendship.get_id_user2() << endl;
    f.close();
}

void RepositoryFriendship::remove_friendship(Friendship f) {
    vector<Friendship> elems = friendships.get_all();
    for (Friendship friendship: elems)
        if (f == friendship)
            this->friendships.remove(f);
    save_to_file();
}

RepositoryFriendship::~RepositoryFriendship() = default;
