#include "Customer.h"
#include <map>
class CustomerManager
{
public:
	virtual int makeId();
    virtual Customer* search(int id);
    virtual Customer* inputCustomer();
    virtual Customer* saveCustomer(string name, string phone);
private:
	static map<int, Customer*> customerList;
};

