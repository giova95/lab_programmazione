//
// Created by giova on 07/03/21.
//

#include "User.h"

void User::addChat(Chat *c, User &u) {
    chats.insert(std::make_pair(u.getName(),c));
}

void User::removeChat(const User &u) {
     auto it = chats.find(u.getName());
     chats.erase(it);
}

Chat *User::findChat(const User &u) {
    auto it = chats.find(u.getName());
    return (it->second);
}

Chat *User::createChat(User u) {
    Chat* c = new Chat((*this),u);
    chats.insert(std::make_pair(u.getName(),c));
    u.addChat(c, *this);
    return c;
}


