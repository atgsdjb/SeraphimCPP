#include"../temp/Seraphim.h"
#include<iostream>
using namespace std;
int main(int argc ,char** argv){
	cout<<"hello seraphim"<<endl;
	string *str = new string("------");
	malloc(sizeof(int));
	vector<int> v;
	v.push_back(0);
	Seraphim mSeraphim("dongjb",30);
	cout<<mSeraphim.getName()<<"\told====="<<mSeraphim.getOld()<<endl;
	cout<<*str<<endl;
	return 0;
}
