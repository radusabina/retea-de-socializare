//
// Created by Sabina on 5/21/2022.
//

#include "message.h"

Message::Message() {
    this->id_user1 = 0;
    this->id_user2 = 0;
    this->message = "";
}

Message::Message(int id_user1, int id_user2, string message) {
    this->id_user1 = id_user1;
    this->id_user2 = id_user2;
    this->message = message;
}

Message::Message(Message &m) {
    this->id_user1 = m.id_user1;
    this->id_user2 = m.id_user2;
    this->message = m.message;
}

int Message::get_id_user1() {
    this->id_user1;
}

int Message::get_id_user2() {
    this->id_user2;
}
