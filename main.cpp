//
// Created by giova on 07/03/21.
//


#include <unistd.h>

#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotification.h"

using namespace std;

void menu();
Chat firstChoice(User u,int i);
vector<Chat>& secondChoice(vector<Chat>& c);

string name;
string name2;
string text;
vector<Chat> chats;

int main() {
    cout << "Insert your UserName: " << endl;
    cin >> name;
    User sender(name);
    cout<<"Loading..."<<endl;
    sleep(1);
    int id = 0;
    int s;
    //Menu
    do {
        menu();
        cout << "Make your Choice[1-3]: ";
        cin >> s;

        switch (s) {
            case 1:
                chats.push_back(firstChoice(sender, id));
                id++;
                break;
            case 2:
                chats = secondChoice(chats);
                break;
            case 3:
                cout<<"Exit...";
                exit(0);
            default:
                cerr << "Invalid Choice, try again!"<<endl;
        }
    } while (s != '3');
}

void menu(){
    cout<<"Welcome in Your Chat!"<<endl;
    sleep(1);
    cout<<"1) Text new message "<<endl;
    cout<<"2) View chat log "<<endl;
    cout<<"3) Exit"<<endl;
}

Chat firstChoice(User u, int i){
    string again;
    //create new chat
    cout << "Who you want to text ?" << endl;
    cin >> name2;
    User receiver(name2);
    Chat *chat = u.createChat(i, receiver);
    MessageNotification notificationCenter(true, chat);
    notificationCenter.attach();
    do {
        //text new message
        cout << "Type your message: " << endl;
        cin >> text;
        Message msg1(u.getName(), receiver.getName(), text, false);
        chat->addMessage(msg1);
        cout << receiver.getName() << " is Writing..." << endl;
        sleep(1);
        Message msg2(receiver.getName(), u.getName(), "Answer by " + receiver.getName() + " to " + u.getName(), false);
        chat->addMessage(msg2);

        cout << "Would you answer? [Yes or No]" << endl;
        cin >> again;
    }while(again == "Yes");

   return *chat;
}

vector<Chat>& secondChoice(vector<Chat>& c){
    cout<<"Your Chat Log "<<endl;
    cout<< "Loading... "<<endl;
    sleep(1);
    if(c.empty())
        cerr<<"There are no chats, you can start one from the menu! "<<endl;
    else{
        for(auto it:c){
            cout<<"There are "<<it.getUnreadMessages()<<" unread messages"<<endl;
            for(int m = 0; m < it.getMessages().size(); m++) {
                it.readMessage(m);
                sleep(3);
            }
        }
    }
    return c;
}
