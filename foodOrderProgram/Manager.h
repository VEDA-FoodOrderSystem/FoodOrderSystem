#include <iostream>
using namespace std;

class Manager
{
public:
	Manager(string pw = "0000");
	void setPw(string& pw);
	string getPw();

private:
	string pw;
};

