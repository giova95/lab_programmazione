//
// Created by giova on 24/10/22.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(User, GetterSetter){
    User g("giovanni");
    ASSERT_EQ(g.getName(), "giovanni");
    g.setName("alberto");
    ASSERT_EQ(g.getName(), "alberto");
}