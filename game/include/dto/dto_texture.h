#ifndef DTO_TEXTURE_H
#define DTO_TEXTURE_H

#include <config/c_pch.h>

enum DtoTextureType {
    BLOCK_DIRT,
    BLOCK_SAND,
    BLOCK_STONE,

    // GUN
    GUN_PISTOL,
    GUN_BOW,
    GUN_DART,

    // PROJECTILE
    IRON_DEFAULT,
    // ------------------------------------------
    ARROW_DEFAULT,
    ARROW_FLAME,
    ARROW_POISON,
    // ------------------------------------------
    DART_DEFAULT,
    DART_SLEEP
};

#endif