#ifndef LAPI_CREATE_STREAM_H
#define LAPI_CREATE_STREAM_H

#include "lapi/lapi.h"
#include "util/json_stream.h"
#include "streamid.h"

namespace live_stream_sdk {
    class DLLEXPORT LapiCreateStream : public LiveAPI 
    {
    public:
        enum ERROR_CODE
        {
            Success = 0,
            Failed = 1,
            InvalidParam = 2,
            StreamTimeout = 3,
            InternalServerError = 4,
            InvalidToken = 5
        };
        LapiCreateStream();
        std::string build_url(const std::string& app_id, const std::string& stream_type, const std::string& res, const std::string& rt,
            const std::string& stream_format, const std::string& nt, const std::string& token, int32_t p2p,const std::string& ns_us_addr,
            const std::string& ns_src,int32_t& status);
    
        int32_t request(const std::string&  app_id, const std::string& stream_type, const std::string& res,const std::string& rt,
            const std::string& stream_format, const std::string& nt, const std::string& token, int32_t p2p,const std::string& ns_us_addr,
            const std::string& ns_src);
        virtual int32_t parse_response();

        StreamId_Ext & get_stream_id();
        std::string& get_upload_url_token();
        ERROR_CODE get_error_code();
        //std::string error_code_str(ERROR_CODE);

    protected:
        rapidjson::Document _doc;
        std::string _request_url;
        StreamId_Ext _stream_id;
        std::string _get_upload_url_token;
        ERROR_CODE _error_code;
    };
}
#endif
