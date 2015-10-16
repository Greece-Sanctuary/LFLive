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

#include "network_channel.h"

#ifdef WIN32

#include "stdint.h"
#include "windows.h"

#else
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif


#if defined(WIN32)
#define snprintf _snprintf
typedef int socklen_t;

#else

typedef int Socket;
#ifndef INVALID_SOCKET 
#define INVALID_SOCKET -1
#endif
#ifndef SOCKET_ERROR 
#define SOCKET_ERROR -1
#endif

#define closesocket(fd) close(fd)

#define WSANOTINITIALISED  EPROTONOSUPPORT

#endif

namespace avnetwork
{
    int tcp_init();

    class SimpleTCPChannel : public BaseChannel
    {
    public:
        SimpleTCPChannel();
        virtual int init(int socket, struct sockaddr_in& addr);
        virtual int send_data(const char* data, uint32_t len);
        virtual int receive_data(char* data, uint32_t max_len);

        virtual ~SimpleTCPChannel();

    protected:
        int _socket;
        struct sockaddr_in _addr;
    };
}
