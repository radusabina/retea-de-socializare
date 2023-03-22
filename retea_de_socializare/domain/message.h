#pragma once
#include <string>

using namespace std;

class Message {
public:
    int id_user1;
    int id_user2;
    string message;
private:
    Message();
    Message(int id_user1, int id_user2, string message);
    Message(Message& m);

    int get_id_user1();
    int get_id_user2();
    string get_message();

    void set_id_user1(int new_id_user1);
    void set_id_user2(int new_id_user2);
    void set_message(string new_message);

    ~Message();
};