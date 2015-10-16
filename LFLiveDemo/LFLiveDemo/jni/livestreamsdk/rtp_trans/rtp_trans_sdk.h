#pragma once

#include "rtp_trans.h"

class RTPTransSDK : RTPTrans
{
public:
    void on_recv_rtp(const uint8_t* data, uint16_t len);
    void on_recv_rtcp(const uint8_t* data, uint16_t len);
    void on_recv_packet(const uint8_t* data, uint16_t len);
};
