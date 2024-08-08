
#include "Menu.h"
#include <map>

class MenuManager
{
public:
    MenuManager();
    ~MenuManager();

    void inputMenu();
    void deleteMenu(int id);
    void editMenu(int id);
    Menu* search(int id);
    int makeId();
    void displayMenu();
    void displayMenu(int id);
    void sortMenu(int mode);
    bool selectMenu();

private:
    map<int, Menu*> menuList;
};

