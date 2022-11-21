//
// Created by giova on 06/04/21.
//

#ifndef CHAT_PROJECT_MESSAGENOTIFICATION_H
#define CHAT_PROJECT_MESSAGENOTIFICATION_H

#include "Observer.h"
#include "Chat.h"
#include "Message.h"

class MessageNotification: public Observer{
public:
    MessageNotification(bool a, Chat* s): active(a), subject(s) {}

    virtual ~MessageNotification(){}

    void attach() override;

    void detach() override;

    void update() override;

    void print(const Message &msg);

    bool isActive() const {
        return active;
    }

    void setActive(bool act) {
        MessageNotification::active = act;
    }

private:
bool active;
Chat* subject;
};


#endif //CHAT_PROJECT_MESSAGENOTIFICATION_H
