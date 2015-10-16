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

#include <string>

#include <vector>

#include "../third_party/rapidjson/include/rapidjson/document.h"
#include "../third_party/rapidjson/include/rapidjson/reader.h"
#include "../third_party/rapidjson/include/rapidjson/writer.h"


namespace JSON_NS
{
    typedef std::string JsonErr;

    class JsonDecode
    {
    public:
        static rapidjson::Value& get_value(const char* m_name, rapidjson::Value& jobj)
        {
            if (m_name && jobj.IsObject() && jobj.HasMember(m_name)){
                if (!jobj[m_name].IsObject())
                    throw JsonErr("json wrong fomat object: ") + m_name;
                return jobj[m_name];
            }
            else
            {
                throw JsonErr("json has not a member of ") + m_name;
            }
        }

        static rapidjson::Value& get_array(const char* m_name, rapidjson::Value& jobj)
        {
            if (m_name && jobj.IsObject() && jobj.HasMember(m_name)){
                if (!jobj[m_name].IsArray())
                    throw JsonErr("json wrong fomat array: ") + m_name;
                return jobj[m_name];
            }
            else
            {
                throw JsonErr("json has not a member of ") + m_name;
            }
        }


        static std::string get_string(const char* m_name, rapidjson::Value& jobj)
        {
            if (m_name && jobj.IsObject() && jobj.HasMember(m_name)){
                if (jobj[m_name].IsString())
                {
                    return jobj[m_name].GetString();
                }
                else
                    throw JsonErr(m_name) + " is not a string";
            }
            else
                throw JsonErr("json has not a member of ") + m_name;
        }

        static std::string try_get_string(const char* m_name, rapidjson::Value& jobj)
        {
            if (m_name && jobj.IsObject() && jobj.HasMember(m_name)){
                if (jobj[m_name].IsString())
                {
                    return jobj[m_name].GetString();
                }
                else
                    return "";
            }
            else
                return "";
        }


        static uint32_t get_uint(const char* m_name, rapidjson::Value& jobj)
        {
            if (m_name && jobj.IsObject() && jobj.HasMember(m_name)){
                if (jobj[m_name].IsUint())
                {
                    return jobj[m_name].GetUint();
                }
                else
                    throw JsonErr(m_name) + " is not a uint";
            }
            else
                throw JsonErr("json has not a member of ") + m_name;
        }
    };

}
