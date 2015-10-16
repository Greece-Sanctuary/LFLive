#pragma once

#include "download_sdk.h"
#include "rtp_trans/rtp_trans.h"
//#include "avformat/rtp.h"
#include "fragment/rtp_block.h"

#include "util/sdk_thread.h"
#include "util/port.h"
#include "network/udp.h"
#include "util/data_buffer.h"
#include "rtp_trans/rtp_trans_ext.h"

#include "jetter_buffer.h"

//#define SEQ_DUMP

namespace live_stream_sdk {

    enum SDKState
    {
        SDKConstruct = 1,
        SDKInit,
        SDKLplSche,
        SDKReqSDP,
        SDKSentRequest,
        SDKRecvAck,
        SDKRecvingRTP,
        SDKStop,
    };

    class DLLEXPORT RTPDownloadSDK : public DownloadSDK
    {
    public:
        /************************************************************************/
        /*                        public interface                              */
        /************************************************************************/
        RTPDownloadSDK(bool debug_media);
        ~RTPDownloadSDK();
        void SetUserData(void *user_data);
        void SetupChannel(avformat::SdpInfo *sdpinfo);
        void SetUserAgent(const std::string& user_agent);
        void SetRTPTransConfig(RTPTransConfig *config);
        void SetServerInfo(const std::string& receiver_ip, const std::string& sdp_url, const std::string& token, uint16_t receiver_udp_port);
        virtual int32_t Init(StreamId_Ext stream_id, const std::string& app_id, const std::string& player_type, const std::string& token);
        void Close();
        /************************************************************************/
        /*                        event interface                               */
        /************************************************************************/
        void RegisterOnState(OnState_t state_callback);
        void RegisterOnSdp(OnSdpHandle_t sdp_callback);
        void RegisterOnRecv(OnReceiveHandle_t pkt_callback);
        /************************************************************************/
        /*                        statistics interface                          */
        /************************************************************************/
        ReceiverReport *get_receiver_report();
        /************************************************************************/
        /*                        private interface                             */
        /************************************************************************/
        void ProcessRtpPacket(uint8_t *data, uint16_t len);
        void ProcessRtcpPacket(uint8_t *data, uint16_t len);
        RTPTrans  * GetRTPTrans();
    private:
        int32_t _req_sdp();
        int32_t _send_udp_req();
        static void* _down_thread(void* argv);
        void rtp_loop();
    public:
        //for debug media mode
        avnetwork::SimpleUDPChannel *_audio_rtp_channel;
        avnetwork::SimpleUDPChannel *_audio_rtcp_channel;
        avnetwork::SimpleUDPChannel *_video_rtp_channel;
        avnetwork::SimpleUDPChannel *_video_rtcp_channel;
        //for normal mode
        avnetwork::SimpleUDPChannel *_channel;
    private:
        livesdk_thread_t _down_thread_handle;
        rtp_trans::RTPTransExt  *_trans;
        bool _debug_media;
        avutil::DataBuffer* _buffer;
        std::string _user_agent;
        SDKState _state;
        std::string _receiver_ip;
        std::string _sdp_url;
        std::string _token;
        uint16_t _receiver_udp_port;
        RTPTransConfig *_config;
        ReceiverReport _receiver_report;
        /************************************************************************/
        /* callback                                                             */
        /************************************************************************/
        OnReceiveHandle_t _pkt_callback;
        OnState_t _state_callback;
        OnSdpHandle_t _sdp_callback;
        void *_userdata;
        LapiGetPlayList _lapi;
    public:
        uint32_t _buffer_duration;
        JitterBuffer _audio_buffer;
        JitterBuffer _video_buffer;
    protected:
        uint16_t RecvRtpPacket(uint8_t* rtp_packet, uint16_t& len);
    };
}
