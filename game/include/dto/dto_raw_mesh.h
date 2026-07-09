#ifndef DTO_RAW_MESH_H
#define DTO_RAW_MESH_H

#include <config/c_pch.h>

struct DtoCartesian {
    float x;
    float y;
    float w;
    float h;
};

struct DtoRawMesh { // raw mesh
    DtoCartesian cartesian;
    std::vector<std::pair<std::string, std::string>> rawTextures;
};

#endif