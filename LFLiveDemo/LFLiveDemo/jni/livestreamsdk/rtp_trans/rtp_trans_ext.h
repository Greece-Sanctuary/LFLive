#pragma once

#include "rtp_trans.h"
#include "media_manager/rtp_block_cache.h"
#include "network/udp.h"
#include "util/data_buffer.h"

#include "../sdk/sdk_interface.h"
using namespace live_stream_sdk;


namespace rtp_trans
{
    class RTPTransExt : public RTPTrans
    {
    public:
        RTPTransExt(std::string trans_name, StreamId_Ext sid, RTPTransManager *manager, RTPTransMode mode, RTPTransConfig *config = NULL);

        int32_t set_channel(avnetwork::SimpleUDPChannel*);

        int32_t set_audio_rtp_channel(avnetwork::SimpleUDPChannel*);
        int32_t set_audio_rtcp_channel(avnetwork::SimpleUDPChannel*);

        int32_t set_video_rtp_channel(avnetwork::SimpleUDPChannel*);
        int32_t set_video_rtcp_channel(avnetwork::SimpleUDPChannel*);
        void set_rtp_cache(media_manager::RTPMediaCache* media_cache) { _media_cache = media_cache; }

        void RegisterOnState(OnState_t state_callback, void *userdata) {
            _state_callback = state_callback;
            _userdata = userdata;
        }

        bool set_debug_media(bool);
        void destroy();
        void reset();
    protected:
        media_manager::RTPMediaCache* _media_cache;
        
        virtual int send_rtp(uint32_t ssrc, uint16_t seq);
        virtual int send_rtcp(uint32_t ssrc, const avformat::RtcpPacket *pkt);

        void close_session(RTPSession *session);

        avnetwork::SimpleUDPChannel* _audio_rtp_channel;
        avnetwork::SimpleUDPChannel* _audio_rtcp_channel;

        avnetwork::SimpleUDPChannel* _video_rtp_channel;
        avnetwork::SimpleUDPChannel* _video_rtcp_channel;

        avnetwork::SimpleUDPChannel* _channel;

        bool _debug_media;

        avutil::DataBuffer* _buffer;

        OnState_t _state_callback;
        void *_userdata;

    };
}
