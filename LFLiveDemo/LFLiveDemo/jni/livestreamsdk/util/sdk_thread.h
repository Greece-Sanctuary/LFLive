/**
* @file
* @brief
* @author   songshenyi
* <pre><b>copyright: Youku</b></pre>
* <pre><b>email: </b>songshenyi@youku.com</pre>
* <pre><b>company: </b>http://www.youku.com</pre>
* <pre><b>All rights reserved.</b></pre>
* @date 2015/07/24
* @see
*/


#pragma once

#define PTHREAD 1

#if defined(PTHREAD)
#if defined(WIN32)
#include "..\third_party\pthreads\include\pthread.h"
#else
#include <pthread.h>
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h> 
#include <string.h>

#if defined(WIN32)
#include <windows.h>
#else
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#endif

namespace live_stream_sdk
{

#if defined(PTHREAD)

    typedef pthread_t livesdk_thread_t;
    typedef pthread_mutex_t livesdk_mutex_t;
    typedef pthread_cond_t livesdk_cond_t;

#define livesdk_thread_create	__livesdk_thread_create
#define livesdk_thread_join	__livesdk_thread_join
#define livesdk_thread_exit	pthread_exit
#define livesdk_mutex_init		pthread_mutex_init
#define livesdk_mutex_lock		pthread_mutex_lock
#define livesdk_mutex_unlock	pthread_mutex_unlock
#define livesdk_mutex_destroy	pthread_mutex_destroy
#define livesdk_cond_init		pthread_cond_init
#define livesdk_cond_signal	pthread_cond_signal
#define livesdk_cond_broadcast	pthread_cond_broadcast
#define livesdk_cond_wait		pthread_cond_wait
#define livesdk_cond_destroy	pthread_cond_destroy

    int __livesdk_thread_join(livesdk_thread_t thread, void **ptr);
    int __livesdk_thread_create(pthread_t *thread, pthread_attr_t *attr, void * (*routine)(void*), void *arg);


#else


typedef HANDLE livesdk_cond_t;
typedef HANDLE livesdk_mutex_t;
typedef HANDLE livesdk_thread_t;

#define livesdk_thread_create	WIN_thread_create
#define livesdk_thread_join	WIN_thread_join
#define livesdk_thread_exit(arg)
#define livesdk_mutex_init		WIN_mutex_init
#define livesdk_mutex_lock		WIN_mutex_lock
#define livesdk_mutex_unlock	WIN_mutex_unlock
#define livesdk_mutex_destroy	WIN_mutex_destroy
#define livesdk_cond_init		WIN_cond_init
#define livesdk_cond_signal	WIN_cond_signal
#define livesdk_cond_broadcast	WIN_cond_broadcast
#define livesdk_cond_wait		WIN_cond_wait
#define livesdk_cond_destroy	WIN_cond_destroy

int WIN_mutex_init(livesdk_mutex_t *m, void *attr_unused);
int WIN_mutex_lock(livesdk_mutex_t *mutex);
int WIN_mutex_unlock(livesdk_mutex_t *mutex);
int WIN_mutex_destroy(livesdk_mutex_t *mutex);
int WIN_thread_create(livesdk_thread_t *t, void *attr_unused, void *(*func)(void*), void *arg);
int WIN_thread_join(livesdk_thread_t thread, void **unused);
int WIN_cond_init(livesdk_cond_t *cond, void *attr_unused);
int WIN_cond_wait(livesdk_cond_t * cond, livesdk_mutex_t * mutex);
int WIN_cond_signal(livesdk_cond_t * cond);
int WIN_cond_broadcast(livesdk_cond_t * cond);
int WIN_cond_destroy(livesdk_cond_t * cond);

#endif

}
