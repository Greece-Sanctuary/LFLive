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

#include <string>
#include "streamid.h"
#include "util/json_stream.h"
#include <util/port.h>

namespace live_stream_sdk
{
    class DLLEXPORT LplSche
    {
    public:
        LplSche();
        int request(std::string& url);
        int parse_response();

        std::string get_token();
        StreamId_Ext get_streamid();
        std::string get_player_type();

        std::string get_download_ip();
        std::string get_sdp_url();

        uint16_t get_download_udp_port();
        void set_user_agent(const std::string& user_agent) {
            _user_agent = user_agent;
        }
        ~LplSche();

    protected:
        rapidjson::Document _doc;
        std::string _response;
        std::string _token;
        std::string _player_type;
        StreamId_Ext _stream_id;
        std::string _download_ip;

        std::string _app_id;
        std::string _sdp_url;
        uint16_t _download_udp_port;
        std::string _user_agent;
    };
}
