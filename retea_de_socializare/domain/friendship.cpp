//
// Created by Sabina on 5/14/2022.
//

#include "friendship.h"

Friendship::Friendship() {
    this->id_user1 = 0;
    this->id_user2 = 0;
}

Friendship::Friendship(int id_user1, int id_user2) {
    this->id_user1 = id_user1;
    this->id_user2 = id_user2;
}

Friendship::Friendship(const Friendship &f) {
    this->id_user1 = f.id_user1;
    this->id_user2 = f.id_user2;
}

int Friendship::get_id_user1() {
    return this->id_user1;
}

int Friendship::get_id_user2() {
    return this->id_user2;
}

Friendship::~Friendship() {
}

void Friendship::set_id_user1(int new_id_user1) {
    this->id_user1 = new_id_user1;
}

void Friendship::set_id_user2(int new_id_user2) {
    this->id_user2 = new_id_user2;
}

bool Friendship::operator==(Friendship& f) {
    return (this->id_user1 == f.id_user1 && this->id_user2 == f.id_user2);
}

bool Friendship::operator<(Friendship& f) {
    if (this->id_user1 < f.id_user1) return true;
    if (this->id_user1 == f.id_user1)
        if (this->id_user2 < f.id_user2) return true;
    return false;
}

bool Friendship::operator>(Friendship& f) {
    if (this->id_user1 > f.id_user1) return true;
    if (this->id_user1 == f.id_user1)
        if (this->id_user2 > f.id_user2) return true;
    return false;
}
