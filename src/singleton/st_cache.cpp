#include <singleton/st_cache.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/gui/gui.h>

SINGLETON_cache* G_cache = nullptr;

std::vector<std::pair<DtoTextureType, Texture2D*>> SINGLETON_cache::get_object(){
    return this->object;
}

Texture2D* SINGLETON_cache::get_by_texture_type_object(DtoTextureType search){
    for(int i = 0;i < this->get_object().size();i++){
        if(this->get_object()[i].first == search){
            return this->get_object()[i].second;
        }
    }

    return nullptr;
}

void SINGLETON_cache::set_object(std::vector<std::pair<DtoTextureType, Texture2D*>> value){
    this->object = value;
}