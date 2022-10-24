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
    Message text("giovanni", "alberto", "Hi, what's up?", false);
    c.addMessage(text);
    ASSERT_THROW(c.readMessage(4), std::out_of_range);
    ASSERT_THROW(c.readMessage(0), std::out_of_range);
}