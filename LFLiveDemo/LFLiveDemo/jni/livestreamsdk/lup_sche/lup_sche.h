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

#include "util/json_stream.h"
#include "streamid.h"
#include <string>

namespace live_stream_sdk
{
    class LupSche
    {
    public:
        struct LupScheStatus
        {
        enum LupScheStatus_
        {
            Success = 0,
            ConnectError = -1,
            HTTPError = -2,
            DocError = -3,
            ParseResponseError = -4,
        } _val;
        LupScheStatus() { }
        LupScheStatus(int val) : _val(static_cast<LupScheStatus_>(val)) { }
        LupScheStatus(LupScheStatus_ val) : _val(val) { }
        LupScheStatus(const LupScheStatus& rhv) : _val(rhv._val) { }
        operator int() { return static_cast<int>(_val); }
        operator LupScheStatus_() { return _val; }
        };

        LupSche();
        void init(std::string portal_ip, int portal_port, StreamId_Ext streamid,std::string token,std::string app_id );

        int request(std::string url);
        virtual int parse_response();

        std::string get_token();
        StreamId_Ext get_streamid();
        std::string get_stream_format();

        std::string get_uploader_ip();

        void set_user_agent(const std::string& user_agent);
    protected:
        rapidjson::Document _doc;
        std::string _response;
        std::string _token;
        StreamId_Ext _stream_id;
        std::string _uploader_ip;

        std::string _portal_ip;
        uint16_t _portal_port;

        std::string _user_agent;

        //for createstream only
        std::string _app_id;
        std::string _stream_type;
        std::string _res;
        std::string _rt;
        std::string _stream_format;
        std::string _nt;
        //optional
        int _p2p;
        std::string _ns_us_addr;
        std::string _ns_src;
    };


}
