#include <gtest/gtest.h>
#include "mylist.h"

TEST(mylist, default_constructor) {
    mylist<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}