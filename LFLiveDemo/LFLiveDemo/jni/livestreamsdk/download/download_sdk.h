#pragma once

#include "sdk/sdk_interface.h"
#include "streamid.h"
#include "lpl_sche/lpl_sche.h"
#include "lapi/lapi_get_playlist.h"

namespace live_stream_sdk 
{
    class DLLEXPORT DownloadSDK 
    {
    public:
        DownloadSDK();
        ~DownloadSDK();
        //const std::string& app_id,const std::string& player_type,const std::string& token
        virtual int32_t download_schedule(StreamId_Ext& stream_id, std::string play_sche_url);

    protected:
        std::string _download_token;
        std::string _user_agent;
        StreamId_Ext _stream_id;

        LplSche _sche;
    };
}
