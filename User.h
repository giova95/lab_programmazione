//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_USER_H
#define CHAT_PROJECT_USER_H

#include <iostream>
#include <map>

#include "Chat.h"

class Chat;
class User {
public:
    explicit User(std::string name) : name(name) {}

    virtual ~User(){}

    void addChat(Chat* c, User& u);

    void removeChat(const User& u);

    Chat* findChat(const User& u);

    Chat* createChat(User u);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

private:
    std::string name;
    std::map <std::string, Chat*> chats;
};
#endif //CHAT_PROJECT_USER_H
