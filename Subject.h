//
// Created by giova on 07/03/21.
//

#ifndef CHAT_PROJECT_SUBJECT_H
#define CHAT_PROJECT_SUBJECT_H
class Subject{
public:
    virtual void addObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notify()=0;
    virtual ~Subject(){}
};
#endif //CHAT_PROJECT_SUBJECT_H
