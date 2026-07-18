#include <render_type/rt.h>

RenderType::RenderType(std::string worldName){}

RenderType::~RenderType(){}

std::vector<std::pair<Uni*, SIGNATURE_mesh*>> RenderType::get_objects() { return this->objects; }

void RenderType::set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value) {
  this->objects = value;
}

void RenderType::set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value){
    this->objects.push_back(value);
}

bool RenderType::delete_checker(void *mem) {
  if (mem != nullptr) {
    return false;
  }

  return true;
}

void RenderType::Execute(){}