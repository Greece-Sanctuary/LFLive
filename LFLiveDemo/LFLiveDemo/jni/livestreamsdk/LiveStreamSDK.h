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

#include "util/log.h"
#include "upload/rtp_upload.h"
#include "upload/flv_upload.h"

namespace live_stream_sdk
{
    RTPUploadSDK* create_rtp_upload_instance();
}
