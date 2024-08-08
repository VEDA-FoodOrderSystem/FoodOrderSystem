#include "OrderManager.h"

OrderManager::OrderManager()
{

}
OrderManager::~OrderManager()
{

}
void OrderManager::inputOrder()
{
	//메뉴, 수량 입력받고 orderMenuList에 추가
	//order_Id 생성
	//time 생성
	//Order 생성해서 orderList에 추가
	//displayOrder(id)
}
void OrderManager::deleteOrder(int id)
{
	//displayOrder(id)
	//orderList에서 해당 order 삭제
}
void OrderManager::editOrder(int id)
{
	//해당 id의 order의 주문상태를 변경
	//displayOrder(id)
}
Order* OrderManager::search(int id)
{
	//해당 id의 Order를 OrderList에서 반환
}
int OrderManager::makeId()
{
	//order_id 생성
}
void OrderManager::displayOrder()
{
	//orderList의 모든 order 출력
}
void OrderManager::displayOrder(int id)
{
	//해당 id의 order 출력
}
bool OrderManager::selectMenu()
{
	//displayOrder()
	//1.수정 2.삭제 3.종료 선택
}