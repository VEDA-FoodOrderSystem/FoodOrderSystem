#include "Customer.h"

Customer::Customer(int id, string name, string phone)
{
	customer_id = id;
	this->name = name;
	this->phone = phone;
}

int Customer::getId()
{
	return customer_id;
}

void Customer::setName(string& name)
{
	this->name = name;
}
string Customer::getName()
{
	return name;
}
void Customer::setPhone(string& phone)
{
	this->phone = phone;
}
string Customer::getPhone()
{
	return phone;
}
