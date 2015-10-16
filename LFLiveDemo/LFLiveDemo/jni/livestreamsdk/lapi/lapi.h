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

#ifndef LAPI_H
#define LAPI_H
#include <string>
#include <stdint.h>
#include "util/port.h"

#define LAIFENG_API_HOST "lapi.xiu.youku.com"
#define LAIFENG_API_PORT 80

namespace live_stream_sdk
{
    class DLLEXPORT LiveAPI
    {
    public:
        struct LapiStatus
        {
            enum _LapiStatus
            {
                Success = 0,
                ConnectError = -1,
                HTTPError = -2
            };
        };

        LiveAPI();
        int32_t set_addr(std::string host_name, uint16_t port);
        int32_t set_useragent(std::string useragent);

        int32_t request(std::string url, int32_t& http_code, std::string& response);

        std::string get_response();

        virtual int32_t parse_response();

    protected:
        std::string _host_name;
        uint16_t _port;
        std::string _response;
        std::string _user_agent;
    };
}
#endif
