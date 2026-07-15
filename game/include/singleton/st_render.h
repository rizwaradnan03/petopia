#ifndef SINGLETON_RENDER_H
#define SINGLETON_RENDER_H

#include <config/c_pch.h>
#include <dto/dto_render_type.h>
#include <render_type/rt.h>

class RENDER_TYPE_world;
class RENDER_TYPE_gui;

class SINGLETON_render {
public:
  RenderType *get_select();
  void set_select(RenderType *value);

  void change_screen(DtoRenderType worldType, std::string screenName);

  Camera2D *get_globalize_camera();
  void set_globalize_camera(Camera2D *value);

  void Execute();

private:
  RenderType *select;
  Camera2D *globalize_camera;
};

extern SINGLETON_render *G_render;

#endif
