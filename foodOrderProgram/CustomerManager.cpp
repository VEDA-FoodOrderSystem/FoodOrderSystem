#include "CustomerManager.h"

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

Customer* CustomerManager::inputCustomer()
{
    string name, phone;
    cout << endl;
    cout << "주문자(고객) 정보를 입력하세요." << endl;
    cout << "이름>> "; cin >> name;
    cout << "전화번호>> "; cin >> phone;

    int id = makeId();
    Customer* c = new Customer(id, name, phone);
    customerList.insert(make_pair(id, c));
    return c;
}