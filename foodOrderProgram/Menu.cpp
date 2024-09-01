#include "Menu.h"

Menu::Menu(int id, string name, int star, int price, int ordered, bool isValid)
{
	menu_id = id;
	this->name = name;
	this->star = star;
	this->price = price;
	this->ordered = ordered;
    this->isValid = isValid;
}
int Menu::getId()
{
	return menu_id;
}
void Menu::setName(string& name)
{
	this->name = name;
}
string Menu::getName()
{
	return name;
}
void Menu::setStar(int inputStar)
{
	this->star += inputStar;
}
double Menu::getStar()
{
	return star;
}
void Menu::setPrice(int price)
{
	this->price = price;
}
int Menu::getPrice()
{
	return price;
}
void Menu::setOrdered(int ordered)
{
	this->ordered = ordered;
}
int Menu::getOrdered()
{
	return ordered;
}
void Menu::setIsValid(bool valid)
{
    isValid = valid;
}
bool Menu::getIsValid()
{
    return isValid;
}
