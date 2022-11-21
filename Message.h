//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_MESSAGE_H
#define CHAT_PROJECT_MESSAGE_H
#include <iostream>
#include <unistd.h>

class Message{
public:
    Message(const std::string& se, const std::string& re, const std::string& te, bool r): sender(se), receiver(re), text(te), read(r){}

    const std::string & getSender() const {
        return sender;
    }

    const std::string & getReceiver() const {
        return receiver;
    }

    const std::string & getText() const {
        return text;
    }

    bool isRead() const {
        return read;
    }

    void setRead(bool r) {
        read = r;
    }

private:
    bool read;
    std::string receiver, sender, text;
};
#endif //CHAT_PROJECT_MESSAGE_H
