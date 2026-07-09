#ifndef DTO_SIGNATURE_MESH_H
#define DTO_SIGNATURE_MESH_H

#include <config/c_pch.h>
#include <dto/dto_texture.h>

struct MeshInit {
    float x;
    float y;
    float w;
    float h;

    // string on the first one stands for title
    std::vector<std::pair<std::string, std::vector<Texture>>> texture;
    std::pair<std::string, uint8_t> selected_texture;
    std::pair<float*, std::chrono::time_point<std::chrono::high_resolution_clock>*> force_time_limit = std::make_pair(nullptr, nullptr);
};

struct MeshPole {
    float x;
    float y;
};

#endif