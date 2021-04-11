//
// Created by giova on 07/03/21.
//

#include <unistd.h>

#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotification.h"

int main(){
 std::string name;
 std::string name2;
 std::string text;

 //create a chat
 std::cout<<"Inserire il tuo nome utente:"<<std::endl;
 std::cin>>name;
 User mainUser(name);
 std::cout<<"A chi vuoi scrivere?"<<std::endl;
 std::cin>>name2;
 User otherUser(name2);
 Chat* chat = mainUser.createChat(otherUser);

 //texting message
 Message text1(name,name2,"Ciao "+ name2 + " Come stai?",false);
 Message text2(name2,name,"Ciao " + name + " Tutto bene, te?",false);
 Message text3(name, name2, "Abbastanza bene dai", false);
 Message text4(name2,name,"Sono contento, sentiamoci in settimana",false);

 //activate Message notification
 MessageNotification centroNotifiche(true,chat);
 centroNotifiche.attach();

 //chat simulator with notification, save messages
 chat->addMessage(text1);
 std::cout<< name2 + " sta scrivendo..."<<std::endl;
 sleep(2);
 chat->addMessage(text2);
 chat->addMessage(text3);
 chat->addMessage(text4);

 //read messages
  chat->readMessage(1);
  chat->readMessage(3);
  chat->readMessage(7);

 //check for unread messages
  chat->getUnreadMessages();

 //remove chat
   mainUser.removeChat(otherUser);
}

