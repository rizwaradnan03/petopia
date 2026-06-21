#ifndef DTO_CURL_H
#define DTO_CURL_H

#include <config/c_pch.h>

enum CurlMethodEnum {
    GET,
    POST
};

struct DtoCurl {
    std::string uri;
    std::string* data;
    CurlMethodEnum method;
};

#endif