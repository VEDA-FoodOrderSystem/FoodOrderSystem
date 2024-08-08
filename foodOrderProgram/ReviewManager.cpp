#include "ReviewManager.h"
ReviewManager::ReviewManager()
{

}
ReviewManager::~ReviewManager()
{

}
void ReviewManager::inputReview(int order_id)
{
	//평점, comment 입력 받기
	//order_id에 해당하는 order의 rating update
	//review_id 생성
	//review 생성 후 reviewList에 추가
	//displayReview(review_id)
}
Review* ReviewManager::search(int id)
{
	//해당 review_id를 가진 review 반환
}
int ReviewManager::makeId()
{
	//review_Id 생성
}
void ReviewManager::displayReview()
{
	//reviewList의 모든 review 출력
}
void ReviewManager::displayReview(int id)
{
	//reviewList에서 해당 review 출력
}