#include "CustomerManager.h"

map<int, Customer*> CustomerManager::customerList;

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