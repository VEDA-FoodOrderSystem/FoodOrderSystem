#include <iostream>
#include <vector>
using namespace std;
class Review
{
public:
	Review(int review_id = 0, int star = 0, string content = "", int order_id = 0);
	int getId();
	void setStar(int star);
	double getStar();
	void setContent(string& content);
    string getContent();
	void setOrderId(int id);
	int getOrderId();

private:
	int review_id;
	int star;
	string content;
	int order_id;
};

