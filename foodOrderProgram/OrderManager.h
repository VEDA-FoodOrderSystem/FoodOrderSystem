#include "Order.h"
class OrderManager
{
public:
    OrderManager();
    ~OrderManager();

    void inputOrder();
    void deleteOrder(int id);
    void editOrder(int id);
    Order* search(int id);
    int makeId();
    void displayOrder();
    void displayOrder(int id);
    bool selectMenu();
private:
    map<int, Order*> orderList;
};

