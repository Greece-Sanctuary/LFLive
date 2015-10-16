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
#include <string>

#define USER_AGENT "Youku Live Stream SDK/1.0"

class CHttpClient
{
public:
    CHttpClient(void);
    ~CHttpClient(void);

public:

    int Put(const std::string & strUrl, const std::string & strPut, const std::string & userAgent, std::string & strResponse, int& httpRspCode);

    int Post(const std::string & strUrl, const std::string & strPost, const std::string & userAgent, std::string & strResponse, int& httpRspCode);

    int Get(const std::string & strUrl, const std::string & userAgent, std::string & strResponse, int& httpRspCode);

    void SetDebug(bool bDebug);
    void SetUserAgent(const std::string userAgent);

private:
    bool _bDebug;
    std::string _user_agent;
};
