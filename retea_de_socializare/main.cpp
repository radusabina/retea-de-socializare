#include "user_interface/user_interface.h"
#include "tests/tests.h"

int main() {
    test_all();


    RepositoryUser repo_user("users.txt");
    ServiceUser service_user(repo_user);

    RepositoryFriendship repo_friendship("friendship.txt");
    ServiceFriendship service_friendship(repo_friendship);
    UserInterface ui(service_user, service_friendship);


    ui.console();

    return 0;
}