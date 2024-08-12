#include "FoodOrderSystem.h"
#include <iomanip>

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
	cout << ">>";  cin >> m;
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
	cout << ">>";  cin >> m;
	map<int, int> m1;
	switch (m) {
	case 1: //주문하기
		int mode;
		cout << endl;
		cout << "메뉴 정렬 기준을 선택하세요." << endl;
		cout << "(1) 가격  (2) 별점  (3) 주문횟수" << endl;
		cout << ">>"; cin >> mode;
		m1 = mm.sortMenu(mode);
		om.inputOrder(mm.sortMenu(mode)); //vector<int,int> idx,menu_id 의 pair
		break;
	case 2: //리뷰작성
		int orderId;
		cout << "리뷰를 작성할 주문번호를 입력해주세요." << endl;
		cout << ">>";  cin >> orderId;
		cout << "주문번호 "<<orderId<<"번에 대한 내역입니다."<<endl;
		cout << "------------------------------" << endl;
		om.displayOrder(orderId - 1);
		cout << "------------------------------" << endl;
		rm.inputReview(orderId - 1);
		break;
	case 3: //리뷰확인
		cout << "작성된 리뷰입니다." << endl;
		cout << "------------------------------" << endl;
		rm.displayReview();
		cout << "------------------------------" << endl;
		break;
	case 4: default:
		return false;
	}
	return true;
}


void FoodOrderSystem::run()
{
	int mode;
	cout << setw(10) << "[음식 주문 프로그램]" << endl;

	while (1) {
		cout << endl;
		cout << "원하는 모드를 선택하세요." << endl;
		cout << "1. 고객" << endl;
		cout << "2. 관리자" << endl;
		cout << "3. 종료" << endl;
		cout << ">>";  cin >> mode;


		if (mode == 3) break;
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
	}
	cout << "프로그램이 종료되었습니다." << endl;
}