/*
* Author: hechao@youku.com
*
*/

#ifndef __RTP_TRANS_MANAGER_
#define __RTP_TRANS_MANAGER_

#include <stdint.h>
#include <deque>
#include <string>
#include <map>

#include "rtp_types.h"
#include "streamid.h"
#include "rtp_trans.h"
#include "avformat/sdp.h"
#include "avformat/rtp.h"
#include "rtp_media_manager_helper.h"

const int MAX_RTP_LEN = 10 * 1024;

struct RTPItem
{
    char buf[MAX_RTP_LEN];
    int len;
    rtp_type_t type;
    std::string key;
};

class RTPTransManager
{
    friend class RTPTrans;
public:
    RTPTransManager(RTPMMHelper *helper);
    ~RTPTransManager();

public:
    int open_receiver(std::string name, StreamId_Ext sid);
    int close_receiver(std::string name);

    int open_sender(std::string name, StreamId_Ext sid);
    int close_sender(std::string name);

    int _open(std::string name, StreamId_Ext sid, RTPTransMode mode);

    int put_rtp(std::string trans_name, StreamId_Ext sid, avformat::RTP_FIXED_HEADER *rtp, uint16_t len);
    int put_rtcp(std::string trans_name, StreamId_Ext sid, avformat::RTCPPacketInformation *rtcp);

    int put_sdp(StreamId_Ext sid, const avformat::SdpInfo *sdp);
    int get_sdp(StreamId_Ext sid, avformat::SdpInfo *sdp);

    /*
    * key, the returned data will be sent to
    * rtp_type: the returned data type: rtp or rtcp
    */
    int get_next_rtp(std::string &key, rtp_type_t &rtp_type, char *buf, int &len);

    void on_timer();

public:
    void writable_callback();


protected:
    void _send_rtp();
    void _send_rtcp();

private:
    RTPMMHelper *_mm_helper;
    std::deque<RTPItem>  _sender_rtp_queue;
    typedef std::map<std::string, RTPTrans*> TRANS_MAP;
    TRANS_MAP _trans_map;
};

#endif

