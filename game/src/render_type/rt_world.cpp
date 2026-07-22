#include <render_type/rt_world.h>
#include <nodes/2d/uni/uni.h>
#include <nodes/2d/oth/oth_particle.h>
#include <nodes/2d/oth/oth_projectile.h>
// #include <source/particle/object/o_player.h>

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
  OBJECT_player *player = new OBJECT_player(cart, pCol);
  this->set_player(player);
  // obj.push_back(player);

  this->set_objects(obj);
}

RENDER_TYPE_world::~RENDER_TYPE_world() {
  std::vector<std::pair<Uni*, SIGNATURE_mesh*>> obj = this->get_objects();
  std::vector<OTHER_particle*> prt;

  for (uint16_t i = 0; i < obj.size() + prt.size(); i++) {
    if(i < obj.size()){
      delete obj[i].first;
      delete obj[i].second;
    }else{
      delete prt[i - obj.size()];
    }
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

std::vector<OTHER_particle*> RENDER_TYPE_world::get_particles() { return this->particles; }

void RENDER_TYPE_world::set_particles(std::vector<OTHER_particle*> value) {
  this->particles = value;
}

void RENDER_TYPE_world::set_push_particle(OTHER_particle* value){
  if(OTHER_projectile* trs = dynamic_cast<OTHER_projectile*>(value)){
    this->set_push_asb_projectile(trs);
  }
    
  this->particles.push_back(value);
}

std::vector<OTHER_projectile*> RENDER_TYPE_world::get_asb_projectiles() { return this->asb_projectiles; }

void RENDER_TYPE_world::set_asb_projectiles(std::vector<OTHER_projectile*> value) {
  this->asb_projectiles = value;
}

void RENDER_TYPE_world::set_push_asb_projectile(OTHER_projectile* value){
    this->asb_projectiles.push_back(value);
}

OBJECT_player* RENDER_TYPE_world::get_player(){
  return this->player;
}

void RENDER_TYPE_world::set_player(OBJECT_player* value){
  this->player = value;
}

void RENDER_TYPE_world::Execute() {
  BeginMode2D(*G_render->get_globalize_camera());

  // TODO: every frame i need to make an array of object mesh so i can put into the player while i need to assume the collission
  this->get_player()->Execute({});

  for (uint16_t i = 0; i < this->get_objects().size(); i++) {
    std::pair<Uni*, SIGNATURE_mesh*> b = this->get_objects()[i];

    bool c = this->delete_checker(b.second);
    if (c == true) {
      this->get_objects().erase(this->get_objects().begin() + i);
      i--;
      continue;
    }

    b.first->node_render(b.second);
  }

  for(uint16_t i = 0;i < this->get_particles().size();i++){
    OTHER_particle* p = this->get_particles()[i];

    bool c = this->delete_checker(p);
    if(c == true){
      this->get_particles().erase(this->get_particles().begin() + i);
      i--;
      continue;
    }

    p->Execute();
  }

  EndMode2D();
}
