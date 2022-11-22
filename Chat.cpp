//
// Created by giova on 06/04/21.
//

#include "Chat.h"

Chat::Chat(int id, const User& u1, const User& u2) : chatId(id+1), myId(u1.getName()), otherId(u2.getName()) {}

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
    if(msg.getSender() == myId && msg.getReceiver() == otherId) {
        messages.push_back(msg);
        notify();
    }
    else
        throw std::invalid_argument("Invalid message, unregistered users");
}

void Chat::readMessage(int i){
    if(i<messages.size()) {
        if (messages[i].getSender() == otherId) {
            std::cout <<"Sender: "<< messages[i].getSender() <<", "<<"Receiver: "<< messages[i].getReceiver() << std::endl;
            std::cout <<"Text: "<< messages[i].getText() << std::endl;
            messages[i].setRead(true);
            notify();
        }
    }
    else
        throw std::out_of_range(" Message not in the chat");
}

int Chat::getUnreadMessages() {
    int UM=0;
    for(const auto& msg:messages) {
        if (msg.getReceiver() == myId) {
            if (!msg.isRead()) {
                UM += 1;
            }
        }
    }
    return UM;
}

const Message &Chat::lastMessage() {
    return messages.back();
}

