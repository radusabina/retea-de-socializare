//
// Created by Sabina on 5/14/2022.
//

#pragma once

class Friendship {
private:
    int id_user1;
    int id_user2;
public:
    Friendship();
    Friendship(int id_user1,int int_user2);
    Friendship(const Friendship& f);

    int get_id_user1();
    int get_id_user2();
    void set_id_user1(int new_id_user1);
    void set_id_user2(int new_id_user2);

    bool operator==(Friendship& f);
    bool operator<(Friendship& f);
    bool operator>(Friendship& f);

    ~Friendship();
};
