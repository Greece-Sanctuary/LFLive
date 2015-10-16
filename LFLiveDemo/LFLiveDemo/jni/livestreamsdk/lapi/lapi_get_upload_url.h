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
#include "lapi.h"
#include "streamid.h"
#include "util/port.h"

namespace live_stream_sdk
{
    class DLLEXPORT LapiGetUploadUrl : public LiveAPI
    {
    public:
        struct LapiGetUploadUrlStatus
        {
        enum LapiGetUploadUrlStatus_
        {
            OK = 0,
            ConnectError = -1,
            HTTPError = -2,
            LapiGetUploadUrlBuildUrlFailed = -11,
            LapiGetUploadUrlDocError = -12,
            LapiGetUploadUrlParseFailed = -13
        } _val;
        LapiGetUploadUrlStatus() { }
        LapiGetUploadUrlStatus(int val) : _val(static_cast<LapiGetUploadUrlStatus_>(val)) { }
        LapiGetUploadUrlStatus(LapiGetUploadUrlStatus_ val) : _val(val) { }
        LapiGetUploadUrlStatus(const LapiGetUploadUrlStatus& rhv) : _val(rhv._val) { }
        operator int() { return static_cast<int>(_val); }
        operator LapiGetUploadUrlStatus_() { return _val; }
        };

        struct ERROR_CODE
        {
        enum ERROR_CODE_
        {
            Success = 0,
            Failed = 1,
            InvalidParam = 2,
            StreamTimeout = 3,
            InternalServerError = 4,
            InvalidToken = 5
        } _val;
        ERROR_CODE() { }
        ERROR_CODE(int val) : _val(static_cast<ERROR_CODE_>(val)) { }
        ERROR_CODE(ERROR_CODE_ val) : _val(val) { }
        ERROR_CODE(const ERROR_CODE& rhv) : _val(rhv._val) { }
//        operator int() { return static_cast<int>(_val); }
        operator ERROR_CODE_() { return _val; }
        };

        LapiGetUploadUrl();
        std::string build_url(const std::string& app_id, StreamId_Ext& stream_id,const std::string& token, int32_t& status);
        int32_t build_and_request(const std::string& app_id, StreamId_Ext& stream_id, const std::string& token);
        virtual int32_t parse_response();

        int32_t get_version();
        std::string& get_upload_url();
        ERROR_CODE get_error_code();
        std::string error_code_str(ERROR_CODE);

    protected:
        rapidjson::Document _doc;
        int32_t _version;
        std::string _request_url;
        std::string _upload_url;
        ERROR_CODE _error_code;
    };
}
