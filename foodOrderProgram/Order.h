#include <iostream>
#include <map>

using namespace std;
class Order
{
public:
	Order(int order_id = 0, string time = 0, int customer_id = 0, int state = 0, map<int, int> orderMenuList = {});
	int getId();
	void setTime(string& time);
	string getTime();
	void setCustomerId(int id);
	int getCustomerId();
	void setState(int state);
	int getState();
	void setOrderMenuList(map<int, int> orderMenuList);
	map<int, int> getOrderMenuList();

private:
	int order_id;
	string time;
	int customer_id;
	map<int, int> orderMenuList; //menu_id, count
};

