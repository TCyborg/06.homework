#include <gtest/gtest.h>
#include "myvector.h"

TEST(myvector, default_constructor) {
    myvector<int> vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}