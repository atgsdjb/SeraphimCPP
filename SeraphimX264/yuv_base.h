#ifndef _SERAPHIM_YUV_BASE_H
#define _SERAPHIM_YUV_BASE_H
namespace Seraphim{
	class YuvBase{
	private:
		int width;
		int height;
		int count;
	public:
		YuvBase(int _width,int _height,int _count):width(_width),height(_height),count(_count){};
		int getWidth(){return width;}
		int getHeight(){return height;}
		virtual char* getY()=0;
		virtual char* getU()=0;
		virtual char* getV()=0;
	};
};
#endif