//
// Created by giova on 06/04/21.
//

#include "Chat.h"


void Chat::addObserver(Observer *o) {
    observers.push_back(o);
}

void Chat::removeObserver(Observer *o) {
    observers.remove(o);
}

void Chat::notify() {
    for(auto obs:observers)
        obs->update();
}

void Chat::addMessage(const Message &msg) {
    messages.push_back(msg);
    this->notify();
}

void Chat::readMessage(int i) {
    if (messages[i].getSender() == otherId) {
        std::cout <<"Sender: "<< messages[i].getSender() <<", "<<"Receiver: "<< messages[i].getReceiver() << std::endl;
        std::cout <<"Text: "<< messages[i].getText() << std::endl;
        messages[i].setRead(true);
        this->notify();
    }
}

int Chat::getUnreadMessages() {
    int UM=0;
    for(auto& msg:messages)
        if(msg.getReceiver()==myId)
            if(!msg.isRead())
                UM++;
    return UM;
}

Message &Chat::lastMessage() {
    return messages.back();
}

