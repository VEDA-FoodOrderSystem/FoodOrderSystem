#include <gtest/gtest.h>
#include "Review.h"

// 기본 생성자 테스트
TEST(ReviewTest, DefaultConstructor) {
    Review review;
    EXPECT_EQ(review.getId(), 0);
    EXPECT_EQ(review.getStar(), 0);
    EXPECT_EQ(review.getContent(), "");
    EXPECT_EQ(review.getOrderId(), 0);
}

// 매개변수화된 생성자 테스트
TEST(ReviewTest, ParameterizedConstructor) {
    Review review(1, 5, "Excellent", 1001);
    EXPECT_EQ(review.getId(), 1);
    EXPECT_EQ(review.getStar(), 5);
    EXPECT_EQ(review.getContent(), "Excellent");
    EXPECT_EQ(review.getOrderId(), 1001);
}

// setStar과 getStar 테스트
TEST(ReviewTest, SetStar) {
    Review review;
    review.setStar(4);
    EXPECT_EQ(review.getStar(), 4);
}

// setContent과 getContent 테스트
TEST(ReviewTest, SetContent) {
    Review review;
    string newContent = "Not bad";
    review.setContent(newContent);
    EXPECT_EQ(review.getContent(), "Not bad");
}

// setOrderId과 getOrderId 테스트
TEST(ReviewTest, SetOrderId) {
    Review review;
    review.setOrderId(2002);
    EXPECT_EQ(review.getOrderId(), 2002);
}

// setStar 메서드의 유효성 검사
TEST(ReviewTest, SetStarBounds) {
    Review review;
    review.setStar(10);
    EXPECT_EQ(review.getStar(), 10); // assuming that the star rating can be 10 or higher; adjust if necessary
}

// setContent와 setOrderId 메서드의 연속 테스트
TEST(ReviewTest, SetContentAndOrderId) {
    Review review;
    string content = "Great!";
    int orderId = 3003;
    review.setContent(content);
    review.setOrderId(orderId);
    EXPECT_EQ(review.getContent(), "Great!");
    EXPECT_EQ(review.getOrderId(), 3003);
}