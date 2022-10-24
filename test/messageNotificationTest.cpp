//
// Created by giova on 24/10/22.
//

#include "gtest/gtest.h"
#include "../MessageNotification.h"

TEST(MessageNotifier, isActive) {
    User g("giovanni");
    User a("alberto");
    Chat *c = new Chat(0, g, a);
    MessageNotification m(true, c);
    ASSERT_TRUE(m.isActive());
    m.setActive(false);
    ASSERT_FALSE(m.isActive());
}
