//
// Created by giova on 06/04/21.
//

#include "Chat.h"

Chat::Chat(User u1, User u2) : myId(u1.getName()), otherId(u2.getName()) {}


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
    if(myId==msg.getReceiver())
        this->notify();
}

void Chat::readMessage(int i) {
    if (messages[i].getSender() == otherId && i<=messages.size()) {
        std::cout <<"Inviato da: "<< messages[i].getSender() <<", "<<"Ricevuto da: "<< messages[i].getReceiver() << std::endl;
        std::cout <<"Testo del messaggio: "<< messages[i].getText() << std::endl;
        messages[i].setRead(true);
        this->notify();
    }
    else
        std::cout<<"Messaggio non presente nella chat!"<<std::endl;
}

int Chat::getUnreadMessages() {
    int UM=0;
    for(auto& msg:messages) {
        if (msg.getReceiver() == myId)
            if (!msg.isRead())
                UM++;
    }
    return UM;
}

const Message &Chat::lastMessage() {
    return messages.back();
}

