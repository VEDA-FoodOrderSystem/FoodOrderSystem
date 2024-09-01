#include "Customer.h"
#include <map>
#include <vector>

class CustomerManager
{
public:
    CustomerManager();
    ~CustomerManager();
    vector<string> parseCSV(istream& file, char delimiter);

	virtual int makeId();
    virtual Customer* search(int id);
    virtual Customer* inputCustomer();
    virtual Customer* saveCustomer(string name, string phone);
private:
	static map<int, Customer*> customerList;
};

