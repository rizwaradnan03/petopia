#include <config/c_app.h>
#include <config/c_pch.h>
#include <render_type/rt_world.h>
#include <singleton/st_cache.h>
#include <singleton/st_render.h>
#include <singleton/st_system.h>

void init_global() {
  G_cache = new SINGLETON_cache();
  G_render = new SINGLETON_render();
  G_system = new SINGLETON_system();

  G_render->change_screen(DtoRenderType::WORLD, "rizwarmc.json");
}

int main() {
  InitWindow(screenWidth, screenHeight, "petopia");
  InitAudioDevice();
  SetTargetFPS(60);

  init_global();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLUE);

    // BeginMode2D(*G_render->get_globalize_camera());
    G_render->Execute();
    // EndMode2D();

    EndDrawing();
  }

  CloseWindow();
}
