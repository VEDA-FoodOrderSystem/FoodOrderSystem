#include "MenuManager.h"
#include "OrderManager.h"
#include "ReviewManager.h"
#include "CustomerManager.h"

class FoodOrderSystem {
public:
	FoodOrderSystem();
	~FoodOrderSystem();
	void run();
private:
	MenuManager mm;
	OrderManager om;
	ReviewManager rm;
	CustomerManager cm;
	bool selectManagerMenu();
	bool selectCustomerMenu();
};