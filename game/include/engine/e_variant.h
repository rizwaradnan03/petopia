#ifndef ENGINE_VARIANT_H
#define ENGINE_VARIANT_H

#include <config/c_pch.h>

using VariantType = std::variant<float, int, uint8_t, uint16_t, uint32_t, uint64_t, std::string, Texture>;

#endif