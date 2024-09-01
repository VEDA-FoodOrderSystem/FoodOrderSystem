#include <gtest/gtest.h>
#include "Menu.h"

// 기본 생성자 테스트
TEST(MenuTest, DefaultConstructor) {
    Menu menu;
    EXPECT_EQ(menu.getId(), 0);
    EXPECT_EQ(menu.getName(), "");
    EXPECT_EQ(menu.getStar(), 0);
    EXPECT_EQ(menu.getPrice(), 0);
    EXPECT_EQ(menu.getOrdered(), 0);
}

// 매개변수화된 생성자 테스트
TEST(MenuTest, ParameterizedConstructor) {
    Menu menu(1, "피자", 5, 100, 20);
    EXPECT_EQ(menu.getId(), 1);
    EXPECT_EQ(menu.getName(), "피자");
    EXPECT_EQ(menu.getStar(), 5);
    EXPECT_EQ(menu.getPrice(), 100);
    EXPECT_EQ(menu.getOrdered(), 20);
}

// setName과 getName 테스트
TEST(MenuTest, SetName) {
    string name = "떡볶이";

    Menu menu;
    menu.setName(name);
    EXPECT_EQ(menu.getName(), name);
}

// setStar와 getStar 테스트
TEST(MenuTest, SetStar) {
    Menu menu;
    menu.setStar(10);
    EXPECT_EQ(menu.getStar(), 10);
}

// setPrice와 getPrice 테스트
TEST(MenuTest, SetPrice) {
    Menu menu;
    menu.setPrice(200);
    EXPECT_EQ(menu.getPrice(), 200);
}

// setOrdered와 getOrdered 테스트
TEST(MenuTest, SetOrdered) {
    Menu menu;
    menu.setOrdered(15);
    EXPECT_EQ(menu.getOrdered(), 15);
}

// setStar 메서드의 덧셈 기능 테스트
TEST(MenuTest, IncrementStar) {
    Menu menu;
    menu.setStar(5);
    menu.setStar(3); // 기존 별점에 3을 더함
    EXPECT_EQ(menu.getStar(), 8); // 최종 별점은 8이어야 함
}
