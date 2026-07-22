#include <render_type/rt.h>
#include <nodes/2d/uni/uni.h>
#include <nodes/2d/oth/oth_particle.h>

RenderType::RenderType(std::string worldName){}

RenderType::~RenderType(){}

std::vector<std::pair<Uni*, SIGNATURE_mesh*>> RenderType::get_objects() { return this->objects; }

void RenderType::set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value) {
  this->objects = value;
}

void RenderType::set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value){
    this->objects.push_back(value);
}

std::vector<OTHER_particle*> RenderType::get_particles() { return this->particles; }

void RenderType::set_particles(std::vector<OTHER_particle*> value) {
  this->particles = value;
}

void RenderType::set_push_particle(OTHER_particle* value){
    this->particles.push_back(value);
}

bool RenderType::delete_checker(void *mem) {
  if (mem != nullptr) {
    return false;
  }

  return true;
}

void RenderType::Execute(){
  std::vector<std::pair<Uni*, SIGNATURE_mesh*>> obj = this->get_objects(); 
  for(uint16_t i = 0;i < obj.size();i++){
    bool del = this->delete_checker(obj[i].second);
    if(del == true){
      this->get_objects().erase(this->get_objects().begin() + i);
      i--;
      continue;
    }

    obj[i].first->node_render(obj[i].second);
  }
}