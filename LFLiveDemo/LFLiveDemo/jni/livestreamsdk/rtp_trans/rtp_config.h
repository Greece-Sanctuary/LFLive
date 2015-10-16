#ifndef RTP_CONFIG_HEADER
#define RTP_CONFIG_HEADER
#include "stdint.h"
#include <string.h>

#define MAX_INTERVAL  1000
#define PKT_INTERVAL_INCREASE_STEP 100

#define NACK_LIST_MAX_SIZE 250
#define NACK_PKT_MAX_AGE 450
#define SR_RR_INERVAL 5000
#define NACK_PROCESS_INERVAL 10
#define RTT_INERVAL 10
#define RTP_SESSION_TIMEOUT 10000
#define RTP_CNAME "laifeng.com"
#define MAX_NACK_BITRATE 1 << 23
#define ENABLE_SUGGEST_PKT_INTERVAL 0
#define ENABLE_INNER_JETTERBUF 0
#define MAX_RECONNECT_COUNT 3

class RTPTransConfig 
{
private:
    bool inited;
    char _module_name[32];

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
    bool enable_suggest_pkt_interval;
    bool enable_inner_jetterbuf;
    int     max_reconnect_count;
public:
    RTPTransConfig() {
        inited = false;
        set_module_name("rtp_trans");
        set_default_config();
    }
    virtual ~RTPTransConfig() {

    }
    RTPTransConfig& operator=(const RTPTransConfig& rhv) {
        memmove((void*)this, (void*)&rhv, sizeof(RTPTransConfig));
        return *this;
    }
    virtual void set_default_config() {
        max_nack_bandwidth_limit = MAX_NACK_BITRATE;
        nack_interval = NACK_PROCESS_INERVAL;
        max_nacklst_size = NACK_LIST_MAX_SIZE;
        max_packet_age = NACK_PKT_MAX_AGE;
        sr_rr_interval = SR_RR_INERVAL;
        rtt_detect_interval = RTT_INERVAL;
        session_timeout = RTP_SESSION_TIMEOUT;
        enable_suggest_pkt_interval = ENABLE_SUGGEST_PKT_INTERVAL;
        enable_inner_jetterbuf = ENABLE_INNER_JETTERBUF;
        max_reconnect_count = MAX_RECONNECT_COUNT;
    }

    virtual bool reload() const {
        return true;
    }

    void set_module_name(const char *module_name) {
        memset(_module_name, 0, sizeof(_module_name));
        strcat(_module_name, module_name);
    }

    virtual const char* module_name() const {
        return _module_name;
    }
    virtual void dump_config() const {

    }
};
#endif
