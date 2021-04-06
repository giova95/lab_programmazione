//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_OBSEREVER_H
#define CHAT_PROJECT_OBSEREVER_H
class Observer{
public:
    virtual ~Observer(){}
    virtual void attach()=0;
    virtual void detach()=0;
    virtual update()=0;
};

#endif //CHAT_PROJECT_OBSEREVER_H
