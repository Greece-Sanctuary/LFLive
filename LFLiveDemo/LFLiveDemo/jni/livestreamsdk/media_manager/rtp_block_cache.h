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

#include <deque>
#include <vector>
#include "fragment/rtp_block.h"
#include "avformat/sdp.h"
#include "streamid.h"
#include "util/port.h"

namespace media_manager
{
    class MediaManagerRTPInterface;

    class DLLEXPORT RTPCircularCache
    {
    public:
        RTPCircularCache(StreamId_Ext& stream_id);

        int32_t set_manager(MediaManagerRTPInterface*);

        virtual uint32_t set_sample_rate(uint32_t sample_rate);
        virtual uint32_t set_max_duration_ms(uint32_t max_duration);
        virtual uint32_t set_max_size(uint32_t max_size);

        virtual int32_t set_rtp(const avformat::RTP_FIXED_HEADER*, uint16_t len, int32_t& status);
        virtual int32_t empty_count();

        virtual avformat::RTP_FIXED_HEADER* get_by_seq(uint16_t seq, uint16_t& len, int32_t& status_code, bool return_next_valid_packet = false);
        virtual avformat::RTP_FIXED_HEADER* get_latest(uint16_t& len, int32_t& status_code);
        virtual avformat::RTP_FIXED_HEADER* get_next_by_seq(uint16_t seq, uint16_t& len, int32_t& status_code);

        virtual uint16_t size();

        uint32_t get_ssrc();

    protected:
        void _set_push_active();
        void _reset();
        uint32_t _adjust();

        int _fill_in(const avformat::RTP_FIXED_HEADER*, uint16_t);

        void _push_back(const avformat::RTP_FIXED_HEADER*, uint16_t);

        StreamId_Ext _stream_id;
        MediaManagerRTPInterface* _media_manager;

        uint32_t _max_duration;
        uint32_t _sample_rate;

        uint32_t _ssrc;
        avformat::RTPAVType _av_type;
        avformat::RTPMediaType _media_type;

        uint16_t _max_size;
        uint16_t _lastest_set_seq;

        time_t _push_active;

        std::deque<fragment::RTPBlock> _circular_cache;
    };


    class DLLEXPORT RTPMediaCache
    {
    public:
        RTPMediaCache(StreamId_Ext& stream_id);

        int32_t set_manager(MediaManagerRTPInterface*);

        int32_t set_sdp(std::string& sdp);
        int32_t set_sdp(const char* sdp, int32_t len);
        //        int32_t set_sdp(avformat::SdpInfo* sdp, bool malloc_new = false);

        avformat::SdpInfo* get_sdp();

        int32_t set_rtp(const avformat::RTP_FIXED_HEADER* rtp, uint16_t len, int32_t& status);

        RTPCircularCache* get_cache_by_ssrc(uint32_t ssrc);
        RTPCircularCache* get_cache_by_media(avformat::RTPMediaType);
        RTPCircularCache* get_cache_by_codec(avformat::RTPAVType);

        RTPCircularCache* get_audio_cache();
        RTPCircularCache* get_video_cache();

        void adjust_cache_size();

    protected:
        int32_t _reset_cache();


    public:
        StreamId_Ext _stream_id;
        avformat::SdpInfo* _sdp;

        RTPCircularCache* _audio_cache;
        RTPCircularCache* _video_cache;

        MediaManagerRTPInterface* _media_manager;
    };
}
