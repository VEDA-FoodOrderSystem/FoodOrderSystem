#include <iostream>

using namespace std;

class Menu
{
public:
	Menu(int id = 0, string name = "", int star = 0, int price = 0, int ordered = 0);
    virtual int getId();
    virtual void setName(string& name);
    virtual string getName();
    virtual void setStar(int star);
    virtual double getStar();
    virtual void setPrice(int price);
    virtual int getPrice();
    virtual void setOrdered(int ordered);
    virtual int getOrdered();


private:
	int menu_id;
	string name;
	int star;
	int price;
	int ordered;
};

