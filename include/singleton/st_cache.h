#ifndef SINGLETON_CACHE_H
#define SINGLETON_CACHE_H

#include <config/c_pch.h>
#include <dto/dto_texture.h>

class Body;
class Gui;

class SINGLETON_cache {
    public:
        std::vector<std::pair<DtoTextureType, Texture2D*>> get_object();
        Texture2D* get_by_texture_type_object(DtoTextureType search);
        void set_object(std::vector<std::pair<DtoTextureType, Texture2D*>> value);

        std::vector<Body*> get_world_object_by_id(std::string id);
        std::vector<Gui*> get_gui_object_by_id(std::string id);

    private:
        std::vector<std::pair<DtoTextureType, Texture2D*>> object;
};

extern SINGLETON_cache* G_cache;

#endif