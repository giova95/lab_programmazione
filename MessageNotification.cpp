//
// Created by giova on 06/04/21.
//

#include "MessageNotification.h"

void MessageNotification::attach() {
    subject->addObserver(this);
}

void MessageNotification::detach() {
    subject->removeObserver(this);
}

void MessageNotification::update() {
    if(active)
        this->print(subject->lastMessage());
}

void MessageNotification::print(Message &msg) {
    std::cout << "Nuovo messaggio " <<std::endl;
    std::cout << "Inviato da "<< msg.getSender() << " a " << msg.getReceiver() << std::endl;
    std::cout << "Testo del messaggio: " << msg.getText() <<std::endl;
}