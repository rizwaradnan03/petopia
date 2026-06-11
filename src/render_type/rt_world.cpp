#include <render_type/rt_world.h>

RENDER_TYPE_world::RENDER_TYPE_world(std::vector<Body*> objects){
    this->set_objects(objects);
}

std::vector<Body*> RENDER_TYPE_world::get_objects(){
    return this->objects;
}

void RENDER_TYPE_world::set_objects(std::vector<Body*> value){
    this->objects = value;
}