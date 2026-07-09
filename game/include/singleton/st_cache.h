#ifndef SINGLETON_CACHE_H
#define SINGLETON_CACHE_H

#include <config/c_pch.h>
#include <engine/e_variant.h>
#include <dto/dto_texture.h>
#include <namespace/n_entity.h>

class Body;
class Gui;
class UNI_item;

class SINGLETON_cache {
    public:
        SINGLETON_cache();

        std::vector<std::pair<DtoTextureType, Texture>> get_object();
        void set_object(std::vector<std::pair<DtoTextureType, Texture>> value);
        void set_push_object(std::pair<DtoTextureType, Texture> value);

        std::vector<std::pair<DtoTextureType, UNI_item*>> get_item();
        void set_item(std::vector<std::pair<DtoTextureType, UNI_item*>> value);
        void set_push_item(std::pair<DtoTextureType, UNI_item*> value);

        std::vector<Body*> get_world_object_by_id(std::string id);
        std::vector<Gui*> get_gui_object_by_id(std::string id);
        
        Texture get_object_by_texture_type(const DtoTextureType& search);
        UNI_item* get_item_by_texture_type(const DtoTextureType& search);

        std::vector<Texture> get_all_objects_with_the_similar_title(std::string title);

        void init_texture();
        void init_item();

        void init_gun();
        void init_projectile();

    private:
        std::vector<std::pair<DtoTextureType, Texture>> object; // pre defined object

        std::vector<std::pair<DtoTextureType, UNI_item*>> item; // defined items such a gun, item
};

extern SINGLETON_cache* G_cache;

#endif