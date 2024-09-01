#include "FoodOrderSystem.h"

FoodOrderSystem::FoodOrderSystem()
{
	this->mm = MenuManager();
	this->om = OrderManager();
	this->rm = ReviewManager();
	this->cm = CustomerManager();
}
FoodOrderSystem::~FoodOrderSystem()
{
	
}
bool FoodOrderSystem::selectManagerMenu()
{
	int m;
	cout << endl;
	cout << "원하는 메뉴를 선택하세요." << endl;
	cout << "1. 메뉴관리" << endl;
	cout << "2. 주문관리" << endl;
	cout << "3. 뒤로가기" << endl;
	cout << ">> ";  cin >> m;
	switch (m) {
	case 1 : //메뉴 관리
		while (1) {
			bool b = mm.selectMenu();
			if (!b) break;
		}
		break;
	case 2 : //주문 관리
		while (1) {
			bool b = om.selectMenu();
			if (!b) break;
		}
		break;
	case 3: default: //뒤로가기
		return false;
	}
	return true;
}

bool FoodOrderSystem::selectCustomerMenu()
{
	int m;
	cout << endl;
	cout << "원하는 메뉴를 선택하세요." << endl;
	cout << "1. 주문하기" << endl;
	cout << "2. 리뷰작성" << endl;
	cout << "3. 리뷰보기" << endl;
	cout << "4. 뒤로가기" << endl;
	cout << ">> ";  cin >> m;
	map<int, int> m1;
	switch (m) {
	case 1: //주문하기
		int mode;
		cout << endl;
		cout << "메뉴 정렬 기준을 선택하세요." << endl;
		cout << "(1) 가격  (2) 별점  (3) 주문횟수" << endl;
		cout << ">> "; cin >> mode;
		om.inputOrder(mm.sortMenu(mode)); //vector<int,int> idx,menu_id 의 pair
		break;
	case 2: //리뷰작성
		int orderId;
		int reviewId;
		cout << endl;
		cout << "리뷰를 작성할 주문번호를 입력해주세요." << endl;
		cout << ">> ";  cin >> orderId;

		if (om.search(orderId) == nullptr) {
			cout << endl;
			cout << "[Error]" << endl;
			cout << "존재하지 않는 주문번호입니다." << endl;
			break;
		}
		om.displayOrder(orderId, true);
		reviewId = rm.inputReview(orderId);
		break;
	case 3: //리뷰확인
		rm.displayReview();
		break;
	case 4: default:
		return false;
	}
	return true;
}


void FoodOrderSystem::run()
{
	int mode;
	cout << "[음식 주문 프로그램]" << endl;

	while (1) {
		cout << endl;
		cout << "원하는 모드를 선택하세요." << endl;
		cout << "1. 고객" << endl;
		cout << "2. 관리자" << endl;
		cout << "3. 종료" << endl;
		cout << ">> ";  cin >> mode;

		if (cin.fail()) {
			cout << endl;
			cout << "[Error]" << endl;
			cout << "잘못된 입력입니다. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (mode == 3) {
			break;
		}
		else if (mode == 1) {//고객 모드
			while (1) {
				bool b = selectCustomerMenu();
				if (!b) break;
			}
		}
		else if (mode == 2) {//관리자 모드
			while (1) {
				bool b = selectManagerMenu();
				if (!b) break;
			}
		}
		else {
			cout << endl;
			cout << "[Error]" << endl;
			cout << "잘못된 입력입니다. " << endl;
		}
	}
	cout << endl;
	cout << "프로그램이 종료되었습니다." << endl;
}