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

namespace fragment
{
    class AbstractBlock
    {
    public:
        virtual uint32_t get_timestamp() = 0;
        virtual uint32_t get_seq() = 0;
    };
}
