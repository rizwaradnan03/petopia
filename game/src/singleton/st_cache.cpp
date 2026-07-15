#include <nodes/2d/body/body.h>
#include <nodes/2d/gui/gui.h>
#include <singleton/st_cache.h>
#include <source/particle/uni/u_item.h>

SINGLETON_cache *G_cache = nullptr;

SINGLETON_cache::SINGLETON_cache() {
  this->init_texture();
  this->init_item();
}

std::vector<std::pair<DtoTextureType, Texture>> SINGLETON_cache::get_object() {
  return this->object;
}

void SINGLETON_cache::set_object(
    std::vector<std::pair<DtoTextureType, Texture>> value) {
  this->object = value;
}

void SINGLETON_cache::set_push_object(
    std::pair<DtoTextureType, Texture> value) {
  this->object.push_back(value);
}

std::vector<std::pair<DtoTextureType, UNI_item *>> SINGLETON_cache::get_item() {
  return this->item;
}

void SINGLETON_cache::set_item(
    std::vector<std::pair<DtoTextureType, UNI_item *>> value) {
  this->item = value;
}

void SINGLETON_cache::set_push_item(
    std::pair<DtoTextureType, UNI_item *> value) {
  this->item.push_back(value);
}

Texture
SINGLETON_cache::get_object_by_texture_type(const DtoTextureType &search) {
  for (int i = 0; i < this->get_object().size(); i++) {
    if (this->get_object()[i].first == search) {
      return this->get_object()[i].second;
    }
  }

  return Texture{};
}

UNI_item *
SINGLETON_cache::get_item_by_texture_type(const DtoTextureType &search) {
  for (int i = 0; i < this->get_item().size(); i++) {
    if (this->get_item()[i].first == search) {
      return this->get_item()[i].second;
    }
  }

  return nullptr;
}

void SINGLETON_cache::init_texture() {
  std::vector<std::pair<DtoTextureType, std::string>> initialize = {
      std::make_pair(DtoTextureType::BODY_PLAYER,
                     "./storage/sprites/bakul-sate.png"),
      std::make_pair(DtoTextureType::BLOCK_DIRT, "./storage/sprites/CPC.png"),
      std::make_pair(DtoTextureType::BLOCK_SAND, "./storage/sprites/CPC.png"),
      std::make_pair(DtoTextureType::BLOCK_STONE, "./storage/sprites/CPC.png"),
  };

  for (int i = 0; i < initialize.size(); i++) {
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

std::vector<Texture>
SINGLETON_cache::get_all_objects_with_the_similar_title(std::string title) {
  std::vector<std::pair<std::string, DtoTextureType>> lst = entity::list;

  std::vector<Texture> toReturn;
  for (int i = 0; i < lst.size(); i++) {
    for (int j = 0; j < title.size(); j++) {
      if (lst[i].first[j] != title[j]) {
        break;
      }

      if (j == title.size() - 1) {
        Texture fnd = get_object_by_texture_type(lst[i].second);
        toReturn.push_back(fnd);
      }
    }
  }

  return toReturn;
}

void SINGLETON_cache::init_item() {
  this->init_gun();
  this->init_projectile();
}

void SINGLETON_cache::init_gun() {
  std::vector<std::pair<DtoTextureType, std::vector<VariantType>>> initialize =
      {std::make_pair(
          DtoTextureType::GUN_PISTOL,
          std::vector<VariantType>{0.0f, 0.0f, 10.0f, 4.0f, "GUN_PISTOL"})};

  for (int i = 0; i < initialize.size(); i++) {
    std::pair<DtoTextureType, std::vector<VariantType>> it = initialize[i];

    float xVal = std::get<float>(it.second[0]);
    float yVal = std::get<float>(it.second[1]);
    float wVal = std::get<float>(it.second[2]);
    float hVal = std::get<float>(it.second[3]);
    std::string rawTxVal = std::get<std::string>(it.second[4]);

    DtoRawMesh rawMesh;
    rawMesh.rawTextures = {std::make_pair("default", rawTxVal)};

    DtoPoleset *pGun = new DtoPoleset();
    pGun->x = 0;
    pGun->y = 0;

    DtoItemAmount aGun;
    aGun.amount = 1;

    UNI_item *uGun = new UNI_item(rawMesh, pGun, aGun);
    this->set_push_item(std::make_pair(it.first, uGun));
  }
}

void SINGLETON_cache::init_projectile() {}
