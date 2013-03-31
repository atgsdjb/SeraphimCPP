#include<iostream>
#include"fs.h"
void t(){
  F* s=new S();
  delete s;
}
int main(int argc,char** argv){
	t();
	return 0;
}
