//edited by gxh
#ifndef AVENGAPI_H_
#define AVENGAPI_H_

#ifdef __cplusplus
#define EXTERNC extern "C"
EXTERNC {
#else
#define EXTERNC
#endif

#ifdef _WIN32
#define AVENG_API extern "C" __declspec(dllexport)
#else
#define AVENG_API __attribute__ ((__visibility__("default")))
#endif
    
    
enum AVGroupType{ kAudio = 1, kVideo = 2, kEncoder = 4, kDecoder = 8};
enum AVType{audio = 0,video }; 
enum DevType{ dev_cam = 0, dev_recoder, dev_player };
#if 1
struct AVGroup
{
	int GroupId;
	long long StreamId;//UUID
	//AVGroupType type;//1:video/2:audio/4:encoder/8:decoder/0:no defined
	int type;
	int VEChanId;
	int AEChanId;
	int VDChanId;
	int ADChanId;
	int CaptureId;
	//int RecoderId;
	//int PlayerId;
};
#endif
#if defined(__ANDROID__)
AVENG_API int IISetAndroidObj(void* jvm, void* context);
AVENG_API int IIClearAndroidObj();
#endif
AVENG_API int IIAVETestMain(void *wind0, void *wind1);
AVENG_API int IICreateAVObj(void** pHandle, int windNum, int extwin, char *devStr);
AVENG_API int IIDeleteAVObj(void* pHandle);
AVENG_API void IISetSndPktCallback(void *hnd, void *cb, void *obj);
//AVENG_API int IIStartPreview(void *hnd, void *wind, char *devName);
//AVENG_API int IIStartEncoder(void *hnd, void *wind, int captureID);
AVENG_API int IIStartVideo(void *hnd);
AVENG_API int IIStartAudio(void *hnd);
AVENG_API int IIStartVideoDecoder(void *hnd, int winIdx, void *extwind);
AVENG_API int IIStartAudioDecoder(void *hnd, char *devName);
AVENG_API int IIPlayVideo(void *hnd, void *data, int len, int channel);
AVENG_API int IIPlayAudio(void *hnd, void *data, int len, int channel);
//
AVENG_API int IIStartPreview(void *hnd, void *wind, char *devName);
AVENG_API int IIStartEncoder(void *hnd, void *wind, int captureID);
AVENG_API int IIAddExtWin(void *hnd, void *extwind);
AVENG_API int IIGetDevList(void *hnd, char **dev, int type);
AVENG_API int IISetDevList(void *hnd, int idx, int type);
//
AVENG_API int IIStartRecoderDev(void *hnd, char *devName);
AVENG_API int IIStartAudioEncoder(void *hnd, int recoderId);
AVENG_API int IIStartPlayerDev(void *hnd, char *devName);
AVENG_API int IIStartAudioDecoder2(void *hnd, int playerId);
AVENG_API void IIStartCast(void *hnd, int chanId, void *wind);
AVENG_API void IISetParams(void *hnd, char *cparams);
AVENG_API void IISetRawDataCallback(void *hnd, void *cb, void *obj);
AVENG_API int IIAddGroup(void *hnd, struct AVGroup *group);
AVENG_API int IIStopAVCodec(void *hnd, int groupId, long long streamId);
AVENG_API int IIFindGroupId(void *hnd, int type, long long streamId);
AVENG_API void IICloseAVEngine(void *hnd);
//
AVENG_API int IIICreateAVETestObj(void** pHandle);
AVENG_API int IIIDeleteAVETestObj(void* pHandle);
AVENG_API int IITStartAVCodec(void *hnd, long long streamId, void *wind, char *cparams, int EncOrDec);
AVENG_API int IITStopAVCodec(void *hnd, long long streamId, int EncOrDec);
#ifdef  __cplusplus    
}    
#endif 

#endif
