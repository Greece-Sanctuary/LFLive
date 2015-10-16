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

#include "lapi.h"
#include "util/json_stream.h"
#include "streamid.h"

namespace live_stream_sdk
{
    class LapiGetPlayList : public LiveAPI {
    public:
        enum LapiGetPlayListStatus
        {
            LapiGetPlayListBuildUrlFailed = -11,
            LapiGetPlayListDocError = -12,
            LapiGetPlayListParseFailed = -13
        };

        enum ERROR_CODE
        {
            Success = 0,
            Failed = 1,
            InvalidParam = 2,
            StreamTimeout = 3,
            InternalServerError = 4,
            InvalidToken = 5
        };

        LapiGetPlayList();
        std::string build_url(StreamId_Ext& stream_id,const std::string& app_id,const std::string& player_type,const std::string& token,int32_t& status);
        int32_t request(StreamId_Ext& stream_id, const std::string& app_id, const std::string& player_type,const std::string& token);
        int32_t parse_response();
        std::string get_player_sche_url();
        ERROR_CODE get_error_code();
        //std::string error_code_str(ERROR_CODE);

    protected:
        rapidjson::Document _doc;
        std::string _request_url;
        std::string _player_url;
        ERROR_CODE _error_code;
    };
}
