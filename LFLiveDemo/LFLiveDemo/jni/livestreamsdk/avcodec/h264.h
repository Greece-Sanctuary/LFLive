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

#include <stdint.h>
#include "util/port.h"

namespace avcodec
{
    /* Slice type */
#define X264_TYPE_AUTO          0x0000  /* Let x264 choose the right type */
#define X264_TYPE_IDR           0x0001
#define X264_TYPE_I             0x0002
#define X264_TYPE_P             0x0003
#define X264_TYPE_BREF          0x0004  /* Non-disposable B-frame */
#define X264_TYPE_B             0x0005
#define X264_TYPE_KEYFRAME      0x0006  /* IDR or I depending on b_open_gop option */
#define IS_X264_TYPE_I(x) ((x)==X264_TYPE_I || (x)==X264_TYPE_IDR)
#define IS_X264_TYPE_B(x) ((x)==X264_TYPE_B || (x)==X264_TYPE_BREF)

    typedef struct
    {
        int i_ref_idc;  /* nal_priority_e */
        int i_type;     /* nal_unit_type_e */
        int b_long_startcode;
        int i_first_mb; /* If this NAL is a slice, the index of the first MB in the slice. */
        int i_last_mb;  /* If this NAL is a slice, the index of the last MB in the slice. */

        /* Size of payload (including any padding) in bytes. */
        int     i_payload;
        /* If param->b_annexb is set, Annex-B bytestream with startcode.
        * Otherwise, startcode is replaced with a 4-byte size.
        * This size is the size used in mp4/similar muxing; it is equal to i_payload-4 */
        uint8_t *p_payload;

        /* Size of padding in bytes. */
        int i_padding;
    } x264_nal_t;

    DLLEXPORT uint8_t* create_h264_payload(x264_nal_t* x264_nal_list, x264_nal_t* sps_pps_nal_list, uint32_t nal_num, uint32_t& payload_len);

    const uint8_t *ff_avc_find_startcode(const uint8_t *p, const uint8_t *end);
}
