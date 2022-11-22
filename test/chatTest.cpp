//
// Created by giova on 24/10/22.
//

#include "gtest/gtest.h"
#include "../Chat.h"

User g("giovanni");
User a("alberto");

TEST(Chat, GetterSetter){
    Chat c(0, g, a);
    ASSERT_EQ(c.getChatId(), 1);
    c.setChatId(3);
    ASSERT_EQ(c.getChatId(), 3);
    ASSERT_EQ(c.getMyId(), "giovanni");
    c.setMyId("giuseppe");
    ASSERT_EQ(c.getMyId(), "giuseppe");
    ASSERT_EQ(c.getOtherId(),"alberto");
    c.setOtherId("antonio");
    ASSERT_EQ(c.getOtherId(), "antonio");
}

TEST(Chat, Methods){
    Chat c(0, g, a);
    Message text1("giovanni", "alberto", "Hi, what's up?", false);
    Message text2("giovanni", "alberto", " Hi, I'm fine and you? ", false);
    Message text3("giorgio", "antonio", " Hi, this is an invalid message", false);
    c.addMessage(text1);
    c.addMessage(text2);
    ASSERT_THROW(c.addMessage(text3),std::invalid_argument);
    ASSERT_THROW(c.readMessage(4), std::out_of_range);
    ASSERT_THROW(c.readMessage(10), std::out_of_range);
    ASSERT_EQ(c.getUnreadMessages(), 0);
    ASSERT_EQ(g.getName(), text1.getSender());
    ASSERT_EQ(a.getName(), text1.getReceiver());
}