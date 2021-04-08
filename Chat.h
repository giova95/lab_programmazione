//
// Created by giova on 06/04/21.
//

#ifndef CHAT_PROJECT_CHAT_H
#define CHAT_PROJECT_CHAT_H


#include <string>
#include <list>
#include <vector>

#include "Subject.h"
#include "User.h"
#include "Message.h"

class Chat : public Subject{
public:
    Chat(User user1, User user2):myId(user1.getName()),otherId(user2.getName()){}

    virtual ~Chat(){}

    void addMessage(const Message& msg);

    void readMessage(int i);

    int getUnreadMessages();

    const Message& lastMessage();

    virtual void addObserver(Observer* o) override;

    virtual void removeObserver(Observer* o) override;

    virtual void notify() override;

    const std::string &getMyId() const {
        return myId;
    }

    const std::string &getOtherId() const {
        return otherId;
    }

    void setMyId(const std::string &myId) {
        Chat::myId = myId;
    }

    void setOtherId(const std::string &otherId) {
        Chat::otherId = otherId;
    }

private:
    std::list<Observer*> observers;
    std::vector<Message> messages;
    std::string myId,otherId;

};


#endif //CHAT_PROJECT_CHAT_H
