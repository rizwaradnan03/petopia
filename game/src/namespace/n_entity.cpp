#include <namespace/n_entity.h>

namespace entity {
    std::vector<std::pair<std::string, DtoTextureType>> list = {
        std::make_pair("BLOCK_DIRT", DtoTextureType::BLOCK_DIRT),
        std::make_pair("BLOCK_SAND", DtoTextureType::BLOCK_SAND),
        std::make_pair("BLOCK_STONE", DtoTextureType::BLOCK_STONE)
    };

    DtoTextureType* get_texture_type_by_name(const std::string& name){
        DtoTextureType* ret = nullptr;
        for(int i = 0;i < list.size();i++){
            if(list[i].first == name){
                return &list[i].second;
            }
        }

        return ret;
    }

    std::vector<std::pair<DtoTextureType, std::vector<DtoEffectType>>> projectiles = {
        std::make_pair(DtoTextureType::IRON_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        
        std::make_pair(DtoTextureType::ARROW_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        std::make_pair(DtoTextureType::ARROW_FLAME, std::vector<DtoEffectType>{DtoEffectType::DAMAGE, DtoEffectType::BURN}),
        std::make_pair(DtoTextureType::ARROW_POISON, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        
        std::make_pair(DtoTextureType::DART_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        std::make_pair(DtoTextureType::DART_SLEEP, std::vector<DtoEffectType>{DtoEffectType::SLEEP}),
    };

    // std::vector<VariantType> get_projectile_by_dto_texture_type(DtoTextureType& tex){
    //     for(int i = 0;i < projectiles.size();i++){
    //         DtoTextureType nm = std::get<DtoTextureType>(projectiles[0][1]);

    //         if(nm == tex){
    //             return projectiles[i];
    //         }
    //     }
        
    //     return {};
    // }
};