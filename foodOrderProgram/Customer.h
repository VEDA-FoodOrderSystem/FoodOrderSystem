#include <iostream>
using namespace std;

class Customer
{
public:
	Customer(int id = 0, string name = "", string phone = "");
	int getId();
	void setName(string& name);
	string getName();
	void setPhone(string& phone);
	string getPhone();
private:
	int customer_id;
	string name;
	string phone;
};

