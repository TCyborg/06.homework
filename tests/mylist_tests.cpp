#include <gtest/gtest.h>
#include "mylist.h"

//1
TEST(mylist, default_constructor) {
    mylist<int> lst;
    ASSERT_TRUE(lst.empty());
}
//2
TEST(mylist, get_size) {
    mylist<int> lst;
    ASSERT_EQ(lst.size(), 0);
    
    lst.push_back(1);
    EXPECT_EQ(lst.size(), 1);
    
    lst.push_back(2);
    EXPECT_EQ(lst.size(), 2);
    
    lst.erase(0);
    EXPECT_EQ(lst.size(), 1);
}
//3
TEST(mylist, get_data) {
    mylist<int> lst;
    lst.push_back(0xbaadc0de);
    ASSERT_EQ(lst[0], 0xbaadc0de);
}
//4
TEST(mylist, push_back) {
    mylist<int> lst;
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(-1);
    lst.push_back(0xbaadc0de);
    lst.push_back(0x0badbabe);
    lst.push_back(2147483647);
    lst.push_back(-2147483648);
    
    ASSERT_EQ(lst.size(), 7);
    ASSERT_EQ(lst[0], 0);
    EXPECT_EQ(lst[1], 1);
    EXPECT_EQ(lst[2], -1);
    EXPECT_EQ(lst[3], 0xbaadc0de);
    EXPECT_EQ(lst[4], 0x0badbabe);
    EXPECT_EQ(lst[5], 2147483647);
    EXPECT_EQ(lst[6], -2147483648);
}
//5
TEST(mylist, insert_begin) {
    mylist<int> lst;
    lst.push_back(0xbaadc0de);
    lst.push_back(0x0badbabe);
    lst.insert(0, 0xbaadf00d);
    
    EXPECT_EQ(lst.size(), 3);
    EXPECT_EQ(lst[0], 0xbaadf00d);
    EXPECT_EQ(lst[1], 0xbaadc0de);
    EXPECT_EQ(lst[2], 0x0badbabe);
}
//6
TEST(mylist, insert_middle) {
    mylist<int> lst;
    lst.push_back(0xbaadc0de);
    lst.push_back(0x0badbabe);
    lst.insert(1, 0xbaadf00d);
    
    EXPECT_EQ(lst.size(), 3);
    EXPECT_EQ(lst[0], 0xbaadc0de);
    EXPECT_EQ(lst[1], 0xbaadf00d);
    EXPECT_EQ(lst[2], 0x0badbabe);
}
//7
TEST(mylist, erase_end) {
    mylist<int> lst;
    lst.push_back(0xbaadc0de);
    lst.push_back(0x0badbabe);
    lst.push_back(0xbaadf00d);
    lst.erase(2);
    
    EXPECT_EQ(lst.size(), 2);
    EXPECT_EQ(lst[0], 0xbaadc0de);
    EXPECT_EQ(lst[1], 0x0badbabe);
}
//8
TEST(mylist, erase_begin) {
    mylist<int> lst;
    lst.push_back(0xbaadf00d);
    lst.push_back(0xbaadc0de);
    lst.push_back(0x0badbabe);
    lst.erase(0);
    
    EXPECT_EQ(lst.size(), 2);
    EXPECT_EQ(lst[0], 0xbaadc0de);
    EXPECT_EQ(lst[1], 0x0badbabe);
}
//9
TEST(mylist, erase_middle) {
    mylist<int> lst;
    lst.push_back(0xbaadc0de);
    lst.push_back(0xbaadf00d);
    lst.push_back(0x0badbabe);
    lst.erase(1);
    
    EXPECT_EQ(lst.size(), 2);
    EXPECT_EQ(lst[0], 0xbaadc0de);
    EXPECT_EQ(lst[1], 0x0badbabe);
}