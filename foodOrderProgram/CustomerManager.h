#include "Customer.h"
#include <map>
class CustomerManager
{
public:
	int makeId();
	Customer* inputCustomer();
private:
	map<int, Customer*> customerList;
};

