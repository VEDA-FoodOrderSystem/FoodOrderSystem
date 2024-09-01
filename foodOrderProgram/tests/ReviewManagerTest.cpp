#include "gtest/gtest.h"
#include "MenuManager.h"
#include "OrderManager.h"
#include "ReviewManager.h"
#include "CustomerManager.h"

class ReviewManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        orderManager = new OrderManager();
        reviewManager = new ReviewManager();
        customerManager = new CustomerManager();
    }

    void TearDown() override {
        delete orderManager;
        delete reviewManager;
        delete customerManager;
    }

    OrderManager* orderManager;
    ReviewManager* reviewManager;
    CustomerManager* customerManager;
};

// saveReview 함수 테스트
TEST_F(ReviewManagerTest, SaveAndSearch) {

    vector<pair<int, int>> orderMenu = {{1, 2}, {3, 4}};
    Customer* c = customerManager->saveCustomer("Hyetae", "010");

    int order_id = orderManager->saveOrder("2023.09.01 12:00", c->getId(), orderMenu);

    auto savedOrder = orderManager->search(order_id);

    int id = reviewManager->saveReview(4, "Good food", order_id);
    auto review = reviewManager->search(id);
    EXPECT_EQ(review->getStar(), 4);
    EXPECT_EQ(review->getContent(), "Good food");
    EXPECT_EQ(review->getOrderId(), order_id);
}

TEST_F(ReviewManagerTest, Search_NonExisting) {
    auto review = reviewManager->search(-1);
    EXPECT_EQ(review, nullptr);
}