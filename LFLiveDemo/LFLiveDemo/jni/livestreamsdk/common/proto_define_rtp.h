#pragma once

#include <stdint.h>
#include "proto_define.h"

#define STREAM_ID_LEN 16

enum RTPProtoType
{
    PROTO_RTP = 0,
    PROTO_RTCP = 1,
    PROTO_RTP_STREAMID = 2,
    PROTO_RTCP_STREAMID = 3,
    PROTO_CMD = 255,
};

// rtp uploader <----> receiver
// CMD_RTP_U2R_REQ_STATE = 500,

#pragma pack(1)

typedef struct rtp_u2r_req_state
{
    uint32_t version;
    uint8_t streamid[STREAM_ID_LEN];
    uint64_t user_id;
    uint8_t token[32];
    uint8_t payload_type;
}rtp_u2r_req_state;


// CMD_RTP_U2R_RSP_STATE = 501,
typedef struct rtp_u2r_rsp_state
{
    uint32_t version;
    uint8_t streamid[STREAM_ID_LEN];
    uint16_t result;//0 success; 1 token invalid; 2 streamid invalid;
}rtp_u2r_rsp_state;

typedef struct rtp_u2r_stream_pkt_header {
    uint8_t streamid[STREAM_ID_LEN];
};

// rtp downloader <----> player
// CMD_RTP_D2P_REQ_STATE = 600,

typedef struct rtp_d2p_req_state
{
    uint32_t version;
    uint8_t streamid[STREAM_ID_LEN];
    uint8_t token[32];
    uint8_t payload_type;
    uint8_t useragent[128];
}rtp_d2p_req_state;

// CMD_RTP_D2P_RSP_STATE = 601,
typedef struct rtp_d2p_rsp_state
{
    uint32_t version;
    uint8_t streamid[STREAM_ID_LEN];
    uint16_t result; //0 success; 1 token invalid; 2 streamid invalid;
}rtp_d2p_rsp_state;

typedef struct rtp_d2p_stream_pkt_header {
    uint8_t streamid[STREAM_ID_LEN];
};

// rtp forward <----> forward
// CMD_RTP_F2F_REQ_STATE = 700,

typedef struct rtp_f2f_req_state
{
    uint32_t version;
    uint8_t streamid[STREAM_ID_LEN];
}rtp_f2f_req_state;
#pragma pack()
