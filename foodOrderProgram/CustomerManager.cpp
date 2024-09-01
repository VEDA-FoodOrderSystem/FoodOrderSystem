#include "CustomerManager.h"
#include <fstream>
#include <sstream>

map<int, Customer*> CustomerManager::customerList;

CustomerManager::CustomerManager() {
    ifstream file;
    file.open("customerlist.txt");
    if (!file.fail()) {
        while (!file.eof()) {
            vector<string> row = parseCSV(file, ',');
            if (row.size()) {
                int id = atoi(row[0].c_str());
                string name = row[1].c_str();
                string phone = row[2].c_str();

                Customer *c = new Customer(id, name, phone);
                customerList[id] = c;
            }
        }
    }
    file.close();
}

CustomerManager::~CustomerManager() {
    ofstream file;
    file.open("customerlist.txt");
    if (!file.fail()) {
        for (const auto& v : customerList) {
            Customer* c = v.second;
            if (c == NULL)
                continue;
            file << c->getId()<< ", " << c->getName() << ", " << c->getPhone() << "\n";
        }
    }
    file.close();
}

vector<string> CustomerManager::parseCSV(istream& file, char delimiter) {
    stringstream ss;
    vector<string> row;
    string t = " \n\r\t";
    char c;

    while (file.get(c)) {
        if (c == delimiter || c == '\r' || c == '\n') {
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t));
            s.erase(s.find_last_not_of(t) + 1);
            row.push_back(s);
            ss.str("");
            ss.clear(); // 스트링스트림 초기화

            // 만약 줄바꿈 문자를 만나면 종료
            if (c == '\r' && file.peek() == '\n') file.get(); // Windows 개행 처리 (\r\n)
            if (c == '\n') break;
        } else {
            ss << c;
        }
    }

    // 마지막 값 처리
    if (!ss.str().empty()) {
        string s = ss.str();
        s.erase(0, s.find_first_not_of(t));
        s.erase(s.find_last_not_of(t) + 1);
        row.push_back(s);
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
    if (customerList.find(id) != customerList.end())
        return customerList[id];
    return nullptr;
}

Customer* CustomerManager::inputCustomer()
{
    string name, phone;
    cout << endl;
    cout << "주문자(고객) 정보를 입력하세요." << endl;
    cout << "이름>> "; cin >> name;
    cout << "전화번호>> "; cin >> phone;

    return saveCustomer(name, phone);
}

Customer* CustomerManager::saveCustomer(string name, string phone)
{
    int id = makeId();
    Customer* c = new Customer(id, name, phone);
    customerList.insert(make_pair(id, c));
    return c;
}