#include<string>
using namespace std;
class Seraphim{
public :
	string getName();
	int getOld();
	Seraphim(string _name,int _old):name(_name),old(_old){};
private:
	string name;
	int old;
};
