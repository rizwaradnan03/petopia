#include <singleton/st_cache.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/gui/gui.h>

SINGLETON_cache* G_cache = nullptr;

SINGLETON_cache::SINGLETON_cache(){
    this->init_texture();
    this->init_item();
}

std::vector<std::pair<DtoTextureType, Texture>> SINGLETON_cache::get_object(){
    return this->object;
}

void SINGLETON_cache::set_object(std::vector<std::pair<DtoTextureType, Texture>> value){
    this->object = value;
}

void SINGLETON_cache::set_push_object(std::pair<DtoTextureType, Texture> value){
    this->object.push_back(value);
}

std::vector<std::pair<DtoTextureType, UNI_item*>> SINGLETON_cache::get_item(){
    return this->item;
}

void SINGLETON_cache::set_item(std::vector<std::pair<DtoTextureType, UNI_item*>> value){
    this->item = value;
}

void SINGLETON_cache::set_push_item(std::pair<DtoTextureType, UNI_item*> value){
    this->item.push_back(value);
}

Texture SINGLETON_cache::get_object_by_texture_type(const DtoTextureType& search){
    for(int i = 0;i < this->get_object().size();i++){
        if(this->get_object()[i].first == search){
            return this->get_object()[i].second;
        }
    }

    return Texture{};
}

UNI_item* SINGLETON_cache::get_item_by_texture_type(const DtoTextureType& search){
    for(int i = 0;i < this->get_item().size();i++){
        if(this->get_item()[i].first == search){
            return this->get_item()[i].second;
        }
    }
    
    return nullptr;
}

void SINGLETON_cache::init_texture(){
    std::vector<std::pair<DtoTextureType, std::string>> initialize = {
        std::make_pair(DtoTextureType::BLOCK_DIRT, "./storage/sprites/CPC.png"),
    };

    for(int i = 0;i < initialize.size();i++){
        std::pair<DtoTextureType, std::string> it = initialize[i];
    
        Image img = LoadImage(it.second.c_str());
        if (img.data == nullptr) {
            std::cout << "Gagal load image!" << std::endl;
        }
        
        Texture tx = LoadTextureFromImage(img);
        UnloadImage(img);
        
        this->set_push_object(std::make_pair(it.first, tx));
    }
}

void SINGLETON_cache::init_item(){
    this->init_gun();
    this->init_projectile();
}

void SINGLETON_cache::init_gun(){
    std::vector<std::pair<DtoTextureType, std::vector<VariantType>>> initialize = {
        std::make_pair(DtoTextureType::GUN_PISTOL, std::vector<VariantType>{0.0f, 0.0f, 10.0f, 4.0f, get_object_by_texture_type(DtoTextureType::GUN_PISTOL)})
    };

    for(int i = 0;i < initialize.size();i++){
        std::pair<DtoTextureType, std::vector<VariantType>> it = initialize[i];

        float xVal = std::get<float>(it.second[0]);
        float yVal = std::get<float>(it.second[1]);
        float wVal = std::get<float>(it.second[2]);
        float hVal = std::get<float>(it.second[3]);
        Texture txVal = std::get<Texture>(it.second[4]);

        MeshInit mGun;
        mGun.x = xVal;
        mGun.y = yVal;
        mGun.w = wVal;
        mGun.h = hVal;
        mGun.texture = txVal;

        DtoPoleset* pGun;
        pGun->x = 0;
        pGun->y = 0;

        DtoItemAmount aGun;
        aGun.amount = 1;

        UNI_item* uGun = new UNI_item(mGun, pGun, aGun);
        this->set_push_item(std::make_pair(it.first, uGun));
    }
}

void SINGLETON_cache::init_projectile(){

}