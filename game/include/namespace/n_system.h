#ifndef NAMESPACE_SYSTEM_H
#define NAMESPACE_SYSTEM_H

#include <config/c_pch.h>

namespace sys {
    std::pair<int, int> get_screen_resolution();
    int get_resolution_width();
    int get_resolution_height();

    std::pair<int, int> get_half_resolution();
    int get_half_width();
    int get_half_height();
};

#endif