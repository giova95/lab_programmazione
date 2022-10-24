//
// Created by giova on 24/10/22.
//

#include "gtest/gtest.h"
#include "../Message.h"

TEST(Message, GetterSetter){
    Message text("giovanni", "alberto", "Hi, what's up?", false );
    ASSERT_EQ(text.getSender(), "giovanni");
    ASSERT_EQ(text.getReceiver(), "alberto");
    ASSERT_EQ(text.getText(), "Hi, what's up");
    ASSERT_EQ(text.isRead(), false);
    text.setRead(true);
    ASSERT_EQ(text.isRead(), true);
}
