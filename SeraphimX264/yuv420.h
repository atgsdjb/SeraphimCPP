#ifndef  _SERAPHIM_YUV420_H
#define _SERAPHIM_YUV420_H
#include"yuv_base.h"
extern"C"{
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
};
namespace  Seraphim{
	class Yuv420 : public YuvBase{
	private:
		 long start_v;
		 long start_u;
		 //方便操作
		 long sizePreY;
		 long sizePreU;
		 long sizePreV;
		 //
		 long postion;
		 long sizePreFrame;
		 FILE* file;
		 char* buffer;
		 long  countBuffer;//Buffer中可用的数据!
		 void readData();
		 
	public:
		Yuv420(int _width,int _height,int _count,char* fileName);
		long getSizePreY(){return sizePreY;}
		long getSizePreU(){return sizePreU;}
		long getSizePreV(){return sizePreV;}
		virtual char* getY();
		virtual char* getU();
		virtual char* getV();
		virtual ~Yuv420(){
			fclose(file);
			delete buffer;

		};
	};

};
#endif