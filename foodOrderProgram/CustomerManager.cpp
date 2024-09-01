#include "CustomerManager.h"
#include <fstream>
#include <sstream>

map<int, Customer*> CustomerManager::customerList;

CustomerManager::CustomerManager()
{
	ifstream file;
	file.open("customerList.csv");

	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				string name = row[1].c_str();
				string phone = row[2].c_str();
				Customer* c = new Customer(id, name, phone);
				customerList.insert({ id, c });
			}
		}
	}
	file.close();
}

CustomerManager::~CustomerManager()
{
	ofstream file;
	file.open("customerList.csv");

	if (!file.fail()) {
		for (const auto& v : customerList) {
			Customer* c = v.second;
			file << c->getId() << ", " << c->getName() << ", ";
			file << c->getPhone() << endl;
		}
	}
	file.close();
}

vector<string> CustomerManager::parseCSV(istream& file, char delimiter)
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

int CustomerManager::makeId()
{
    if (customerList.size() == 0) {
        return 0;
    }
    else {
        auto it = customerList.end();
        int lastId = (--it)->first;
        return (++lastId);
    }
}

Customer* CustomerManager::search(int id)
{
    return customerList[id];
}

Customer* CustomerManager::inputCustomer()
{
    string name, phone;
    cout << endl;
    cout << "주문자 정보를 입력하세요." << endl;
    cout << ">> 이름: "; cin >> name;
    cout << ">> 전화번호: "; cin >> phone;

    return saveCustomer(name, phone);
}

Customer* CustomerManager::saveCustomer(string name, string phone)
{
    int id = makeId();
    Customer* c = new Customer(id, name, phone);
    customerList.insert(make_pair(id, c));
    return c;
}