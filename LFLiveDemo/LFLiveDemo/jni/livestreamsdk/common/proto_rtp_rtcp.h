#pragma once

#include "proto_define_rtp.h"
#include "util/data_buffer.h"
#include "streamid.h"
#include <stdint.h>

// rtp uploader <----> rtp receiver
int32_t encode_rtp_u2r_req_state(const rtp_u2r_req_state *body, avutil::DataBuffer *obuf);

int32_t decode_rtp_u2r_rsp_state(rtp_u2r_rsp_state *rsp , avutil::DataBuffer *in_buf);

int32_t encode_rtp_u2r_packet(StreamId_Ext& stream_id,const uint8_t* body, uint16_t len, avutil::DataBuffer *obuf);

int32_t encode_rtcp_u2r_packet(StreamId_Ext& stream_id,const uint8_t* body, uint16_t len, avutil::DataBuffer *obuf);

int32_t decode_rtcp_u2r_packet(StreamId_Ext& streamid, avutil::DataBuffer *in_buf);


// rtp downloader <----> rtp player
int32_t encode_rtp_d2p_req_state(const rtp_d2p_req_state* body, avutil::DataBuffer *obuf);

int32_t decode_rtp_d2p_rsp_state(rtp_d2p_rsp_state* rsp, avutil::DataBuffer *in_buf);

int32_t encode_rtcp_d2p_packet(StreamId_Ext& stream_id,const uint8_t* body, uint16_t len, avutil::DataBuffer *obuf);

int32_t decode_rtcp_d2p_packet(StreamId_Ext& stream_id, avutil::DataBuffer *in_buf);

int32_t decode_rtp_d2p_packet(StreamId_Ext& stream_id, avutil::DataBuffer *in_buf);
