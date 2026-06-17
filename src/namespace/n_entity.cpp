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
};