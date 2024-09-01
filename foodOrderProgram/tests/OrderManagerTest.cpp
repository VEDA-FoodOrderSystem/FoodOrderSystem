#include "gtest/gtest.h"
#include "MenuManager.h"
#include "OrderManager.h"
#include "CustomerManager.h"

class OrderManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        orderManager = new OrderManager();
        customerManager = new CustomerManager();
    }

    void TearDown() override {
        delete orderManager;
        delete customerManager;
    }

    OrderManager* orderManager;
    CustomerManager* customerManager;
};

TEST_F(OrderManagerTest, SaveAndSearch) {
    vector<pair<int, int>> orderMenu = {{1, 2}, {3, 4}};
    Customer* c = customerManager->saveCustomer("Hyetae", "010");

    int id = orderManager->saveOrder("2023.09.01 12:00", c->getId(), orderMenu);

    auto savedOrder = orderManager->search(id);
    ASSERT_NE(savedOrder, nullptr);
    EXPECT_EQ(savedOrder->getCustomerId(), c->getId());
    EXPECT_EQ(savedOrder->getOrderMenuList(), orderMenu);
}

TEST_F(OrderManagerTest, Search_NonExisting) {
    auto customer = customerManager->search(-1);
    EXPECT_EQ(customer, nullptr);
}

TEST_F(OrderManagerTest, Delete) {
    vector<pair<int, int>> orderMenu = {{1, 2}};
    Customer* c = customerManager->saveCustomer("Hyungee", "010");
    int id = orderManager->saveOrder("2023-08-31 12:00", c->getId(), orderMenu);

    auto order = orderManager->search(id);
    ASSERT_NE(order, nullptr);

    orderManager->deleteOrder(id);

    order = orderManager->search(id);
    EXPECT_EQ(order, nullptr);
}

TEST_F(OrderManagerTest, Edit) {
    vector<pair<int, int>> orderMenu = {{1, 2}};
    int id = orderManager->saveOrder("2023.08.31 12:00", 0, orderMenu);

    auto order = orderManager->search(id);
    ASSERT_NE(order, nullptr);
    EXPECT_EQ(order->getState(), 0);

    istringstream input("1");
    cin.rdbuf(input.rdbuf());

    bool result = orderManager->editOrder(id);

    EXPECT_TRUE(result);
    EXPECT_EQ(order->getState(), 1);
}
