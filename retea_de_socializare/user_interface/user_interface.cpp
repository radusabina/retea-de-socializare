//
// Created by Sabina on 5/1/2022.
//

#include <iostream>
#include "user_interface.h"

using namespace std;

void UserInterface::console() {

    int option = 1;
    while (option != 0) {
        cout << "1. CRUD user\n";
        cout << "2. CRUD friendship\n";
        cout << "0. Exit\n";
        cout << endl;

        cout << "Enter an option: ";
        cin >> option;

        switch (option) {
            case 0: {break;}
            case 1: {user_console(); break;}
            case 2: {friendship_console(); break;}
            default: cout << "Wrong option. Please retry! \n";
        }
    }
}

UserInterface::UserInterface() = default;

UserInterface::UserInterface(ServiceUser &service_user, ServiceFriendship& service_friendship) {
    this->service_user = service_user;
    this->service_friendship = service_friendship;
}

UserInterface::~UserInterface() = default;

void UserInterface::add_user() {
    cout << "Enter the id: ";
    int id;
    cin >> id;
    cout << "Enter the username: ";
    string username;
    cin >> username;
    this->service_user.add_user(id, username);
}

void UserInterface::show_all_users() {
    List<User> users = this->service_user.get_all_users();
    for (int i = 0; i < this->service_user.get_number_of_users(); i++)
        cout << users[i].get_id() << " " << users[i].get_username() << endl;
}

void UserInterface::remove_user() {
     cout << "Enter the user's id: ";
     int id;
     cin >> id;
     this->service_user.remove_user(id);
}

void UserInterface::update_user() {
    cout << "Enter the user's id: ";
    int id;
    cin >> id;
    cout << "Enter the username you want to update:";
    string username;
    cin >> username;
    cout << "Enter the new id: ";
    int new_id;
    cin >> new_id;
    cout << "Enter the new username:";
    string new_username;
    cin >> new_username;
    this->service_user.update_user(id, username, new_id, new_username);
}

void UserInterface::user_console() {
    int option = 1;
    while(option != 0) {
        cout << "1. Add user\n";
        cout << "2. Show all users\n";
        cout << "3. Delete user\n";
        cout << "4. Update user\n";
        cout << "0. Exit\n";
        cout << endl;

        cout << "Enter the option:";
        cin >> option;

        switch (option) {
            case 0: break;
            case 1: {add_user(); break;}
            case 2: {show_all_users(); break;}
            case 3: {remove_user(); break;}
            case 4: {update_user(); break;}
            default: cout << "Wrong option. Please retry! \n";
        }
    }
}

void UserInterface::add_friendship() {
    cout << "Enter the first user id: ";
    int id_user1;
    cin >> id_user1;
    cout << "Enter the second user id: ";
    int id_user2;
    cin >> id_user2;
    this->service_friendship.add_friendship(id_user1, id_user2);
}

void UserInterface::show_all_friendships() {
    vector<Friendship> elems = this->service_friendship.get_all();
    User u;
    List<User> friends;
    int id = 0;
    for (Friendship f: elems) {
        if (f.get_id_user1() != id) {
            id = f.get_id_user1();
            u = this->service_user.get_by_id(f.get_id_user1());
            friends = get_friends(u);
            cout << u.get_username() << " :  [ ";
            for (int i = 0; i < friends.get_nr_elems(); i++)
                cout << friends[i].get_username() << " ";
            cout << " ]" << endl;
        }
    }
}

void UserInterface::friendship_console() {
    int option = 1;
    while (option != 0) {
        cout << "1. Add friendship\n";
        cout << "2. Show all friendships\n";
        cout << "3. Delete friendship\n";
        cout << "0. Exit\n";

        cout << "Enter the option: ";
        cin >> option;

        switch (option) {
            case 0: break;
            case 1: {add_friendship(); break;}
            case 2: {show_all_friendships(); break;}
            case 3: {remove_friendship(); break;}
            default: cout << "Wrong option. Please retry!!";
        }
    }
}

List<User> UserInterface::get_friends(User u) {
    List<User> friends;
    User user;
    for (Friendship f: this->service_friendship.get_all())
        if (u.get_id() == f.get_id_user1()) {
            user  = this->service_user.get_by_id(f.get_id_user2());
            friends.add(user);
        }
    return friends;
}

void UserInterface::remove_friendship() {
    cout << "Enter the first user id: ";
    int id_user1;
    cin >> id_user1;
    cout << "Enter the second user id: ";
    int id_user2;
    cin >> id_user2;
    this->service_friendship.remove_friendship(id_user1, id_user2);
}

