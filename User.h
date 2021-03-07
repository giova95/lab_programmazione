//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_USER_H
#define CHAT_PROJECT_USER_H
#include <iostream>
class User {
public:
    explicit User(std::string &name) : name(name) {}
    ~User();

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

private:
    std::string name;

};
#endif //CHAT_PROJECT_USER_H
