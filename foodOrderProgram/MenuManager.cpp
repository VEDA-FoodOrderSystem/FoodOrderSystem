#include "MenuManager.h"
#include <algorithm>
#include <fstream>
#include <sstream>

map<int, Menu*> MenuManager::menuList;

MenuManager::MenuManager()
{
	ifstream file;
	file.open("menulist.txt");

	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				int star = atoi(row[2].c_str());
				int price = atoi(row[3].c_str());
				int ordered = atoi(row[4].c_str());
				Menu* m = new Menu(id, row[1], star, price, ordered);
				menuList.insert({ id, m });
			}
		}
	}
	file.close();
}

MenuManager::~MenuManager()
{
	ofstream file;
	file.open("menulist.txt");

	if (!file.fail()) {
		for (const auto& v : menuList) {
			Menu* m = v.second;
			file << m->getId()<< ", " << m->getName() << ", ";
			file << m->getStar() << ", " << m->getPrice() << ",";
			file << m->getOrdered() << endl;
		}
	}
	file.close();
}


vector<string> MenuManager::parseCSV(istream& file, char delimiter)
{
	stringstream ss;
	vector<string> row;
	string t = " \n\r\t";

	while (!file.eof()) {
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n') {
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t));
			s.erase(s.find_last_not_of(t) + 1);
			row.push_back(s);
			ss.str("");
			if (c != delimiter) break;
		}
		else {
			ss << c;
		}
	}
	return row;
}

void MenuManager::inputMenu()
{
	string menuName;
	int menuPrice;
	cout << endl;
	cout << "등록할 메뉴의 정보를 입력해주세요." << endl;
	cout << "이름>> "; cin >> menuName;
	cout << "가격>> "; cin >> menuPrice;


	int id = makeId();
	Menu* m = new Menu(id, menuName, 0, menuPrice, 0);
	menuList.insert(make_pair(id, m));

	cout << "------------------------------" << endl;
	cout << "*신메뉴 " << menuName << "이 등록되었습니다." << endl;
	displayMenu(id);
	cout << "------------------------------" << endl;
}

void MenuManager::deleteMenu(int id)
{
	Menu* m = search(id);
	cout << "------------------------------" << endl;
	cout << "*삭제된 메뉴는 다음과 같습니다." << endl;
	displayMenu(id);
	cout << "------------------------------" << endl;

	menuList.erase(id);
}

void MenuManager::editMenu(int id)
{
	string editName;
	int editPrice;
	cout << endl;
	cout << "수정할 내용을 입력해주세요." << endl;
	cout << "이름>> "; cin >> editName;
	cout << "가격>> "; cin >> editPrice;
	
	Menu* m = search(id);
	m->setName(editName);
	m->setPrice(editPrice);
	menuList[id] = m;

	cout << "------------------------------" << endl;
	cout << "*수정된 메뉴는 다음과 같습니다." << endl;
	displayMenu(id);
	cout << "------------------------------" << endl;
}

Menu* MenuManager::search(int id)
{
	return menuList[id];
}

int MenuManager::makeId()
{
	if (menuList.size() == 0) {
		return 0;
	}
	else {
		auto it = menuList.end();
		int lastId = (--it)->first;
		return (++lastId);
	}
}

void MenuManager::displayMenu(vector < pair<int, Menu*>> v)
{
	cout << endl;
	cout << "현재 등록된 메뉴 리스트입니다." << endl;
	cout << "------------------------------" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		Menu* m = (*it).second;
		double rating;
		if (m->getOrdered() == 0) {
			rating = -1.0;
		}
		else {
			rating = m->getStar() / m->getOrdered();
		}

		cout << "(" << distance(v.begin(), it)+1 << ")" << endl;
		cout << "메뉴 : " << m->getName() << endl;
		cout << "가격 : " << m->getPrice() << endl;
		if (rating == -1.0) {
			cout << "신메뉴 입니다." << endl;
		}
		else {
			cout << fixed;
			cout.precision(2);
			cout << "평점 : " << rating << endl;
		}
	}
	cout << "------------------------------" << endl;
}

void MenuManager::displayMenu()
{
	cout << endl;
	cout << "현재 등록된 메뉴 리스트입니다." << endl;
	cout << "------------------------------" << endl;
	for (const auto& v : menuList) {
		Menu* m = v.second;

		cout << "(" << m->getId() + 1 << ")" << endl;
		cout << "메뉴 : " << m->getName() << endl;
		cout << "가격 : " << m->getPrice() << endl;
	}
	cout << "------------------------------" << endl;
}
void MenuManager::displayMenu(int id)
{
	Menu* m = search(id);
	cout << "이름 : " << m->getName() << endl;
	cout << "가격 : " << m->getPrice() << endl;
}


bool MenuManager::compPrice(pair<int, Menu*>& a, pair<int, Menu*>& b)

{
	return a.second->getPrice() > b.second->getPrice();
}

bool MenuManager::compRating(pair<int, Menu*>& a, pair<int, Menu*>& b)
{
	double ratingA, ratingB;
	if (a.second->getOrdered() == 0) ratingA = -1.0;
	else {
		ratingA = a.second->getStar() / a.second->getOrdered();
	}
	if (b.second->getOrdered() == 0) ratingB = -1.0;
	else {
		ratingB = b.second->getStar() / b.second->getOrdered();
	}
	return ratingA > ratingB;
}


bool MenuManager::compOrdered(pair<int, Menu*>& a, pair<int, Menu*>& b)
{
	return a.second->getOrdered() > b.second->getOrdered();
}

map<int,int>  MenuManager::sortMenu(int mode)
{
	vector<pair<int, Menu*>> v(menuList.begin(), menuList.end());
	map <int, int> m;
	switch (mode) {
	case 1:
		sort(v.begin(), v.end(), compPrice);
		displayMenu(v);
		for (auto it = v.begin(); it != v.end(); it++) {
			m.insert(make_pair(distance(v.begin(), it)+1, (*it).second->getId()));
		}
		break;
	case 2:
		sort(v.begin(), v.end(), compRating);
		displayMenu(v);
		for (auto it = v.begin(); it != v.end(); it++) {
			m.insert(make_pair(distance(v.begin(), it) + 1, (*it).second->getId()));
		}
		break;
	case 3:
		sort(v.begin(), v.end(), compOrdered);
		displayMenu(v);
		for (auto it = v.begin(); it != v.end(); it++) {
			m.insert(make_pair(distance(v.begin(), it) + 1, (*it).second->getId()));
		}
		break;
	}
    return m;
}

bool MenuManager::isExistMenu(int id)
{
	if (menuList.find(id) == menuList.end()) return false;
	else {
		return true;
	}
}

bool MenuManager::selectMenu()
{
	int mode, id;
	cout << endl;
	cout << "원하는 메뉴를 선택하세요." << endl;
	cout << "1. 메뉴 등록" << endl;
	cout << "2. 메뉴 수정" << endl;
	cout << "3. 메뉴 삭제" << endl;
	cout << "4. 뒤로 가기" << endl;
	cout << ">>"; cin >> mode;

	switch (mode) {
	case 1:
		inputMenu();
		break;
	case 2:
		displayMenu();
		cout << endl;
		cout << "수정할 메뉴의 번호를 입력하세요." << endl;
		cout << ">>"; cin >> id;
		while (!isExistMenu(id - 1)) {
			cout << "없는 메뉴입니다. 다시 입력하세요." << endl;
			cout << ">>"; cin >> id;
		}
		editMenu(id-1);
		break;
	case 3:
		displayMenu();
		cout << endl;
		cout << "삭제할 메뉴의 번호를 입력하세요." << endl;
		cout << ">>"; cin >> id;
		while (!isExistMenu(id - 1)) {
			cout << "없는 메뉴입니다. 다시 입력하세요." << endl;
			cout << ">>";  cin >> id;

		}
		deleteMenu(id - 1);
		break;
	case 4: default:
		return false;
	}
	return true;
}
