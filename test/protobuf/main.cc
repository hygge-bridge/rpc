#include "test.pb.h"
#include <iostream>
using namespace hygge;

int main() {
    GetFriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *user1 = rsp.add_friend_list();
    user1->set_name("hygge");
    user1->set_age(22);
    user1->set_sex(User::MAN);
    User *user2 = rsp.add_friend_list();
    user2->set_name("helen");
    user2->set_age(33);
    user2->set_sex(User::MAN);

    for (int i = 0; i < rsp.friend_list_size(); ++i) {
        std::cout << rsp.friend_list(i).name() 
                  << rsp.friend_list(i).age()
                  << rsp.friend_list(i).sex()
                  << std::endl;
    }
    return 0;
}