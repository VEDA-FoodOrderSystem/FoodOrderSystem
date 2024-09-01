#include <iostream>
#include <vector>

using namespace std;
class Order {
public:
	Order(int order_id = 0, string time = "", int customer_id = 0, int state = 0, vector<pair<int, int>> orderMenuList = {});
	virtual int getId() const;
    virtual void setTime(string& time);
    virtual string getTime();
    virtual void setCustomerId(int id);
    virtual int getCustomerId() const;
    virtual void setState(int state);
    virtual int getState();
    virtual void setOrderMenuList(vector<pair<int, int>> orderMenu);
    virtual vector<pair<int, int>> getOrderMenuList();

private:
	int order_id;
	string time;
    int state;
	int customer_id;
    vector<pair<int, int>> orderMenuList; //menu_id, count
};

