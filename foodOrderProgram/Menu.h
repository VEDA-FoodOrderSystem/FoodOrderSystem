#include <iostream>

using namespace std;

class Menu
{
public:
	Menu(int id = 0, string name = "", double rating = 0.0, int price = 0, int ordered = 0);
	int getId();
	void setName(string& name);
	string getName();
	void setRating(double rating);
	double getRating();
	void setPrice(int price);
	int getPrice();
	void setOrdered(int ordered);
	int getOrdered();


private:
	int menu_id;
	string name; // char배열로??
	int rating;
	int price;
	int ordered;
};

