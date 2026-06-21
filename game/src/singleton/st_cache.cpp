#include <singleton/st_cache.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/gui/gui.h>

SINGLETON_cache* G_cache = nullptr;

SINGLETON_cache::SINGLETON_cache(){
    this->init_texture();
}

std::vector<std::pair<DtoTextureType, Texture>> SINGLETON_cache::get_object(){
    return this->object;
}

Texture SINGLETON_cache::get_by_texture_type_object(DtoTextureType search){
    for(int i = 0;i < this->get_object().size();i++){
        if(this->get_object()[i].first == search){
            return this->get_object()[i].second;
        }
    }

    return Texture{};
}

void SINGLETON_cache::set_object(std::vector<std::pair<DtoTextureType, Texture>> value){
    this->object = value;
}

void SINGLETON_cache::init_texture(){
    std::vector<std::pair<DtoTextureType, Texture>> txt;
    
    Image blockDirtImg = LoadImage("./storage/sprites/CPC.png");
    if (blockDirtImg.data == nullptr) {
        std::cout << "Gagal load image!" << std::endl;
    }
    
    
    Texture blockDirtTx = LoadTextureFromImage(blockDirtImg);
    UnloadImage(blockDirtImg);
    
    DtoTextureType blockDirtTyp = DtoTextureType::BLOCK_DIRT;
    txt.push_back(std::make_pair(blockDirtTyp, blockDirtTx));

    this->set_object(txt);
}