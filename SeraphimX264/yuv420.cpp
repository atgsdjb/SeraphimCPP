#include"yuv420.h"
#include<exception>
#include<iostream>
using namespace std;
namespace Seraphim{
	Yuv420::Yuv420(int _width,int _height,int _count,char* fileName):YuvBase(_width,_height,_count),postion(0),countBuffer(0){
		long l_size = _width*_height;
	
		start_u = l_size;
		start_v = l_size*5/4;
		sizePreY = l_size;
		sizePreU= l_size/4;
		sizePreV = sizePreU;
		sizePreFrame = sizePreY+sizePreU+sizePreV;
		file = fopen(fileName,"rb+");
		assert(file!=NULL);
		buffer = new char[sizePreFrame*5];
	};
	void Yuv420::readData(){
		countBuffer = fread(buffer,1,sizePreFrame*5,file);
		FILE *f_t = fopen("t_temp.yuv","wb+");
		if(countBuffer%sizePreFrame != 0){
			//throw new  exception("error's file end");
			cout<<"read file error"<<endl;
		}
		fwrite(buffer,1,countBuffer,f_t);
		fflush(f_t);
		fclose(f_t);
		cout<<sizePreFrame*5<<"====="<<countBuffer<<endl;
		postion=-1;
	}
	//读数据时候都以getY为标志,处理当前位置,缓冲空等!
	char* Yuv420::getY(){
		if(countBuffer==0){
			readData();
			if(countBuffer == 0){
				return NULL;  //NULL 作为文件结束标志
			}
		}
		postion++;
		countBuffer -=sizePreFrame;
		return (char*)(buffer+postion*sizePreFrame);
	}
	char* Yuv420::getV(){
		return (char*)(buffer+postion*sizePreFrame+start_v);
	}
	char* Yuv420::getU(){
		return (char*)(buffer+postion*sizePreFrame+start_u);
	}
};