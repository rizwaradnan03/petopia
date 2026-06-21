#ifndef SINGLETON_SYSTEM_H
#define SINGLETON_SYSTEM_H

#include <config/c_pch.h>
#include <dto/dto_curl.h>
#include <namespace/n_callback.h>
#include <namespace/n_file.h>
#include <engine/e_variant.h>

class SINGLETON_system {
    public:
        SINGLETON_system();

        CURL* get_curl();
        void set_curl(CURL* value);

        std::vector<std::pair<std::string, VariantType>> get_fetch(DtoCurl curlDto);
        void set_post(DtoCurl curlDto);

    private:
        CURL* curl;
};

extern SINGLETON_system* G_system;

#endif