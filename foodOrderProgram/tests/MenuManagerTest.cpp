#include <gtest/gtest.h>
#include "MenuManager.h"

class MenuManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        menuManager = new MenuManager();
    }

    void TearDown() override {
        delete menuManager;
    }

    MenuManager* menuManager;
};

// 테스트: 메뉴 저장
TEST_F(MenuManagerTest, SaveAndSearch) {
    int id = menuManager->saveMenu("떡볶이", 3000);
    auto menu = menuManager->search(id);
    ASSERT_NE(menu, nullptr);
    EXPECT_EQ(menu->getName(), "떡볶이");
    EXPECT_EQ(menu->getPrice(), 3000);
}

TEST_F(MenuManagerTest, Search_NonExisting) {
    auto foundMenu = menuManager->search(-1);
    EXPECT_EQ(foundMenu, nullptr);
}

// 테스트: 메뉴 수정
TEST_F(MenuManagerTest, Edit) {
    int id = menuManager->saveMenu("김밥", 3500);
    menuManager->saveEdit(id, "치즈김밥", 4000);
    auto menu = menuManager->search(id);
    ASSERT_NE(menu, nullptr);
    EXPECT_EQ(menu->getName(), "치즈김밥");
    EXPECT_EQ(menu->getPrice(), 4000);
}

// 테스트: 메뉴 삭제
TEST_F(MenuManagerTest, Delete) {
    int id = menuManager->saveMenu("돈까스", 8000);
    auto menu = menuManager->search(id);
    EXPECT_EQ(menu->getIsValid(), true);

    menuManager->deleteMenu(id);
    menu = menuManager->search(id);
    EXPECT_EQ(menu->getIsValid(), false);
}

// 테스트: 메뉴 정렬 (가격 기준)
TEST_F(MenuManagerTest, SortMenuByPrice) {
    menuManager->saveMenu("라면", 4000);
    menuManager->saveMenu("볶음밥", 5000);

    map<int, int> sortedMenu = menuManager->sortMenu(1); // Mode 1: Sort by price
    ASSERT_FALSE(sortedMenu.empty());

    auto it = sortedMenu.begin();
    EXPECT_EQ(it->second, 4); // Sushi should be first (ID 0)
    ++it;
    EXPECT_EQ(it->second, 1); // Salad should be second (ID 1)
}

// 테스트: 메뉴 정렬 (평점 기준)
TEST_F(MenuManagerTest, SortMenuByRating) {
    // Manually set stars and ordered for rating testing
    Menu* menu1 = menuManager->search(0);
    menu1->setStar(40);
    menu1->setOrdered(10);

    Menu* menu2 = menuManager->search(1);
    menu2->setStar(50);
    menu2->setOrdered(5);

    map<int, int> sortedMenu = menuManager->sortMenu(2); // Mode 2: Sort by rating
    ASSERT_FALSE(sortedMenu.empty());

    auto it = sortedMenu.begin();
    EXPECT_EQ(it->second, 1); // Rice should be first (higher rating)
    ++it;
    EXPECT_EQ(it->second, 0); // Noodles should be second
}

