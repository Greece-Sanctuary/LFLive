/*
* Author: hechao@youku.com
*
*/
#ifndef __RTP_MEDIA_MANAGER_HELPER_
#define __RTP_MEDIA_MANAGER_HELPER_

//#include "rtp_trans_manager.h"
#include "avformat/sdp.h"
#include "media_manager/media_manager_rtp_interface.h"
#include "streamid.h"

class RTPMMHelper
{
public:
    virtual ~RTPMMHelper(){};

    virtual int32_t set_rtp(StreamId_Ext& stream_id, avformat::RTP_FIXED_HEADER *rtp, uint16_t len, int32_t& status_code) = 0;

    virtual const avformat::RTP_FIXED_HEADER* get_rtp_by_ssrc_seq(StreamId_Ext& stream_id, uint32_t ssrc,
        uint16_t seq, uint16_t &len, int32_t& status_code, bool return_next_valid_packet = false) = 0;

    virtual const avformat::RTP_FIXED_HEADER* get_rtp_by_mediatype_seq(StreamId_Ext& stream_id, avformat::RTPMediaType type,
        uint16_t seq, uint16_t &len, int32_t& status_code, bool return_next_valid_packet = false) = 0;

    virtual int32_t set_sdp_char(StreamId_Ext& stream_id, char* sdp, int32_t len, int32_t& status_code) = 0;
    virtual const char* get_sdp_char(StreamId_Ext& stream_id, int32_t& len, int32_t& status_code) = 0;

    virtual int32_t set_sdp_str(StreamId_Ext& stream_id, const std::string& sdp, int32_t& status_code) = 0;
    virtual std::string get_sdp_str(StreamId_Ext& stream_id, int32_t& status_code) = 0;
};

class RTPMediaManagerHelper : public RTPMMHelper
{
public:
    RTPMediaManagerHelper();
    ~RTPMediaManagerHelper();

public:
    virtual int32_t set_rtp(StreamId_Ext& stream_id, avformat::RTP_FIXED_HEADER *rtp, uint16_t len, int32_t& status_code);

    virtual const avformat::RTP_FIXED_HEADER* get_rtp_by_ssrc_seq(StreamId_Ext& stream_id, uint32_t ssrc,
        uint16_t seq, uint16_t &len, int32_t& status_code, bool return_next_valid_packet);

    virtual const avformat::RTP_FIXED_HEADER* get_rtp_by_mediatype_seq(StreamId_Ext& stream_id, avformat::RTPMediaType type,
        uint16_t seq, uint16_t &len, int32_t& status_code, bool return_next_valid_packet);

    virtual int32_t set_sdp_char(StreamId_Ext& stream_id, char* sdp, int32_t len, int32_t& status_code);
    virtual const char* get_sdp_char(StreamId_Ext& stream_id, int32_t& len, int32_t& status_code);

    virtual int32_t set_sdp_str(StreamId_Ext& stream_id, const std::string& sdp, int32_t& status_code);
    virtual std::string get_sdp_str(StreamId_Ext& stream_id, int32_t& status_code);

protected:
    media_manager::MediaManagerRTPInterface* _media_manager;
};

#endif

