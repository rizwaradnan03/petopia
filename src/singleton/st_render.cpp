#include <singleton/st_render.h>

SINGLETON_render* G_render = nullptr;

RenderType* SINGLETON_render::get_select(){
    return this->select;
}

void SINGLETON_render::set_select(RenderType* value){
    this->select = value;
}

void SINGLETON_render::Execute(){
    this->get_select()->Execute();
}