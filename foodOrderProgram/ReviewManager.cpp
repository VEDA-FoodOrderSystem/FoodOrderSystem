#include "ReviewManager.h"
#include "MenuManager.h"
#include "OrderManager.h"
#include "CustomerManager.h"
#include <vector>
#include <fstream>
#include <sstream>

map<int, Review*> ReviewManager::reviewList;

ReviewManager::ReviewManager() {

    ifstream file;
    file.open("reviewlist.csv");
    if (!file.fail()) {
        while (!file.eof()) {
            string content;
            vector<string> row = parseCSV(file, ',');
            if (row.size()) {
                int id = atoi(row[0].c_str());
                int star = atoi(row[1].c_str());
                string content = row[2].c_str();
                int order_id = atoi(row[3].c_str());

                Review* r = new Review(id);
                r->setStar(star);
                r->setContent(content);
                r->setOrderId(order_id);
                reviewList[id] = r;
            }
        }
    }
    file.close();
}

ReviewManager::~ReviewManager() {
    ofstream file;
    file.open("reviewlist.csv");
    if (!file.fail()) {
        for (const auto& v : reviewList) {
            Review* r = v.second;
            file << r->getId()<< ", " << r->getStar() << ", ";

            string content = r->getContent();
            file << content;
            //for (auto c: content)
                //file << c << ' ';
            file << ", " << r->getOrderId() << endl;
        }
    }
    file.close();
}

vector<string> ReviewManager::parseCSV(istream& file, char delimiter)
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

void ReviewManager::inputReview(int order_id) {
    OrderManager om = OrderManager();
    bool isExistReview = false;

    for (auto rv : reviewList) {
        if (rv.second->getOrderId() == order_id) isExistReview = true;
    }

    if (isExistReview) {
        cout << endl;
        cout << "[Error]" << endl;
        cout << "해당 주문은 이미 리뷰가 작성되었습니다." << endl;
        return;
    }

	//별점, comment 입력 받기
    int star;
    string content;
    while (1) {
        try {
            cout << endl;
            cout << "평점을 입력해 주세요. (0, 1, 2, 3, 4, 5)\n>> ";
            cin >> star;
            cin.ignore();
            if (star < 0 || star > 5) {
                throw runtime_error("범위에 어긋나는 입력입니다.");
            }
            else {
                break;
            }
        }
        catch (const runtime_error& e) {
            cout << endl;
            cout << "[Error]" << endl;
            cout << "다시 입력해주세요." << endl;
        }
    }
    cout << endl;
    cout << "리뷰를 입력해 주세요.\n>> ";
    getline(cin, content);

	saveReview(star, content, order_id);
}

void ReviewManager::saveReview(int star, string content, int order_id) {

    MenuManager mm = MenuManager();
    OrderManager om = OrderManager();

    //order_id에 해당하는 menu의 star update
    Order* order = om.search(order_id);
    vector<pair<int, int>> orderMenuList = order->getOrderMenuList();
    for (auto oml: orderMenuList) {
        Menu* menu = mm.search(oml.first);
        menu->setStar(star + (menu -> getStar()));
        menu->setReviewed(menu->getReviewed() + oml.second);
    }

    //review_id 생성
    int id = makeId();

    //review 생성 후 reviewList에 추가
    Review* review = new Review(id, star, content, order_id);
    reviewList.insert({id, review});

    //displayReview(review_id)
    cout << endl;
    displayReview(id);
}


Review* ReviewManager::search(int id)
{
	//해당 review_id를 가진 review 반환
    return reviewList[id];
}

map<int, Review*> ReviewManager::getReviewList() {
    return reviewList;
}

int ReviewManager::makeId()
{
	//review_Id 생성
    if(reviewList.size( ) == 0) {
        return 0;
    } else {
        auto elem = reviewList.end();
        int id = (--elem)->first;
        return ++id;
    }
}
void ReviewManager::displayReview() {

    map<int, Review*> reviewList = getReviewList();

    if (reviewList.empty()) {
        cout << endl;
        cout << "[Error]" << endl;
        cout << "작성된 리뷰가 없습니다.\n";
        return;
    }
    
    cout << endl;
    cout << "작성된 리뷰입니다." << endl;

	//reviewList의 모든 review 출력
    for (auto it = reviewList.rbegin(); it != reviewList.rend(); it++)
        displayReview(it->first);
}

void ReviewManager::displayReview(int id) {

    MenuManager mm = MenuManager();
    OrderManager om = OrderManager();
    CustomerManager cm = CustomerManager();

	//reviewList에서 해당 review 출력
    Review* review = search(id);
    cout << "------------------------------\n";

    Order* order = om.search(review->getOrderId());
    Customer* customer = cm.search(order->getCustomerId());
    cout << "주문 번호: " << review->getOrderId() << "번\n";

    cout << "  메뉴  : ";
    vector<pair<int, int>> orderMenuList = order->getOrderMenuList();
    for (auto oml: orderMenuList) {
        Menu* menu = mm.search(oml.first);
        cout << menu->getName() << ' ' << oml.second << "개\n";
    }

    cout << "  시간  : " << order->getTime() << "\n";
    cout << " 주문자  : " << customer->getName() << "\n";
    cout << "  평점  : " << review->getStar() << "\n";
    cout << "  리뷰  : " << review->getContent() << '\n';
    cout << "------------------------------\n";
}