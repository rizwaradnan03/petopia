#include <singleton/st_render.h>

SINGLETON_render* G_render = nullptr;

RenderType* SINGLETON_render::get_select(){
    return this->select;
}

void SINGLETON_render::set_select(RenderType* value){
    this->select = value;
}

void SINGLETON_render::change_screen(DtoRenderType worldType, std::string screenName){
    RenderType* rt;

    if(worldType == DtoRenderType::WORLD){
        rt = new RENDER_TYPE_world(screenName);
    }else if(worldType == DtoRenderType::GUI){
        // rt = new RENDER_TYPE_gui()
    }

    this->set_select(rt);
}

void SINGLETON_render::Execute(){
    this->get_select()->Execute(); // run the selected
}