#ifndef NAMESPACE_ENTITY_H
#define NAMESPACE_ENTITY_H

#include <config/c_pch.h>
#include <dto/dto_texture.h>
#include <dto/dto_effect.h>
#include <engine/e_variant.h>

namespace entity {
    extern std::vector<std::pair<std::string, DtoTextureType>> list;
    DtoTextureType* get_texture_type_by_name(const std::string& name);

    extern std::vector<std::pair<DtoTextureType, std::vector<DtoTextureType>>> guns; 
    std::pair<DtoTextureType*, std::vector<DtoTextureType*>> get_gun_by_texture_type(DtoTextureType& tex);

    extern std::vector<std::pair<DtoTextureType, std::vector<DtoEffectType>>> projectiles;
    std::pair<DtoTextureType*, std::vector<DtoEffectType*>> get_projectile_by_dto_texture_type(DtoTextureType& tex);
};

#endif