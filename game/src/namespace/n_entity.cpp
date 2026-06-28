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

    std::vector<std::pair<DtoTextureType, std::vector<DtoTextureType>>> guns = {
        std::make_pair(DtoTextureType::GUN_PISTOL, std::vector<DtoTextureType>{DtoTextureType::IRON_DEFAULT}),
        std::make_pair(DtoTextureType::GUN_BOW, std::vector<DtoTextureType>{DtoTextureType::ARROW_DEFAULT, DtoTextureType::ARROW_FLAME, DtoTextureType::ARROW_POISON}),        
        std::make_pair(DtoTextureType::GUN_DART, std::vector<DtoTextureType>{DtoTextureType::DART_DEFAULT, DtoTextureType::DART_SLEEP}),
    };

    std::pair<DtoTextureType*, std::vector<DtoTextureType*>> get_gun_by_texture_type(DtoTextureType& tex){
        for(int i = 0;i < guns.size();i++){
            if(guns[i].first == tex){
                std::vector<DtoTextureType*> txt;
                for(int j = 0;j < guns[i].second.size();j++){
                    txt.push_back(&guns[i].second[j]);
                }

                return std::make_pair(&guns[i].first, txt);
            }
        }

        return std::make_pair(nullptr, std::vector<DtoTextureType*>{nullptr});
    } 

    std::vector<std::pair<DtoTextureType, std::vector<DtoEffectType>>> projectiles = {
        std::make_pair(DtoTextureType::IRON_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        
        std::make_pair(DtoTextureType::ARROW_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        std::make_pair(DtoTextureType::ARROW_FLAME, std::vector<DtoEffectType>{DtoEffectType::DAMAGE, DtoEffectType::BURN}),
        std::make_pair(DtoTextureType::ARROW_POISON, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        
        std::make_pair(DtoTextureType::DART_DEFAULT, std::vector<DtoEffectType>{DtoEffectType::DAMAGE}),
        std::make_pair(DtoTextureType::DART_SLEEP, std::vector<DtoEffectType>{DtoEffectType::SLEEP}),
    };

    std::pair<DtoTextureType*, std::vector<DtoEffectType*>> get_projectile_by_dto_texture_type(DtoTextureType& tex){
        for(int i = 0;i < projectiles.size();i++){
            if(projectiles[i].first == tex){
                std::vector<DtoEffectType*> eff;
                for(int j = 0;j < projectiles[i].second.size();j++){
                    eff.push_back(&projectiles[i].second[j]);
                }

                return std::make_pair(&projectiles[i].first, eff);
            }
        }

        return std::make_pair(nullptr, std::vector<DtoEffectType*>{nullptr});
    }
};