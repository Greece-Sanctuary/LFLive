/**
* @file
* @brief
* @author   gaosiyu
* <pre><b>copyright: Youku</b></pre>
* <pre><b>email: </b>gaosiyu@youku.com</pre>
* <pre><b>company: </b>http://www.youku.com</pre>
* <pre><b>All rights reserved.</b></pre>
* @date 2015/09/16
* @see
*/
#ifndef JETTER_BUFFER_H
#define JETTER_BUFFER_H

#include <set>
#include "../util/sdk_thread.h"
#include "fragment/rtp_block.h"

using namespace std;

namespace live_stream_sdk {
    class RTPPacketMoreThan {
    public:
        bool operator() (const fragment::RTPBlock* rtpblock,
            const fragment::RTPBlock* pre_rtpblock) const {
            return (rtpblock->get_seq() != pre_rtpblock->get_seq()) &&
                static_cast<uint16_t>(pre_rtpblock->get_seq() - rtpblock->get_seq()) < 0x8000;
        }
    };
    typedef std::set<fragment::RTPBlock *, RTPPacketMoreThan> RTPPACKET_QUEUE;

    class JitterBuffer {
    private:

        uint32_t _buffer_duration;
        uint16_t _jitter_buffer_size;
        uint32_t _time_base;

        RTPPACKET_QUEUE _pkt_queue;
        //RTPPACKET_QUEUE::iterator _pkt_queue_jitter_it;
        fragment::RTPBlock *_pkt_queue_jitter_block;
        uint32_t _first_ts;
        int64_t _first_clock_ts;
        uint16_t _jitter_buf_size;
        bool _is_first;
        bool _is_ready;
        livesdk_mutex_t _lock;
    public:
        JitterBuffer();
        ~JitterBuffer() {
            _pkt_queue.clear();
        }
        void SetRTPPacket(fragment::RTPBlock *rtpblock);
        fragment::RTPBlock * GetRTPPacket(int& got);
        void setBufferDuration(uint32_t buffer_duration) { _buffer_duration = buffer_duration; }
        void setTimeBase(uint32_t time_base) { _time_base = time_base; }
        void setJitterBufferSize(uint16_t size) { _jitter_buffer_size = size; }
    };

}
#endif
