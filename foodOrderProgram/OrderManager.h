#include "Order.h"
#include <map>

class MenuManager;
class CustomerManager;

class OrderManager {
public:
    OrderManager();
    ~OrderManager();

    vector<string> parseCSV(istream& file, char delimiter);

    virtual void inputOrder(map<int, int> idx);
    virtual int saveOrder(string time, int customer_id, const vector<pair<int, int>>& order);
    virtual void deleteOrder(int id);
    virtual bool editOrder(int id);
    virtual Order* search(int id);
    virtual int makeId();
    virtual bool displayOrder();
    virtual void displayOrder(int id, bool isCustomer);
    virtual bool selectMenu();
private:
    static map<int, Order*> orderList;
    friend class OrderManagerTest;
};

