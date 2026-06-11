#include <singleton/st_render.h>

SINGLETON_render* G_render = nullptr;

RenderType* SINGLETON_render::get_select(){
    return this->select;
}

void SINGLETON_render::set_select(RenderType* value){
    this->select = value;
}

void SINGLETON_render::change_screen(DtoRenderWorldType worldType){
    RenderType* rt;

    if(worldType == DtoRenderWorldType::WORLD){
        // rt = new RENDER_TYPE_world();
    }else if(worldType == DtoRenderWorldType::GUI){
        // rt = new RENDER_TYPE_gui()
    }
}

void SINGLETON_render::Execute(){
    this->get_select()->Execute();
}