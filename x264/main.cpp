#include<iostream>
extern"C"{
#include"stdint.h"
#include"x264.h"
};
#include"yuv420.h"
using namespace Seraphim;
using namespace std;

unsigned int g_uiPTSFactor = 0;
int iNal = 0;
x264_nal_t * pNals = NULL;
int encode (x264_t * pX264Handle, x264_picture_t * pPicIn, x264_picture_t * pPicOut)
{
	int iResult = 0;
	iResult =
		x264_encoder_encode (pX264Handle, &pNals, &iNal, pPicIn, pPicOut);

	if (0 == iResult)
	{
		std::cout << "编码成功,但被缓存了." << std::endl;
	}
	else if (iResult < 0)
	{
		std::cout << "编码出错" << std::endl;
	}
	else if (iResult > 0)
	{
		std::cout << "得到编码数据" << std::endl;
	}
	int iFrames = x264_encoder_delayed_frames (pX264Handle);
	std::cout << "当前编码器中缓存数据:" << iFrames << "帧\n";
	return iFrames;
}
/**
**/
x264_param_t* initParam(x264_param_t* param,int width,int height){
	x264_param_default (param);
	param->i_width = width;
	param->i_height = height;
	param->i_threads = X264_SYNC_LOOKAHEAD_AUTO;	//* 取空缓冲区继续使用不死锁的保证.//* video Properties
	param->i_frame_total = 0;	//* 编码总帧数.不知道用0.
	param->i_keyint_max = 10;
	param->i_bframe = 5;
	param->b_open_gop = 0;
	param->i_bframe_pyramid = 0;
	param->i_bframe_adaptive = X264_B_ADAPT_TRELLIS;
	param->b_annexb = 1;
	param->i_log_level = X264_LOG_NONE;
	param->rc.i_bitrate = 1024 * 10;	//* 码率(比特率,单位Kbps), muxing parameters
	param->i_fps_den = 1;	//* 帧率分母
	param->i_fps_num = 25;	//* 帧率分子
	param->i_timebase_den = param->i_fps_num;
	param->i_timebase_num = param->i_fps_den;
	return param;
};

int main(int argc,char** argv){
	int iResult = -1;
	x264_t * pX264Handle = NULL;
	x264_param_t * param = new x264_param_t;
	assert (param);
	initParam(param,176,144);
	Yuv420 yuv(176,144,0,"akiyo_qcif.yuv");
	x264_param_apply_profile (param, x264_profile_names[1]);
	pX264Handle = x264_encoder_open (param);
	iResult = x264_encoder_headers (pX264Handle, &pNals, &iNal);
	assert (iResult >= 0);
	iNal = 0;
	pNals = NULL;
	x264_picture_t * pPicIn = new x264_picture_t;
	x264_picture_t * pPicOut = new x264_picture_t;
	x264_picture_init (pPicOut);
	x264_picture_alloc (pPicIn, X264_CSP_I420, param->i_width,param->i_height);
	pPicIn->img.i_csp = X264_CSP_I420;
	pPicIn->img.i_plane = 3;
	FILE * pFile = fopen ("seraphim01.264", "wb");
	uint8_t* y= yuv.getY();
	while(y!=NULL){
		pPicIn->img.plane[0]=y;
		pPicIn->img.plane[1]=yuv.getU();
		pPicIn->img.plane[2]=yuv.getV();
		iResult =x264_encoder_encode (pX264Handle, &pNals, &iNal, pPicIn, pPicOut);
		if(iResult==0){
			cout<<"缓存当前帧"<<endl;
		}else if(iResult <0){
			cout<<"编码错误"<<endl;
			break;
		}else{
		//存储数据
			for (int i = 0; i < iNal; ++i)
			{
			fwrite (pNals[i].p_payload, 1, pNals[i].i_payload, pFile);
			} 
			cout<<"写入数据"<<endl;
			fflush(pFile);
		}
		y= yuv.getY();
	}
	fclose(pFile);
	int i ;
	cout<<"编码结束,按任意键退出"<<endl;
	cin>>i;
	return 0;
}