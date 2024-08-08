#include "MenuManager.h"

MenuManager::MenuManager()
{

}

MenuManager::~MenuManager()
{

}

void MenuManager::inputMenu()
{
	//입력 받고 menu_id 생성
	//Menu() 생성
	//menuList에 넣기
	//생성한 Menu 출력(disiplayMenu(id) 호출)

}
void MenuManager::deleteMenu(int id)
{
	//삭제한 Menu 출력(displayMenu(id) 호출)
	//menuList에서 제거
}
void MenuManager::editMenu(int id)
{
	//수정할 내용 입력 받고
	//Menu 수정
}
Menu* MenuManager::search(int id)
{
	//menuList에서 해당 id의 Menu를 반환
}
int MenuManager::makeId()
{
	//menu_id를 생성
}
void MenuManager::displayMenu()
{
	//menuList의 모든 Menu 내용을 출력
}
void MenuManager::displayMenu(int id)
{
	//해당 id를 가진 Menu의 내용을 출력
}
void MenuManager::sortMenu(int mode)
{
	//mode (이름, 평점, 주문 수)에 맞게 menuList를 정렬
}
bool MenuManager::selectMenu()
{
	//사용자에게 menu를 입력받음
	//메뉴등록, 메뉴 수정, 돌아가기
}