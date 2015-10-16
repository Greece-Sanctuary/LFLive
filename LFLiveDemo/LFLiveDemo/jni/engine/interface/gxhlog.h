#ifndef GXHLOG_H_
#define GXHLOG_H_


#ifdef __cplusplus
#define EXTERNC extern "C"
EXTERNC{
#else
#define EXTERNC
#endif

#ifdef _WIN32
#define GXHLOG_API extern "C" __declspec(dllexport)
#else
#define GXHLOG_API __attribute__ ((__visibility__("default")))
#endif

/*#ifdef  __cplusplus    
extern "C" {    
#endif */ 
#define MAX_GXH_LOG_NUM		5
//#define LOG_FILE		"ipc_log.txt"
GXHLOG_API void LogInit(int type);
GXHLOG_API void LogOut(char *format,void *data);
GXHLOG_API void LogClose();
GXHLOG_API void LogTime(char *cTime);
GXHLOG_API void LogTS();
GXHLOG_API void LogTE(char *format, int base);
//
//GXHLOG_API  int64_t IGetCurrentTime(int dt);
//
GXHLOG_API void ITAB(void *fp, char *format, int tidx);

#ifdef  __cplusplus    
}    
#endif 

#endif
