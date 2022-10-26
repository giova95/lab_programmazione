//
// Created by giova on 07/03/21.
//

#include "User.h"
#include "Chat.h"

void User::addChat(Chat *c, User &u) {
    chats.insert(std::make_pair(u.getName(),c));
}

void User::removeChat(const User &u) {
     auto it = chats.find(u.getName());
     chats.erase(it);
     if(chats.empty())
         std::cout<<"Chat successfully remove "<<std::endl;
     else
         std::cerr<<"Unable to remove chat "<<std::endl;
}

Chat *User::findChat(const User &u) {
    auto it = chats.find(u.getName());
    return (it->second);
}

Chat *User::createChat(int i, User u) {
    Chat* c = new Chat(i, (*this), u);
    chats.insert(std::make_pair(u.getName(),c));
    u.addChat(c, *this);
    return c;
}


