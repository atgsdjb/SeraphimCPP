#include"histogram.h"
#include<iostream>
#include"exception.h"
using namespace std;
namespace Seraphim{
	Histogram::Histogram(float _min,float _max,int count):min(_min),max(_max),countSection(count){
		if(_min > _max)
			throw InvalidArgumentException();
		section = new float[count];
		int i = 0;
		for(i;i<count;i++){
			cout<<"-------------"<<section[i]<<"-----------"<<endl;
		}

	}
	void Histogram::addValue(float value){
	};
};
