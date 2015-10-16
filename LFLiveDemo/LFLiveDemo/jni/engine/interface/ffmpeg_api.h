//edited by gxh
#ifndef FFMPEG_API_H_
#define FFMPEG_API_H_

#ifdef __cplusplus
#define EXTERNC extern "C"
EXTERNC {
#else
#define EXTERNC
#endif
    
#ifdef _WIN32
#define FFAVCODEC_API extern "C" __declspec(dllexport)
#else
//extern "C"
#define FFAVCODEC_API EXTERNC __attribute__ ((__visibility__("default")))
#endif

#ifndef _WIN32
#define MAX_PATH        256
#endif
#define MUT_SIZE		1400//0
#define PARAMS_SIZE		4096
#define MAX_RTP_NUM		100
#define	MAX_BITS_BUF_SIZE	512000
#define H264_PLT            96
//
#define FPS				25
#define RDIP			"127.0.0.1"
#define	RDPORT0			19000
#define	RDPORT1			19001
#define OUTWIDTH		640//704
#define OUTHEIGHT		480//576
#define SPLIT_LEN		(1000*60000)//ms

enum CodecType
{
	kVideoEncRaw,		
	kVideoDecRaw,		
	kVideoEncStream,	
	kVideoDecStream,	
	kAudioEncRaw,		
	kAudioDecRaw,		
	kAudioEncStream,	
	kAudioDecStream,	
	kAVEnc,				
	kAVDec,				
	kAVEncStream,		
	kAVDecStream,		
};
enum CodecAVID
{
	kVideoH264,
	kVideoOpenH264,
	kVideoH265,
	kVideoVP8,
	kAudioAac,
	kAudioAacPlus,
};
enum PicType
{
	PIC_TYPE_AUTO = 0,        
	PIC_TYPE_IDR,           
	PIC_TYPE_I,             
	PIC_TYPE_P,             
	PIC_TYPE_BREF,            
	PIC_TYPE_B,             
	PIC_TYPE_KEYFRAME,   
};
#ifndef _WIN32__
FFAVCODEC_API
int FF_TEST_MAIN(int flag);
#endif

FFAVCODEC_API
int FF_FACTORY_CREATE(void** pHandle, int flag);
FFAVCODEC_API
void FF_FACTORY_DELETE(void* pHandle);
FFAVCODEC_API
int FF_WRITE_TAIL(void *hnd, int codec_flag);
///////////////////////////////////////////////////////////////////////////////////
FFAVCODEC_API
int FF_RTP_PACKAGE(char *inBuf , int size, char *outBuf, short *rtpSize);
FFAVCODEC_API int FF_RTP_UNPACKAGE(char *inBuf,short *rtpSize, int count, int rtpLen, char *outBuf, int *oSize);
FFAVCODEC_API 
int FF_AVCODEC_CREATE(void** pHandle);
FFAVCODEC_API 
int FF_AVCODEC_DELETE(void* pHandle);
FFAVCODEC_API 
int FF_CODEC_INIT(void *hnd, int codec_flag);
FFAVCODEC_API
int FF_CODEC_CODEDED(void *hnd, char * inBuf[3], int len, char *outBuf[3], int oLen, int *pic_type, int codec_flag);
//FFAVCODEC_API 
//void FF_CODEC_CLOSE(void *hnd);
FFAVCODEC_API
void FF_CODEC_SET_PARAMS(void *hnd, char *cParams);
#ifdef  __cplusplus
}
#endif

#endif
