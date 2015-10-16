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
#include "avformat/sdp.h"
#include <list>
#include <map>
#include <set>
#include "util/port.h"
//#include "rtp_trans/rtp_config.h"

namespace live_stream_sdk
{
    enum TRANS_STATE
    {
        TRANS_OPEN,
        TRANS_TIMEOUT,
        TRANS_REFUSE,
        TRANS_DESTROY
    };


    class DLLEXPORT MediaInfo
    {
    public:
        int32_t clock_rate;
        int32_t bit_rate;
        uint16_t port;
        uint32_t ssrc;
        avformat::RTPAVType payload_type;
        avformat::RTPTransport transport;

        virtual avformat::rtp_media_info* generate_rtp_media_info();
        avformat::RTPMediaType get_media_type();
    };

    class DLLEXPORT H264MediaInfo : public MediaInfo
    {
    public:
        virtual avformat::rtp_media_info* generate_rtp_media_info();

        uint8_t* sps;
        uint32_t sps_len;
        uint8_t* pps;
        uint32_t pps_len;
    };

    class DLLEXPORT AACMediaInfo : public MediaInfo
    {
    public:
        uint8_t audioObjectType;
        uint8_t channels;

        virtual avformat::rtp_media_info* generate_rtp_media_info();
    };

    class DLLEXPORT SessionDescription
    {
    public:
        int start_time;
        int end_time;
        std::string receiver_ip;
        std::string stream_id;
        std::list<MediaInfo*> media_list;

        avformat::SdpInfo* generate_sdp_session_level();
        void parse_sdp_info(avformat::SdpInfo* sdpinfo);
    };

    class DLLEXPORT SenderReport
    {
    public:
        uint32_t  frac_lost_packet_count;
        uint32_t total_lost_packet_count;
        uint32_t rtt_ms;
        uint32_t effect_bitrate;
        float packet_lost_rate;
    };

    class DLLEXPORT ReceiverReport
    {
    public:
        uint32_t  frac_lost_packet_count;
        uint32_t total_lost_packet_count;
        uint32_t rtt_ms;
        uint32_t effect_bitrate;
        float packet_lost_rate;
    };

    class NetworkInfo
    {
    public:
        uint32_t max_nack_bandwidth_limit;
        uint32_t nack_interval;
        //receiver
        uint32_t max_nacklst_size;
        uint32_t max_packet_age;
        uint32_t sr_rr_interval;
        uint32_t rtt_detect_interval;
        uint32_t session_timeout;

        int32_t max_buffer_duration_ms;
        uint16_t rtp_port;
    };

    class DLLEXPORT QualityInfo{
        std::map<float,std::string> _level_map;
        std::set<float> _levels;
    public:
        std::string& get_quality_level(float percent);
        void add_level_info(float percent,std::string& decription);
	std::string& get_empty_string();
    protected:
	std::string quality_level;
    };

    typedef void(*OnReceiveHandle_t)(uint8_t* RTPPacket, uint16_t len, void *userdata);

    typedef void(*OnState_t)(int32_t state_no, uint8_t* detailr_str, int32_t len, void *userdata);

    typedef void(*OnSdpHandle_t)(SessionDescription *description, void *userdata);

}
