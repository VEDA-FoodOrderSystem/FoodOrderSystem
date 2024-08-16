#include <iostream>
#include <vector>

using namespace std;
class Order {
public:
	Order(int order_id = 0, string time = 0, int customer_id = 0, int state = 0, vector<pair<int, int>> orderMenuList = {});
	int getId() const;
	void setTime(string& time);
	string getTime();
	void setCustomerId(int id);
	int getCustomerId() const;
	void setState(int state);
	int getState();
	void setOrderMenuList(vector<pair<int, int>> orderMenu);
    vector<pair<int, int>> getOrderMenuList();

private:
	int order_id;
	string time;
    int state;
	int customer_id;
    vector<pair<int, int>> orderMenuList; //menu_id, count
};

