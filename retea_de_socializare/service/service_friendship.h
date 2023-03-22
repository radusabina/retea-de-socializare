//
// Created by Sabina on 5/17/2022.
//

#include "../repository/repository_friendship.h"

class ServiceFriendship {
private:
    RepositoryFriendship repo;
public:
    ServiceFriendship();
    explicit ServiceFriendship(RepositoryFriendship& repo);

    void add_friendship(int id_user1, int id_user2);
    void remove_friendship(int id_user1, int id_user2);

    vector<Friendship> get_all();

    ~ServiceFriendship();
};
