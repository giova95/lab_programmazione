//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_MESSAGE_H
#define CHAT_PROJECT_MESSAGE_H
#include <iostream>

class Message{
public:
    Message(std::string s, std::string r, std::string t): sender(s), receiver(r), text(t){}
    const std::string & getSender() const {
        return sender;
    }

    const std::string & getReceiver() const {
        return receiver;
    }

    const std::string & getText() const {
        return text;
    }

private:
    std::string receiver, sender, text;
};
#endif //CHAT_PROJECT_MESSAGE_H