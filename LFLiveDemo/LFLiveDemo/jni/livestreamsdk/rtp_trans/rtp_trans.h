/*
* Author: gaosiyu@youku.com, hechao@youku.com
*/

#ifndef __RTP_TRANS_
#define __RTP_TRANS_

#include <string>
#include <map>
//#include <hash_map>
#include "avformat/rtp.h"
#include "avformat/rtcp.h"
#include "rtp_session.h"
#include "streamid.h"

#include "util/sdk_thread.h"


enum RTPTransMode
{
    SENDER_TRANS_MODE,
    RECEIVER_TRANS_MODE
};


class RTPTransConfig;
class RTPSession;
class RTPTransManager;
class RTPTrans
{
public:

    RTPTrans(std::string trans_name, StreamId_Ext sid, RTPTransManager *manager, RTPTransMode mode, RTPTransConfig *config = NULL)
        :_name(trans_name), _manager(manager), _sid(sid), _mode(mode), _config(config)
    {
        if (config == NULL)
            init_trans_config();
        livesdk_mutex_init(&_mutex, NULL);
        _is_alive = true;
    }

    //        virtual ~RTPtrans(){}

public:
    virtual void on_handle_rtp(const avformat::RTP_FIXED_HEADER *pkt, uint32_t pkt_len);
    virtual void on_handle_rtcp(avformat::RTCPPacketInformation *rtcpPacketInformation);
    virtual void on_timer();
    virtual void destroy();
    bool is_alive();

    std::string get_name() const { return _name; }
    const StreamId_Ext &get_sid() const { return _sid; }


    uint64_t get_send_video_pkt_interval();
    uint64_t get_send_audio_pkt_interval();


    uint32_t get_video_frac_lost_packet_count();
    uint32_t get_audio_frac_lost_packet_count();
    uint32_t get_video_total_lost_packet_count();
    uint32_t get_audio_total_lost_packet_count();
    uint32_t get_video_rtt_ms();
    uint32_t get_audio_rtt_ms();
    uint32_t get_video_effect_bitrate();
    uint32_t get_audio_effect_bitrate();
    float    get_video_packet_lost_rate();
    float    get_audio_packet_lost_rate();

protected:
    void _lock();
    void _unlock();
    virtual int send_rtp(uint32_t ssrc, uint16_t seq);
    virtual int send_rtcp(uint32_t ssrc, const avformat::RtcpPacket *pkt);
    virtual void close_session(RTPSession *session);
    RTPSession *get_video_session();
    RTPSession *get_audio_session();
    void init_trans_config();

private:
    friend class RTPSession;
    std::string _name;
    RTPTransManager * _manager;
    StreamId_Ext _sid;

    live_stream_sdk::livesdk_mutex_t _mutex;

protected:
    std::map<uint32_t, RTPSession *> _sessions;
    RTPTransMode _mode;
    RTPTransConfig *_config;
    bool _is_alive;
};

#endif

