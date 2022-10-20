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
void secondChoice(vector<Chat>& c);
vector<Chat>& thirdChoice(vector<Chat>& c);

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
        cout << "Make your Choice[1-4]: ";
        cin >> s;

        switch (s) {
            case 1:
                chats.push_back(firstChoice(sender, id));
                id++;
                break;
            case 2:
                secondChoice(chats);
                break;
            case 3:
                chats = thirdChoice(chats);
                break;
            case 4:
                cout<<"Exit...";
                exit(0);
            default:
                cerr << "Invalid Choice, try again!"<<endl;
        }
    } while (s != '4');

}

/*
    //remove chat
    sender.removeChat(receiver);
}
*/

void menu(){
    cout<<"Welcome in Your Chat!"<<endl;
    sleep(1);
    cout<<"1) Text new message "<<endl;
    cout<<"2) View unread messages "<<endl;
    cout<<"3) View chat log "<<endl;
    cout<<"4) Exit"<<endl;
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

void secondChoice(vector<Chat>& c) {
    if(!c.empty()) {
        string read;
        for (auto chat: c)
            chat.getUnreadMessages(); //TODO: controllare funzione perche da messaggi non letti anche dopo aver letto da thirdchoice
        sleep(2);
        cout << "Do you want to read them? [Yes or No] " << endl;
        cin >> read;
        if (read == "Yes") {
            thirdChoice(c);
        }
    }
    else
        cerr<<"There are no chats, you can start one from the menu! "<<endl;
}


vector<Chat>& thirdChoice(vector<Chat>& c){
    cout<<"Your Chat Log "<<endl;
    cout<< "Loading... "<<endl;
    sleep(1);
    if(c.empty())
        cerr<<"There are no chats, you can start one from the menu! "<<endl;
    else{
        for(auto chat:c){
            chat.readMessages();
            sleep(4);
        }
    }
    return c;
}
