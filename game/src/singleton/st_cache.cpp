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


    Image arroDefaultImg = LoadImage("./storage/sprites/CPC.png");
    if (arroDefaultImg.data == nullptr) {
        std::cout << "Gagal load image!" << std::endl;
    }
    
    Texture arroDefaultTx = LoadTextureFromImage(arroDefaultImg);
    UnloadImage(arroDefaultImg);
    
    DtoTextureType arroDefaultTyp = DtoTextureType::ARROW_DEFAULT;
    txt.push_back(std::make_pair(arroDefaultTyp, arroDefaultTx));

    
    Image arroFlameImg = LoadImage("./storage/sprites/CPC.png");
    if (arroFlameImg.data == nullptr) {
        std::cout << "Gagal load image!" << std::endl;
    }
    
    Texture arroFlameTx = LoadTextureFromImage(arroFlameImg);
    UnloadImage(arroFlameImg);
    
    DtoTextureType arroFlameTyp = DtoTextureType::ARROW_FLAME;
    txt.push_back(std::make_pair(arroFlameTyp, arroFlameTx));

    
    Image arrowPoisonImg = LoadImage("./storage/sprites/CPC.png");
    if (arrowPoisonImg.data == nullptr) {
        std::cout << "Gagal load image!" << std::endl;
    }
    
    Texture arrowPoisonTx = LoadTextureFromImage(arrowPoisonImg);
    UnloadImage(arrowPoisonImg);
    
    DtoTextureType arrowPoisonTyp = DtoTextureType::ARROW_POISON;
    txt.push_back(std::make_pair(arrowPoisonTyp, arrowPoisonTx));

    this->set_object(txt);
}