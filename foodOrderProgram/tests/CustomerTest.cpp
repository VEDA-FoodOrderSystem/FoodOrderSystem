#include <gtest/gtest.h>
#include "Customer.h"

// 기본 생성자 테스트
TEST(CustomerTest, DefaultConstructor) {
    Customer customer;
    EXPECT_EQ(customer.getId(), 0);
    EXPECT_EQ(customer.getName(), "");
    EXPECT_EQ(customer.getPhone(), "");
}

// 매개변수화된 생성자 테스트
TEST(CustomerTest, ParameterizedConstructor) {
    Customer customer(1, "Hyetae", "010-1234-5678");
    EXPECT_EQ(customer.getId(), 1);
    EXPECT_EQ(customer.getName(), "Hyetae");
    EXPECT_EQ(customer.getPhone(), "010-1234-5678");
}

// setName과 getName 테스트
TEST(CustomerTest, SetName) {
    Customer customer;
    string newName = "Hyetae";
    customer.setName(newName);
    EXPECT_EQ(customer.getName(), "Hyetae");
}

// setPhone과 getPhone 테스트
TEST(CustomerTest, SetPhone) {
    Customer customer;
    string newPhone = "010-1234-5678";
    customer.setPhone(newPhone);
    EXPECT_EQ(customer.getPhone(), "010-1234-5678");
}

// setName과 setPhone 테스트
TEST(CustomerTest, SetNameAndPhone) {
    Customer customer;
    string name = "Hyetae";
    string phone = "010-1234-5678";
    customer.setName(name);
    customer.setPhone(phone);
    EXPECT_EQ(customer.getName(), "Hyetae");
    EXPECT_EQ(customer.getPhone(), "010-1234-5678");
}