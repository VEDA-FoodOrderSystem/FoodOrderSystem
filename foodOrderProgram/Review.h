#include <iostream>
#include <vector>
using namespace std;
class Review
{
public:
	Review(int review_id = 0, int star = 0, string content = "", int order_id = 0);
    virtual int getId();
    virtual void setStar(int star);
    virtual double getStar();
    virtual void setContent(string& content);
    virtual string getContent();
    virtual void setOrderId(int id);
    virtual int getOrderId();

private:
	int review_id;
	int star;
	string content;
	int order_id;
};