#include "Review.h"
#include <map>

class ReviewManager
{
public:
    ReviewManager();
    ~ReviewManager();
    void inputReview(int order_id);
    Review* search(int id);
    int makeId();
    void displayReview();
    void displayReview(int id);

private:
    map<int, Review*> reviewList;
};

