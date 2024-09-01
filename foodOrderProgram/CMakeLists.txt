cmake_minimum_required(VERSION 3.26)
project(foodOrderProgram)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(foodOrderProgram
        Customer.cpp
        Customer.h
        CustomerManager.cpp
        CustomerManager.h
        FoodOrderSystem.cpp
        FoodOrderSystem.h
        main.cpp
        Menu.cpp
        Menu.h
        MenuManager.cpp
        MenuManager.h
        Order.cpp
        Order.h
        OrderManager.cpp
        OrderManager.h
        Review.cpp
        Review.h
        ReviewManager.cpp
        ReviewManager.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

# 테스트 실행 파일 생성
add_executable(tests
        Menu.cpp
        Order.cpp
        Review.cpp
        Customer.cpp
        MenuManager.cpp
        OrderManager.cpp
        ReviewManager.cpp
        CustomerManager.cpp
        tests/testMain.cpp
        tests/MenuTest.cpp
        tests/OrderTest.cpp
        tests/ReviewTest.cpp
        tests/CustomerTest.cpp
        tests/MenuManagerTest.cpp
        tests/OrderManagerTest.cpp
        tests/ReviewManagerTest.cpp
        tests/CustomerManagerTest.cpp
)
target_link_libraries(tests PRIVATE gtest gmock gtest_main)

# 테스트 자동 검색 및 실행 설정
enable_testing()
include(GoogleTest)
gtest_discover_tests(tests)