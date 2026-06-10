#include <config/c_pch.h>
#include <config/c_app.h>
#include <singleton/st_render.h>

void init_global(){
    SINGLETON_render* G_render = new SINGLETON_render();
    // G_render->set_select()
}

int main(){
    InitWindow(screenWidth, screenHeight, "petopia");
    InitAudioDevice();
    SetTargetFPS(60);

    init_global();

    while(!WindowShouldClose()){
        break;
    }

    CloseWindow();
}