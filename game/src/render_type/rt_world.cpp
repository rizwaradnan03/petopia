#include <render_type/rt_world.h>
#include <nodes/2d/uni/uni.h>

RENDER_TYPE_world::RENDER_TYPE_world(std::string worldName) : RenderType(worldName) {
  std::string strized = "render/world/" + worldName;
  std::vector<std::pair<std::string, VariantType>> datas =
      file::read_whole_file_data(strized, new std::string("block"));

  std::vector<std::pair<Uni*, SIGNATURE_mesh*>> obj; 

  DtoRawMesh cart;
  cart.cartesian.x = 120;
  cart.cartesian.y = 0;
  cart.cartesian.w = 30;
  cart.cartesian.h = 30;
  cart.rawTextures = {
      std::make_pair("default", "BLOCK_DIRT"),
  };

  DtoCollider *pCol = new DtoCollider();
  pCol->layer = 1;
  pCol->mask = {1, 2, 3};
  // Body *player = new OBJECT_player(cart, pCol);
  // obj.push_back(player);

  this->set_objects(obj);
}

RENDER_TYPE_world::~RENDER_TYPE_world() {
  std::vector<std::pair<Uni*, SIGNATURE_mesh*>> obj = this->get_objects();
  for (uint16_t i = 0; i < obj.size(); i++) {
    delete obj[i].first;
    delete obj[i].second;
  }
}

bool RENDER_TYPE_world::delete_checker(void *mem) {
  if (mem != nullptr) {
    return false;
  }

  return true;
}

std::vector<std::pair<Uni*, SIGNATURE_mesh*>> RENDER_TYPE_world::get_objects() { return this->objects; }

void RENDER_TYPE_world::set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value) {
  this->objects = value;
}

void RENDER_TYPE_world::set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value){
    this->objects.push_back(value);
}

void RENDER_TYPE_world::Execute() {
  BeginMode2D(*G_render->get_globalize_camera());

  std::vector<std::pair<Uni*, SIGNATURE_mesh*>> objs = this->get_objects();
  for (uint16_t i = 0; i < objs.size(); i++) {
    std::pair<Uni*, SIGNATURE_mesh*> b = objs[i];

    bool c = this->delete_checker(b.second);
    if (c == true) {
      this->get_objects().erase(this->get_objects().begin() + i);
      i--;
      continue;
    }

    b.first->action(b.second);
  }

  EndMode2D();
}
