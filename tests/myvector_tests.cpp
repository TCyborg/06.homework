#include <gtest/gtest.h>
#include "myvector.h"
//1
TEST(myvector, default_constructor) {
    myvector<int> vec;
    ASSERT_TRUE(vec.empty());
}
//2
TEST(myvector, get_size) {
    myvector<int> vec;
    ASSERT_EQ(vec.size(), 0);
    
    vec.push_back(1);
    EXPECT_EQ(vec.size(), 1);
    
    vec.push_back(2);
    EXPECT_EQ(vec.size(), 2);
    
    vec.erase(0);
    EXPECT_EQ(vec.size(), 1);
}
//3
TEST(myvector, get_data) {
    myvector<int> vec;
    vec.push_back(0xbaadc0de);
    ASSERT_EQ(vec[0], 0xbaadc0de);
}
//4
TEST(myvector, push_back) {
    myvector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(-1);
    vec.push_back(0xbaadc0de);
    vec.push_back(0x0badbabe);
    vec.push_back(2147483647);
    vec.push_back(-2147483648);
    
    ASSERT_EQ(vec.size(), 7);
    ASSERT_EQ(vec[0], 0);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], -1);
    EXPECT_EQ(vec[3], 0xbaadc0de);
    EXPECT_EQ(vec[4], 0x0badbabe);
    EXPECT_EQ(vec[5], 2147483647);
    EXPECT_EQ(vec[6], -2147483648);
}
//5
TEST(myvector, insert_begin) {
    myvector<int> vec;
    vec.push_back(0xbaadc0de);
    vec.push_back(0x0badbabe);
    vec.insert(0, 0xbaadf00d);
    
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 0xbaadf00d);
    EXPECT_EQ(vec[1], 0xbaadc0de);
    EXPECT_EQ(vec[2], 0x0badbabe);
}
//6
TEST(myvector, insert_middle) {
    myvector<int> vec;
    vec.push_back(0xbaadc0de);
    vec.push_back(0x0badbabe);
    vec.insert(1, 0xbaadf00d);
    
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 0xbaadc0de);
    EXPECT_EQ(vec[1], 0xbaadf00d);
    EXPECT_EQ(vec[2], 0x0badbabe);
}
//7
TEST(myvector, erase_end) {
    myvector<int> vec;
    vec.push_back(0xbaadc0de);
    vec.push_back(0x0badbabe);
    vec.push_back(0xbaadf00d);
    vec.erase(2);
    
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 0xbaadc0de);
    EXPECT_EQ(vec[1], 0x0badbabe);
}
//8
TEST(myvector, erase_begin) {
    myvector<int> vec;
    vec.push_back(0xbaadf00d);
    vec.push_back(0xbaadc0de);
    vec.push_back(0x0badbabe);
    vec.erase(0);
    
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 0xbaadc0de);
    EXPECT_EQ(vec[1], 0x0badbabe);
}
//9
TEST(myvector, erase_middle) {
    myvector<int> vec;
    vec.push_back(0xbaadc0de);
    vec.push_back(0xbaadf00d);
    vec.push_back(0x0badbabe);
    vec.erase(1);
    
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 0xbaadc0de);
    EXPECT_EQ(vec[1], 0x0badbabe);
}