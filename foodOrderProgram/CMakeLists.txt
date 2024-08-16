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
