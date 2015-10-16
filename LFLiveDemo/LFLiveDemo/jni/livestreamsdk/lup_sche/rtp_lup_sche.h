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

#include "lup_sche.h"

namespace live_stream_sdk
{
    class RTPLupSche : public LupSche
    {
    public:
        virtual int parse_response();
        std::string& get_sdp_url();
        uint16_t get_uploader_udp_port();

    protected:
        std::string _sdp_url;
        uint16_t _uploader_udp_port;
    };
}
