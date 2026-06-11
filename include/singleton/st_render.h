#ifndef SINGLETON_RENDER_H
#define SINGLETON_RENDER_H

#include <dto/dto_render_world_type.h>
#include <config/c_pch.h>
#include <render_type/rt.h>
#include <render_type/rt_world.h>
#include <render_type/rt_gui.h>

class SINGLETON_render {
    public:
        RenderType* get_select();
        void set_select(RenderType* value);

        void change_screen(DtoRenderWorldType worldType);

        void Execute();

    private:
        RenderType* select;
};

extern SINGLETON_render* G_render;

#endif