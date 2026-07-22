#ifndef ENGINE_VARIANT_H
#define ENGINE_VARIANT_H

#include <config/c_pch.h>

class OTHER_projectile;

using VariantType = std::variant<float, int, uint8_t, uint16_t, uint32_t, uint64_t, std::string, Texture>;

using VariantParticle = std::variant<OTHER_projectile*>;

#endif