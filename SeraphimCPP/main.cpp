#include<iostream>
#include"single.h"
using namespace seraphim;
using namespace std;
single* reverseSignleList(single* s){
	if(s->getNext() == NULL)
		return s;
	single* rs = reverseSignleList(s->getNext());
	s->getNext()->setNext(s);
	s->setNext(NULL);
	return rs;	
}
int main(int argc,char** argv){
	int i;
	cout<<"hello"<<endl;

	single* pSingle=NULL;
	for(i=10;i>=1;--i){
		pSingle = new single(i,pSingle);
	}
	pSingle = reverseSignleList(pSingle);
	while(pSingle !=NULL){

		cout<<pSingle->getData()<<endl;
		pSingle = pSingle->getNext();
	}
		int* pi = new int[100];
		pi[0]=1;
		cout<<*pi<<endl;
		cin>>i;

	return 0;
}