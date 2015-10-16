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
#include <netinet/in.h>
#endif


namespace avnetwork
{
    class BaseChannel
    {
    public:
        virtual int init(int socket, struct sockaddr_in& remote_addr) = 0;
        virtual int send_data(const char* data, uint32_t len) = 0;
        virtual int receive_data(char* data, uint32_t max_len) = 0;
        virtual ~BaseChannel(){};
    };

}
