//
// Created by Sabina on 5/5/2022.
//

#include "../TAD/list.h"
#include "../domain/user.h"
#include "../domain/friendship.h"
#include "../repository/repository_user.h"
#include <cassert>

using namespace std;

void test_lista() {
    List<int> lista;

    lista.add(1);
    lista.add(2);
    lista.add(3);
    assert(lista[0] == 1);
    assert(lista[1] == 2);
    assert(lista[2] == 3);
    assert(lista.get_nr_elems() == 3);

    lista.remove(2);
    assert(lista[0] == 1);
    assert(lista[1] == 3);
    assert(lista.get_nr_elems() == 2);
    assert(lista.remove(1) == 1);
    assert(lista[0] == 3);
    assert(lista.remove(12) == 0);
    assert(lista.get_nr_elems() == 1);
    assert(lista.remove(3) == 1);
    assert(lista.get_nr_elems() == 0);

    lista.add(4);
    assert(lista[0] == 4);
    assert(lista.update(4, 10) == 1);
    assert(lista[0] == 10);
    assert(lista.get_nr_elems() == 1);
    assert(lista.update(9, 7) == 0);
    lista.remove(10);
    assert(lista.get_nr_elems() == 0);

    lista.add(1);
    lista.add(2);
    assert(lista.search(1) == 0);
    assert(lista.search(2) == 1);
    assert(lista.search(10) == -1);
}

void test_user() {
    User u1;
    assert(u1.get_id() == 0);
    assert(u1.get_username().empty());

    User u2(2, "user1");
    assert(u2.get_id() == 2);
    assert(u2.get_username() == "user1");

    User u3(u2);
    assert(u3.get_id() == 2);
    assert(u3.get_username() == "user1");

    u3.set_id(3);
    u3.set_username("user3");
    assert(u3.get_id() == 3);
    assert(u3.get_username() == "user3");

    User u4 = u3;
    assert(u4.get_id() == 3);
    assert(u4.get_username() == "user3");

    assert(u3 == u4);
}

void test_friendship() {
    Friendship f1;
    assert(f1.get_id_user1() == 0);
    assert(f1.get_id_user2() == 0);

    Friendship f2(1, 2);
    assert(f2.get_id_user1() == 1);
    assert(f2.get_id_user2() == 2);

    Friendship f3(f2);
    assert(f3.get_id_user1() == 1);
    assert(f3.get_id_user2() == 2);

    f3.set_id_user1(3);
    f3.set_id_user2(4);
    assert(f3.get_id_user1() == 3);
    assert(f3.get_id_user2() == 4);
}

void test_repository_user() {
    RepositoryUser repo("test_users.txt");
    List<User> elems = repo.get_all_users();
    User u;

    for (int  i = 0; i < repo.get_nr_of_users(); i++) {
        u = elems[i];
        repo.remove_user(u);
    }

    User u1(1, "iosua_pop");
    repo.add_user(u1);
    elems = repo.get_all_users();
    assert(elems[0] == u1);
    assert(repo.get_nr_of_users() == 1);

    User u2(2, "user2");
    repo.update_user(u1, u2);
    elems = repo.get_all_users();
    assert(elems[0] == u2);
    assert(repo.get_nr_of_users() == 1);

    repo.remove_user(u2);
    assert(repo.get_nr_of_users() == 0);
}

void test_all() {
    test_lista();
    test_user();
    test_friendship();
    test_repository_user();
}