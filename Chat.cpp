//
// Created by giova on 06/04/21.
//

#include "Chat.h"

Chat::Chat(int id, User u1, User u2) : chatId(id+1), myId(u1.getName()), otherId(u2.getName()) {}


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

void Chat::readMessage(int i){
    if(i>0 && i<messages.size()) {
        if (messages[i].getSender() == otherId) {
            std::cout <<"Sender: "<< messages[i].getSender() <<", "<<"Receiver: "<< messages[i].getReceiver() << std::endl;
            std::cout <<"Text: "<< messages[i].getText() << std::endl;
            messages[i].setRead(true);
            this->notify();
        }
    }
    else
        throw std::out_of_range(" Messaggio non presente nella chat");
}

void Chat::readMessages() {
    std::cout<<"READ MESSAGES WITH: "<<this->getOtherId()<<" FROM CHAT: "<<chatId<<std::endl;
    for(auto msg:messages){
        std::cout <<"Message Text: "<< msg.getText() << std::endl;
        std::cout <<"Send By: "<< msg.getSender() << std::endl;
        msg.setRead(true);
        std::cout<<msg.isRead()<<std::endl;
    }
}

void Chat::getUnreadMessages() {
    int UM=0;
    for(const auto& msg:messages) {
        if (msg.getReceiver() == myId) {
            if (!msg.isRead()) {
                UM += 1;
            }
        }
    }
    if(UM!=0)
        std::cout<<"\033[1:32mYou have " << UM << " Unread Messages in Chat: "<<chatId<<"\033[0m"<<std::endl;
    else
        std::cout<<"\033[1:32mYou haven't unread Messages in Chat: \033[0m"<<chatId<<"\033[0m"<<std::endl;
}

const Message &Chat::lastMessage() {
    return messages.back();
}

