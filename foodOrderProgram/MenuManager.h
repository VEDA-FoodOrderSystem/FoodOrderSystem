
#include "Menu.h"
#include <map>
#include <vector>

class MenuManager
{
public:
    MenuManager();
    ~MenuManager();

    vector<string> parseCSV(istream& file, char delimiter);
    void inputMenu();
    void deleteMenu(int id);
    void editMenu(int id);
    Menu* search(int id);
    int makeId();
    void displayMenu();
    void displayMenu(vector <pair<int, Menu*>> v);
    void displayMenu(int id);
    map<int, int>  sortMenu(int mode);
    bool selectMenu();

private:
    map<int, Menu*> menuList;
    bool isExistMenu(int id);
    static bool compPrice(pair<int, Menu*>& a, pair<int, Menu*>& b);
    static bool compRating(pair<int, Menu*>& a, pair<int, Menu*>& b);
    static bool compOrdered(pair<int, Menu*>& a, pair<int, Menu*>& b);
};

