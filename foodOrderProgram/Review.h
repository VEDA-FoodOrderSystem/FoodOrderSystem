#include <iostream>
using namespace std;
class Review
{
public:
	Review(int review_id = 0, double rating = 0.0, string content = "", int order_id = 0);
	int getId();
	void setRating(double rating);
	double getRating();
	void setContent(string& content);
	string getContent();
	void setOrderId(int id);
	int getOrderId();

private:
	int review_id;
	double rating;
	string content;
	int order_id;
};

