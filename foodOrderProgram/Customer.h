#include <iostream>
using namespace std;

class Customer
{
public:
	Customer(int id = 0, string name = "", string phone = "");
	virtual int getId();
    virtual void setName(string& name);
    virtual string getName();
    virtual void setPhone(string& phone);
    virtual string getPhone();
private:
	int customer_id;
	string name;
	string phone;
};

