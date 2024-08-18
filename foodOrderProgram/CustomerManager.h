#include "Customer.h"
#include <map>
class CustomerManager
{
public:
	int makeId();
    Customer* search(int id);
	Customer* inputCustomer();
private:
	static map<int, Customer*> customerList;
};

