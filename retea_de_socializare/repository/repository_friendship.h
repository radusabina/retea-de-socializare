#pragma once
#include <string>
#include "../domain/friendship.h"
#include "../TAD/set.h"

using namespace std;

class RepositoryFriendship{
private:
    string friendship_file;
    Set<Friendship> friendships;
public:
    RepositoryFriendship();
    explicit RepositoryFriendship(string friendship_file);

    void add_friendship(Friendship f);
    void remove_friendship(Friendship f);

    vector<Friendship> get_all_friendships();

    void save_to_file();

    ~RepositoryFriendship();
};