#ifndef SINGLETON_CACHE_H
#define SINGLETON_CACHE_H

#include <config/c_pch.h>
#include <dto/dto_texture.h>

class Body;
class Gui;

class SINGLETON_cache {
    public:
        SINGLETON_cache();

        std::vector<std::pair<DtoTextureType, Texture>> get_object();
        Texture get_by_texture_type_object(DtoTextureType search);
        void set_object(std::vector<std::pair<DtoTextureType, Texture>> value);

        std::vector<Body*> get_world_object_by_id(std::string id);
        std::vector<Gui*> get_gui_object_by_id(std::string id);

        void init_texture();

    private:
        std::vector<std::pair<DtoTextureType, Texture>> object;
};

extern SINGLETON_cache* G_cache;

#endif