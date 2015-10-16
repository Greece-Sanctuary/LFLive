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

#include <stdio.h>

namespace avutil
{
    char* util_ip2str_no_r(unsigned int network_order_ip, char *str, size_t sz);

    const char * util_ip2str_no(unsigned int network_order_ip);

    unsigned long long net_util_htonll(unsigned long long val);

    unsigned long long net_util_ntohll(unsigned long long val);

    int sprintfcat(char *buffer, const char *format, ...);
}
