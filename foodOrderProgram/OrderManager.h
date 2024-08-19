#include "Order.h"
#include <map>

class MenuManager;
class CustomerManager;

class OrderManager {
public:
    OrderManager();
    ~OrderManager();

    vector<string> parseCSV(istream& file, char delimiter);

    void inputOrder(map<int, int> idx);
    void deleteOrder(int id);
    bool editOrder(int id);
    Order* search(int id);
    int makeId();
    bool displayOrder();
    void displayOrder(int id, bool isCustomer);
    bool selectMenu();
private:
    static map<int, Order*> orderList;
};

