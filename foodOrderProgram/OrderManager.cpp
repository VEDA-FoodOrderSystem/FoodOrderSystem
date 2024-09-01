#include <ctime>
#include <fstream>
#include <sstream>
#include "ReviewManager.h"
#include "MenuManager.h"
#include "OrderManager.h"
#include "CustomerManager.h"

map<int, Order*> OrderManager::orderList;

OrderManager::OrderManager() {
    ifstream file;
    file.open("orderlist.txt");
    if (!file.fail()) {
        while (!file.eof()) {
            vector<pair<int, int>> orderMenuList;
            vector<string> row = parseCSV(file, ',');
            if (row.size()) {
                int id = atoi(row[0].c_str());
                string time = row[1].c_str();
                int state = atoi(row[2].c_str());
                int customer_id = atoi(row[3].c_str());

                for (int i = 4; !strlen(row[i].c_str()) ; i++) {
                    orderMenuList.push_back({atoi(row[i].c_str()), atoi(row[i].c_str())});
                }

                Order* o = new Order(id, time, state, customer_id);
                orderList[id] = o;
            }
        }
    }
    file.close();
}

OrderManager::~OrderManager() {
    ofstream file;
    file.open("orderlist.txt");
    if (!file.fail()) {
        for (const auto& v : orderList) {
            Order* o = v.second;
            if (o == NULL)
                continue;
            file << o->getId()<< ", " << o->getTime() << ", ";
            file << o->getCustomerId() << ", " << o->getState() << ",";

            file << "{";
            vector<pair<int, int>> orderMenuList = o->getOrderMenuList();
            for (auto oml: orderMenuList) {
                file << "{" << oml.first << ", " << oml.second << "}, ";
            }
            file << "}" << endl;
        }
    }
    file.close();
}

vector<string> OrderManager::parseCSV(istream& file, char delimiter)
{
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

void OrderManager::inputOrder(map<int, int> idx) {

    MenuManager mm = MenuManager();
    CustomerManager cm = CustomerManager();

	// 메뉴, 수량 입력받고 orderMenuList에 추가
    cout << "원하는 메뉴의 번호와 수량을 입력하세요. (종료하려면 0을 입력하세요)\n";

    // 메뉴 번호와 수량을 임시 저장할 벡터
    vector<pair<int, int>> order;
    while (true) {
        int num, cnt;
        bool isContinue;
        cout << ">> 메뉴: "; cin >> num;

        if (!num)
            break;

        cout << ">> 수량: "; cin >> cnt;

        mm.search(idx[num])->setOrdered(cnt);
        order.push_back({idx[num], cnt});

        while (1) {
            try {
                int input;
                cout << "계속 주문하시겠습니까? (1)예 (2)아니오\n>> ";
                cin >> input;

                // 입력이 실패하면 예외를 발생시킴
                if (cin.fail())
                    throw runtime_error("형식에 맞지 않는 입력입니다.");

                if (input == 1) {
                    isContinue = true;
                    break;
                } else if (input == 2) {
                    isContinue = false;
                    break;
                } else throw runtime_error("범위에 어긋나는 입력입니다.");
            } catch (const runtime_error& e) {
                cout << "다시 입력해 주세요.\n";
            }
        }
        if (!isContinue)
            break;
    }

    // 주문자 정보 입력받기
    Customer *customer = cm.inputCustomer();

	//time 생성
    time_t timer = std::time(NULL);
    struct tm* t = localtime(&timer);
    string time = to_string(t->tm_year + 1900) + '.' + to_string(t->tm_mon + 1) + '.' + to_string(t->tm_mday)
            + ' ' + to_string(t->tm_hour) + ':' + to_string(t->tm_min);

    for (auto o: order) {
        Menu* menu = mm.search(o.first);
        menu->setOrdered(o.second);
    }

    int id = saveOrder(time, customer->getId(), order);

    //displayOrder(id)
    displayOrder(id, true);
}

int OrderManager::saveOrder(string time, int customer_id, const vector<pair<int, int>>& order) {

    MenuManager mm = MenuManager();

    //order_Id 생성
    int id = makeId();

    //Order 생성해서 orderList에 추가
    Order *newOrder = new Order(id, time, customer_id, 0, order);
    orderList.insert({id, newOrder});

    return id;
}

void OrderManager::deleteOrder(int id) {
    cout << "다음 주문이 삭제됩니다.\n";
	//displayOrder(id)
    displayOrder(id, false);
	//orderList에서 해당 order 삭제
    orderList.erase(id);
    cout << "주문이 삭제되었습니다.\n";
}

bool OrderManager::editOrder(int id) {
    int n;
    try {
        int input;
        cout << "수정할 타입을 선택해 주세요.\n";
        cout << "(1)조리 시작 (2)조리 완료 (3)삭제 (4)뒤로가기\n>> ";
        cin >> input;

        // 입력이 실패하면 예외를 발생시킴
        if (cin.fail())
            throw runtime_error("형식에 맞지 않는 입력입니다.");

        if (input == 1 || input == 2 || input == 3 || input == 4)
            n = input;
        else throw runtime_error("범위에 어긋나는 입력입니다.");
    } catch (const runtime_error& e) {
        cout << "되돌아갑니다.\n";
    }

    if (n == 1 || n == 2) {
        //해당 id의 order의 주문상태를 변경
        orderList[id]->setState(n);
        //displayOrder(id)
        displayOrder(id, false);
    } else if (n == 3) {
        deleteOrder(id);
        return false;
    }
    return true;
}

Order* OrderManager::search(int id) {
	//해당 id의 Order를 OrderList에서 반환
    if (orderList.find(id) != orderList.end())
        return orderList[id];
    return nullptr;
}

int OrderManager::makeId() {
	//order_id 생성
    if(orderList.empty()) {
        return 0;
    } else {
        auto elem = orderList.end();
        int id = (--elem)->first;
        return ++id;
    }
}

bool OrderManager::displayOrder() {

    if (orderList.empty()) {
        cout << "\n------------------------------\n";
        cout << "새로운 주문 및 진행 중인 주문이 없습니다.";
        cout << "\n------------------------------\n";
        return false;
    }

    cout << "새로운 주문 및 진행 중인 주문 목록입니다.\n";

	//orderList의 모든 order 출력
    for (auto order: orderList) {
        if (order.second->getState() == 2)
            continue;
        displayOrder(order.second->getId(), false);
    }

    return true;
}

void OrderManager::displayOrder(int id, bool isCustomer) {

    MenuManager mm = MenuManager();
    CustomerManager cm = CustomerManager();

	//해당 id의 order 출력
    Order* o = search(id);

    cout << "------------------------------\n";
    cout << "주문 번호: " << o->getId() << "번\n";

    cout << "  메뉴  : ";
    auto ordered = o->getOrderMenuList();
    for (auto it = ordered.begin(); it != ordered.end(); it++) {
        Menu *menu = mm.search(it->first);
        if (it != ordered.begin())
            cout << "       : ";
        cout << menu->getName() << ' ' << it->second << "개\n";
    }

    Customer* customer = cm.search(o->getCustomerId());
    cout << "  시간  : " << o->getTime() << "\n";
    cout << " 주문자  : " << customer->getName() << "\n";

    if (!isCustomer) {
        string state;
        switch (o->getState()) {
            case 0:
                state = "조리 전";
                break;
            case 1:
                state = "조리 중";
                break;
            case 2:
                state = "조리 완료";
                break;
        }
        cout << "  상태  : " << state << "\n";
    }

    cout << "------------------------------\n";
}

bool OrderManager::selectMenu() {
	//displayOrder()
    if (!displayOrder())
        return false;

    int id;
    while (1) {
        try {
            int input;
            cout << "수정할 주문 번호를 입력하세요. (종료는 0을 입력하세요)\n>> ";
            cin >> input;

            Order *order = search(id);

            // 입력이 실패하면 예외를 발생시킴
            if (input && order == nullptr)
                throw runtime_error("범위에 어긋나는 입력입니다.");
            else {
                id = input;
                break;
            }
        } catch (const runtime_error& e) {
            cout << "다시 입력해 주세요.\n";
        }
    }

    if (!id)
        return false;

	// 메뉴 수정
    if(!editOrder(id))
        return false;

    return false;
}