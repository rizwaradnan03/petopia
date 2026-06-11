#ifndef DTO_COLLIDER_H
#define DTO_COLLIDER_H

#include <config/c_pch.h>

struct DtoCollider {
    uint8_t layer;
    std::vector<uint8_t> mask;
};

#endif