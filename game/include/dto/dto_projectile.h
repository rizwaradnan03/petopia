#ifndef DTO_PROJECTILE_H
#define DTO_PROJECTILE_H

#include <dto/dto_texture.h>

struct DtoProjectileValue {
    Texture texture;
    int damage;
};

struct DtoProjectileAcceleration {
    float acceleration_x;
    float acceleration_y;
    float target_x;
    float target_y;

    bool rev_x;
    bool rev_y;
};

#endif