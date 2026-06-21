#ifndef NAMESPACE_CALLBACK_H
#define NAMESPACE_CALLBACK_H

#include <config/c_pch.h>

namespace callback {
    size_t write_curl(void* contents, size_t size, size_t nmemb, std::string* output);
};

#endif