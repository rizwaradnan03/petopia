#include <config/c_pch.h>
#include <config/c_app.h>
#include <singleton/st_render.h>
#include <singleton/st_cache.h>
#include <render_type/rt_world.h>

void init_global(){
    SINGLETON_cache* G_cache = new SINGLETON_cache();
    SINGLETON_render* G_render = new SINGLETON_render();

    // G_render->set_select()
}

int main(){
    InitWindow(screenWidth, screenHeight, "petopia");
    InitAudioDevice();
    SetTargetFPS(60);

    init_global();

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLUE);

        G_render->Execute();

        EndDrawing();
    }

    CloseWindow();
}