#include <gtest/gtest.h>
#include "Order.h"

// Order 생성자 테스트
TEST(OrderTest, ConstructorTest) {
    vector<pair<int, int>> menu = {{1, 2}, {2, 3}};
    Order order(1, "12:00", 100, 1, menu);

    EXPECT_EQ(order.getId(), 1);
    EXPECT_EQ(order.getTime(), "12:00");
    EXPECT_EQ(order.getCustomerId(), 100);
    EXPECT_EQ(order.getState(), 1);
    EXPECT_EQ(order.getOrderMenuList(), menu);
}

// getId() 테스트
TEST(OrderTest, GetIdTest) {
    Order order(5, "10:00", 200, 2, {});
    EXPECT_EQ(order.getId(), 5);
}

// setTime(), getTime() 테스트
TEST(OrderTest, SetAndGetTimeTest) {
    Order order;
    string newTime = "14:30";
    order.setTime(newTime);
    EXPECT_EQ(order.getTime(), newTime);
}

// setCustomerId(), getCustomerId() 테스트
TEST(OrderTest, SetAndGetCustomerIdTest) {
    Order order;
    order.setCustomerId(300);
    EXPECT_EQ(order.getCustomerId(), 300);
}

// setState(), getState() 테스트
TEST(OrderTest, SetAndGetStateTest) {
    Order order;
    order.setState(3);
    EXPECT_EQ(order.getState(), 3);
}

// setOrderMenuList(), getOrderMenuList() 테스트
TEST(OrderTest, SetAndGetOrderMenuListTest) {
    Order order;
    vector<pair<int, int>> menu = {{3, 1}, {4, 5}};
    order.setOrderMenuList(menu);
    EXPECT_EQ(order.getOrderMenuList(), menu);
}

// 기본값 테스트
TEST(OrderTest, DefaultConstructorTest) {
    Order order;
    EXPECT_EQ(order.getId(), 0);
    EXPECT_EQ(order.getTime(), "");
    EXPECT_EQ(order.getCustomerId(), 0);
    EXPECT_EQ(order.getState(), 0);
    EXPECT_TRUE(order.getOrderMenuList().empty());
}