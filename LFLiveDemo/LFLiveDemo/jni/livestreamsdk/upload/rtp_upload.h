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
#include "avformat/sdp.h"
#include "sdk/sdk_interface.h"
#include "media_manager/media_manager_rtp_interface.h"
#include "util/sdk_thread.h"
#include "rtp_trans/rtp_trans_ext.h"
#include "network/udp.h"
#include "util/data_buffer.h"
#include "lup_sche/rtp_lup_sche.h"

#include <list>

//#define SEQ_DUMP
//#define RTP_TEST

namespace live_stream_sdk
{
    class DLLEXPORT RTPUploadSDK : public UploadSDK
    {
    public:
        /************************************************************************/
        /*                        public interface                              */
        /************************************************************************/
        RTPUploadSDK(bool debug_media = false);
        ~RTPUploadSDK();

        int32_t Init(const std::string& app_id, StreamId_Ext& stream_id, const std::string& token);

        int32_t SetSessionDescription(SessionDescription* description);
        int32_t SetNetworkInfo(NetworkInfo* info);
        int32_t SetQualityInfo(QualityInfo* info);
        int32_t SetRTPTransConfig(RTPTransConfig *config);
        std::string & GetQuality();
        int32_t SendRTP(uint8_t* RTPPacket, uint16_t len);
        int32_t Stop();
        void SetUserAgent(const std::string & user_agent);
        void SetUserData(void *user_data);
        /************************************************************************/
        /*                        event interface                               */
        /************************************************************************/
        int32_t RegisterOnState(OnState_t handle);
        /************************************************************************/
        /*                        statistics interface                          */
        /************************************************************************/
        SenderReport *get_sender_report();
        /************************************************************************/
        /*                        private interface                             */
        /************************************************************************/

        int32_t SetState(uint16_t);
        uint16_t GetState();
        int32_t set_receiver_ip(const std::string&);
        int32_t set_sdp_url(const std::string&);
        int32_t set_upload_token(const std::string&);
        
        int32_t set_receiver_udp_port(uint16_t);
        
        
        SenderReport* GetSenderReport(uint32_t ssrc);
        ReceiverReport* GetReceiverReport(uint32_t ssrc);

        enum SDKState
        {
            SDKConstruct = 1,
            SDKGetUploadUrl,
            SDKLupSche,
            SDKSentSDP,
            SDKSentRequest,
            SDKRecvAck,
            SDKSendingRTP,
            SDKReconnecting,
            SDKStop,
        };

    protected:
        static void state_callback(int32_t state_no, uint8_t* detailr_str, int32_t len, void *userdata);
        static void* _upload_thread(void* argv);
        void _state_callback(int32_t state_no, uint8_t* detailr_str, int32_t len, void *userdata);
        void _rtp_loop();
        void _send_rtp();

        int32_t _setup_channel(SessionDescription* description);
        int32_t _send_sdp(std::string& sdp_str);
        int32_t _send_upload_request();

        void _on_recv_packet(avutil::DataBuffer* buffer);
        void _on_recv_rtp_packet(avutil::DataBuffer* buffer);
        void _on_recv_rtcp_packet(avutil::DataBuffer* buffer);

        SDKState _state;

        uint16_t _receiver_udp_port;

        avformat::SdpInfo* _sdp;
        media_manager::RTPMediaCache* _rtp_media_cache;

        livesdk_thread_t _send_thread;
        livesdk_mutex_t _lock;

        rtp_trans::RTPTransExt* _rtp_trans;

        //for debug media mode
        std::vector<avnetwork::SimpleUDPChannel*> _channel_vec;

        avnetwork::SimpleUDPChannel *_audio_rtp_channel;
        avnetwork::SimpleUDPChannel *_audio_rtcp_channel;
        avnetwork::SimpleUDPChannel *_video_rtp_channel;
        avnetwork::SimpleUDPChannel *_video_rtcp_channel;

        //for normal mode
        avnetwork::SimpleUDPChannel *_channel;

        bool _debug_media;
        avutil::DataBuffer* _buffer;
        
        NetworkInfo* _network_info;
        QualityInfo *_quality_info;
        std::string _user_agent;
        std::string _sdp_url;
        std::string _upload_token;
        OnState_t _on_state;
        void *_user_data;
        RTPLupSche* _rtp_lup_sche;
        RTPTransConfig *_config;
        int _reconnect_count_remain;
        SenderReport _sender_report;
    };
}
