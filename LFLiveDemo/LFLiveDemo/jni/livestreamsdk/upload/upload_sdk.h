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
#include "streamid.h"
#include "lup_sche/lup_sche.h"
#include "lapi/lapi_create_stream.h"
#include "lapi/lapi_get_upload_url.h"
#include "sdk/sdk_interface.h"


namespace live_stream_sdk
{
    class DLLEXPORT UploadSDK
    {
    public:
        UploadSDK();
        ~UploadSDK();

        virtual int32_t get_upload_url(const std::string& app_id, StreamId_Ext& stream_id, const std::string& token);
        virtual int32_t upload_schedule(const std::string& url, int32_t& status);

        LapiGetUploadUrl* lapi_get_upload_url();
        LupSche* lup_sche();

        std::string& get_receiver_ip();
        const char* get_receiver_ip_char();

        StreamId_Ext get_stream_id();

    protected:
        std::string _receiver_ip;
        std::string _upload_token;
        StreamId_Ext _stream_id;

        int32_t _app_id;
        LupSche* _sche;

        std::string _lup_sche_url;

        LapiGetUploadUrl *_lapi_getuploadurl;
        LapiCreateStream *_lapi_createstream;
    };


}
