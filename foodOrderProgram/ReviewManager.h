#include "Review.h"
#include <map>

class ReviewManager
{
public:
    ReviewManager();
    ~ReviewManager();

    vector<string> parseCSV(istream& file, char delimiter);

    void inputReview(int order_id);
    Review* search(int id);
    map<int, Review*> getReviewList();
    int makeId();
    void displayReview();
    void displayReview(int id);

private:
    static map<int, Review*> reviewList;
};

