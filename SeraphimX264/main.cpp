/**
* @note x264的编码示例.
* 使用x264的版本为libx264-115
* 1. 示例是个死循环,会源源不断的编码,然后将数据写文件.
* 2. 示例的行为是:编码1000帧后,取空编码缓冲区,然后循环执行这两步.

* @author 

*gcc  -lx264
**/  
#include <cassert>
#include <iostream>
#include <string>
#include "stdint.h"
#include <string.h>
#include <stdio.h> 
#include"yuv420.h"
//using namespace Seraphim;
//using namespace std;
//extern "C"
//{
//
//#include "x264.h"
//#include<stdio.h>
//#include<stdlib.h>
//} //;
//unsigned int g_uiPTSFactor = 0;
//int iNal = 0;
//x264_nal_t * pNals = NULL;
//int encode (x264_t * pX264Handle, x264_picture_t * pPicIn, x264_picture_t * pPicOut)
//{
//	int iResult = 0;
//	iResult =
//		x264_encoder_encode (pX264Handle, &pNals, &iNal, pPicIn, pPicOut);
////	if (0 == iResult)
//	{
//		std::cout << "编码成功,但被缓存了." << std::endl;
//	}
//	else if (iResult < 0)
//	{
//		std::cout << "编码出错" << std::endl;
//	}
//	else if (iResult > 0)
//	{
//		std::cout << "得到编码数据" << std::endl;
//	}
//	int iFrames = x264_encoder_delayed_frames (pX264Handle);
//	std::cout << "当前编码器中缓存数据:" << iFrames << "帧\n";
//	return iFrames;
//}
//void initParam(x264_param_t* pX264Param){
//	pX264Param->i_threads = X264_SYNC_LOOKAHEAD_AUTO;	//* 取空缓冲区继续使用不死锁的保证.//* video Properties
//
//	pX264Param->i_frame_total = 0;	//* 编码总帧数.不知道用0.
//	pX264Param->i_keyint_max = 10;
//	pX264Param->i_bframe = 5;
//	pX264Param->b_open_gop = 0;
//	pX264Param->i_bframe_pyramid = 0;
//	pX264Param->i_bframe_adaptive = X264_B_ADAPT_TRELLIS;
//	pX264Param->b_annexb = 1;
//	pX264Param->i_log_level = X264_LOG_DEBUG;
//	pX264Param->rc.i_bitrate = 1024 * 10;	//* 码率(比特率,单位Kbps), muxing parameters
//	pX264Param->i_fps_den = 1;	//* 帧率分母
//	pX264Param->i_fps_num = 25;	//* 帧率分子
//	pX264Param->i_timebase_den = pX264Param->i_fps_num;
//	pX264Param->i_timebase_num = pX264Param->i_fps_den;
//}
//void setParamSize(x264_param_t* pX264Param,int width,int height){
//	pX264Param->i_width = width;
//	pX264Param->i_height = height;
//} 
int
main2 (int argc, char **argv)
{
	int iResult = 0;
	//x264_t * pX264Handle = NULL;
	//x264_param_t * pX264Param = new x264_param_t;
	//assert (pX264Param);
	//x264_param_default (pX264Param);
	//initParam(pX264Param);
	//setParamSize(pX264Param,176,144);
	//x264_param_apply_profile (pX264Param, x264_profile_names[1]);
	//pX264Handle = x264_encoder_open (pX264Param);
	//assert (pX264Handle);
	//iResult = x264_encoder_headers (pX264Handle, &pNals, &iNal);
	//assert (iResult >= 0);
	for (int i = 0; i < 109; ++i)
	{
	//	switch (pNals[i].i_type)
	//	{
	//	case NAL_SPS:
	//		break;
	//	case NAL_PPS:
	//		break;
	//	default:
	//		break;
	//	}
	}
	//int iMaxFrames = x264_encoder_maximum_delayed_frames (pX264Handle);
	//iNal = 0;
	//pNals = NULL;
	//x264_picture_t * pPicIn = new x264_picture_t;
	//x264_picture_t * pPicOut = new x264_picture_t;
	//x264_picture_init (pPicOut);
	//x264_picture_alloc (pPicIn, X264_CSP_I420, pX264Param->i_width,
	//pX264Param->i_height);
	//pPicIn->img.i_csp = X264_CSP_I420;
	//pPicIn->img.i_plane = 3;
	//FILE * pFile = fopen ("agnt.264", "wb");
	//Yuv420 *yuv = new Yuv420(176,144,0,"test3.yuv");
	//assert (pFile);
	//int iDataLen = pX264Param->i_width * pX264Param->i_height;
	//uint8_t * data = new uint8_t[iDataLen];
	//unsigned int uiComponent = 0;
	//while (++uiComponent)
	//{
	//	char* yp = yuv->getY();
	//	if(yp==NULL){
	//		cout<<"完成编码"<<""<<endl;
	//		break;
	//	}
	//	memcpy (pPicIn->img.plane[0], yp, iDataLen);
	//	memcpy (pPicIn->img.plane[1], yuv->getU(), iDataLen / 4);
	//	memcpy (pPicIn->img.plane[2], yuv->getV(), iDataLen / 4);
	//	if (uiComponent <= 1000)
	//	{
	//		pPicIn->i_pts = uiComponent + g_uiPTSFactor * 1000;
	//		encode (pX264Handle, pPicIn, pPicOut);
	//	}
	//	else
	//	{
	//		//* 将缓存的数据取出
	//		int iResult = encode (pX264Handle, NULL, pPicOut);
	//		if (0 == iResult)
	//		{
	//			//break; //* 取空,跳出
	//			uiComponent = 0;
	//			++g_uiPTSFactor;
	//			/* {{ 这个解决不了取空缓冲区,再压缩无B帧的问题
	//			x264_encoder_reconfig(pX264Handle, pX264Param);
	//			x264_encoder_intra_refresh(pX264Handle);
	//			//* }} */ 
	//		}
	//	}
	//	//* 将编码数据写入文件.
	//	for (int i = 0; i < iNal; ++i)
	//	{
	//		fwrite (pNals[i].p_payload, 1, pNals[i].i_payload, pFile);
	//	} 	//} 
	////* 清除图像区域
	//x264_picture_clean (pPicIn);
	//x264_picture_clean (pPicOut);
	////* 关闭编码器句柄
	//x264_encoder_close (pX264Handle);
	//pX264Handle = NULL;
	//delete pPicIn;
	//pPicIn = NULL;
	//delete pPicOut;
	//pPicOut = NULL;
	//delete pX264Param;
	//pX264Param = NULL;
	//delete[]data;
	//data = NULL;
	int i;
	i=10;
	i++;
	i++;
	i++;

	return 0;
}
//void f(){
//	Yuv420 *v = new Yuv420(176,144,2001,"akiyo_qcif.yuv");
//	int i = 0;
//	int len = 0;
//	const long l_ysize = v->getSizePreY();
//	const long l_usize = v->getSizePreU();
//	const long l_vsize =  v->getSizePreV();
//	char* d = (char*)malloc(v->getSizePreU());
//	memset(d,0xff,v->getSizePreU());
//	FILE *f = fopen("test3.yuv","wb+");
//	for(;i<25;i++){
//		char* yp = v->getY();
//		if(yp==NULL)
//			break;
//		fwrite(yp,1,l_ysize,f);
//		fwrite(v->getU(),1,l_usize,f);
//		fwrite(v->getV(),1,l_vsize,f);
//		//if(i%10==0){
//			//cout<<"i======"<<i<<endl;
//		//}
//
//	}
//	fflush(f);
//	fclose(f);
//	free(d);
//}
int main(int argc,char* argv){
	main2(2,NULL);
	/*cout<<"seraphim\n\nseraphim"<<endl;
	int i;

	f();
	cin>>i;*/
	return 0;
}