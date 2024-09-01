#include "Menu.h"
#include <map>
#include <vector>

class MenuManager
{
public:
    MenuManager();
    ~MenuManager();

    vector<string> parseCSV(istream& file, char delimiter);

    virtual int inputMenu();
    virtual int saveMenu(string menuName, int menuPrice);
    virtual void deleteMenu(int id);
    virtual void editMenu(int id);
    virtual void saveEdit(int id, string name, int price);
    virtual Menu* search(int id);
    virtual int makeId();
    virtual void displayMenu();
    virtual void displayMenu(vector <pair<int, Menu*>> v);
    virtual void displayMenu(int id);
    virtual map<int, int>  sortMenu(int mode);
    virtual bool selectMenu();

private:
    static map<int, Menu*> menuList;
    bool isExistMenu(int id);
    static bool compPrice(pair<int, Menu*>& a, pair<int, Menu*>& b);
    static bool compRating(pair<int, Menu*>& a, pair<int, Menu*>& b);
    static bool compOrdered(pair<int, Menu*>& a, pair<int, Menu*>& b);
};

