#include "Order.h"
#include <vector>

Order::Order(int order_id, string time, int customer_id, int state, vector<pair<int, int>> orderMenuList){
    this->order_id = order_id;
    this->time = time;
    this->customer_id = customer_id;
    this->state = state;
    this->orderMenuList = std::move(orderMenuList);
}

int Order::getId() const {
    return order_id;
}

void Order::setTime(string& time) {
    this->time = time;
}

string Order::getTime() {
    return time;
}

void Order::setCustomerId(int id) {
    this->customer_id = id;
}

int Order::getCustomerId() const {
    return customer_id;
}

void Order::setState(int state) {
    this->state = state;
}

int Order::getState() {
    return state;
}

void Order::setOrderMenuList(vector<pair<int, int>> orderMenu) {
    orderMenuList = orderMenu;
}

vector<pair<int, int>> Order::getOrderMenuList() {
    return orderMenuList;
}