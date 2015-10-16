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
#include <stdint.h>

#ifdef WIN32
#include <Windows.h>
#else
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>

#ifndef INVALID_SOCKET 
#define INVALID_SOCKET -1
#endif
#ifndef SOCKET_ERROR 
#define SOCKET_ERROR -1
#endif

#define closesocket(fd) close(fd)

#define WSANOTINITIALISED  EPROTONOSUPPORT
#endif


#include "network_channel.h"
#include "util/data_buffer.h"


#define MAX_UDP_PKT_SIZE 2048

namespace avnetwork
{
    int udp_init();

    class SimpleUDPChannel : public BaseChannel
    {
    public:
        SimpleUDPChannel();
        virtual int init(int socket, struct sockaddr_in& addr);
        virtual int send_data(const char* data, uint32_t len);
        virtual int receive_data(char* data, uint32_t max_len);
        virtual int send_data(avutil::DataBuffer* buf);
        virtual int receive_data(avutil::DataBuffer* buf, uint32_t max_len);
        virtual int get_sock_fd() { return _socket; }
        virtual ~SimpleUDPChannel();

    protected:
        int _socket;
        struct sockaddr_in _addr;
    };

    class ServerUDPChannel : public SimpleUDPChannel
    {
    public:
        ServerUDPChannel();
        virtual int init(int socket, struct sockaddr_in& addr);
        virtual ~ServerUDPChannel();
    };

    
}
