#include <iostream>

using namespace std;

class Menu
{
public:
	Menu(int id = 0, string name = "", int star = 0, int price = 0, int ordered = 0);
	int getId();
	void setName(string& name);
	string getName();
	void setStar(int star);
	double getStar();
	void setPrice(int price);
	int getPrice();
	void setOrdered(int ordered);
	int getOrdered();


private:
	int menu_id;
	string name;
	int star;
	int price;
	int ordered;
};

