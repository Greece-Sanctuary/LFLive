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

#include "upload_sdk.h"
#include "util/port.h"
#include "lup_sche/flv_lup_sche.h"

namespace avutil
{
    class DataBuffer;
}

namespace live_stream_sdk
{
    class DLLEXPORT FLVUploadSDK : public UploadSDK
    {
    public:

        enum SDKState
        {
            SDKConstruct = 1,
//            SDKCreateStream,
            SDKGetUploadUrl,
            SDKUploadSche,
            SDKConnected,
            SDKSentReq,
            SDKRecvRsp,
            SDKSentHeader,
            SDKSendingTag,
            SDKStop,
        };

        FLVUploadSDK();
        int32_t Init(const std::string& app_id, StreamId_Ext& stream_id, const std::string& token);

        //LapiGetUploadUrl* GetUploadUrl(int32_t& status, StreamId_Ext streamid, const std::string& app_id, const std::string& token);
        //virtual int32_t UploadSchedule(int32_t& status, std::string& url);

        int32_t ConnectAndHandShake();
        int32_t SendFLVHeader(uint8_t* header, uint32_t len);
        int32_t SendFLVTag(uint8_t* tag, uint32_t len);
        int32_t Close();

        uint16_t get_receiver_port();

        // the following functions are using for debug.
        virtual int32_t UploadSchedule(StreamId_Ext streamid, const std::string& app_id, const std::string& token);

        int32_t set_receiver_ip(std::string& ip);
        int32_t set_receiver_port(uint16_t port);
        int32_t set_stream_id(StreamId_Ext& id);
        int32_t set_upload_token(std::string& token);

        int32_t set_state(SDKState);

    protected:

        int32_t _connect_receiver();
        int32_t _send_req();
        int32_t _recv_rsp();
        int32_t _send_data(uint8_t* data, uint32_t len);


        SDKState _state;

        uint16_t _receiver_tcp_port;

        int _socket;

        avutil::DataBuffer* _buffer;

        uint8_t* _temp_buf;

        int32_t _sent_tag_count;

        FLVLupSche* _flv_lup_sche;
    };
}
