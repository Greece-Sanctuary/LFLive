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

#include "proto_define.h"
#include "util/data_buffer.h"

// @return:
//      -1 error
//      0 succ
int encode_u2r_req_state(const u2r_req_state *body, avutil::DataBuffer *obuf);

// @return:
//      -1 error
//      0  succ
//      N  need more bytes
int decode_u2r_rsp_state(u2r_rsp_state *rsp, const avutil::DataBuffer *ibuf);

// @return:
//      -1 error
//      0 succ
int encode_u2r_streaming(const u2r_streaming *body, avutil::DataBuffer *obuf);

// @return:
//      -1 error
//      0 succ
int encode_u2r_req_state_v2(const u2r_req_state_v2 *body, avutil::DataBuffer *obuf);

// @return:
//      -1 error
//      0  succ
//      N  need more bytes
int decode_u2r_rsp_state_v2(u2r_rsp_state_v2 *rsp, const avutil::DataBuffer *ibuf);

// @return:
//      -1 error
//      0 succ
int encode_u2r_streaming_v2(const u2r_streaming_v2 *body, avutil::DataBuffer *obuf);

int decode_u2r_streaming(avutil::DataBuffer * ibuf);
