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
