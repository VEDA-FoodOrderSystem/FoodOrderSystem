#include "Review.h"
#include <map>

class ReviewManager
{
public:
    ReviewManager();
    ~ReviewManager();

    vector<string> parseCSV(istream& file, char delimiter);

    virtual int inputReview(int order_id);
    virtual int saveReview(int star, string content, int order_id);
    virtual Review* search(int id);
    virtual map<int, Review*> getReviewList();
    virtual int makeId();
    virtual void displayReview();
    virtual void displayReview(int id);

private:
    static map<int, Review*> reviewList;
};

