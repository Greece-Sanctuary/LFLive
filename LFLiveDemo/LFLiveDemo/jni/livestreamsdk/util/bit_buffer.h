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
#include <stddef.h>
#include "util/port.h"

namespace avutil
{
    class DLLEXPORT BitBuffer
    {
    public:
        BitBuffer(int max);
        int append_uint(uint32_t len, uint32_t value);
        uint8_t* get_buffer();
        int get_len();
        ~BitBuffer();

    protected:
        uint8_t* _ptr;
        size_t _max_size;
        size_t _pos;
    };
}
