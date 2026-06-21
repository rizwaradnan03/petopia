#ifndef NAMESPACE_ENTITY_H
#define NAMESPACE_ENTITY_H

#include <dto/dto_texture.h>

namespace entity {
    extern std::vector<std::pair<std::string, DtoTextureType>> list;

    DtoTextureType* get_texture_type_by_name(const std::string& name);
};

#endif