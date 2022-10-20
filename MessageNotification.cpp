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

void MessageNotification::update(){
    if(this->isActive())
        this->print(subject->lastMessage());
}

void MessageNotification::print(const Message &msg) {
    std::cout << " \033[1;32mNEW MESSAGE(1) \033[0m" <<std::endl;
    sleep(1);
    std::cout << "Message Text: " << msg.getText() <<std::endl;
    std::cout << "Send By: "<< msg.getSender() <<std::endl;
}
