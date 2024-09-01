#include <gtest/gtest.h>
#include "CustomerManager.h"

// Customer 생성자 테스트
class CustomerManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        customerManager = new CustomerManager();
    }

    void TearDown() override {
        delete customerManager;
    }

    CustomerManager* customerManager;
};

// saveCustomer() 테스트
TEST_F(CustomerManagerTest, Save) {
    auto c = customerManager->saveCustomer("Alice", "12345");
    EXPECT_EQ(customerManager->makeId(), c->getId() + 1);
}

// search() 테스트
TEST_F(CustomerManagerTest, Search_Existing) {
    auto c = customerManager->saveCustomer("Bob", "67890");
    auto foundCustomer = customerManager->search(c->getId());
    ASSERT_NE(foundCustomer, nullptr);
    EXPECT_EQ(foundCustomer->getName(), "Bob");
    EXPECT_EQ(foundCustomer->getPhone(), "67890");
}

TEST_F(CustomerManagerTest, Search_NonExisting) {
    auto foundCustomer = customerManager->search(-1);
    EXPECT_EQ(foundCustomer, nullptr);
}