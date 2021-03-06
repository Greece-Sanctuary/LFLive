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

namespace avcodec
{
    uint8_t aac_get_samplingFrequencyIndex(uint32_t samplerate);

    class AACConfig
    {
    public:
        AACConfig();
        AACConfig(uint8_t*);

        uint8_t set_audioObjectType(uint8_t audioObjectType);
        uint8_t set_samplingFrequencyIndex(uint8_t samplingFrequencyIndex);
        uint8_t set_channelConfig(uint8_t channels);

        uint8_t get_audioObjectType();
        uint8_t get_samplingFrequencyIndex();
        uint8_t get_channelConfig();

        uint8_t audioSpecificConfig[2];
    };
}
