#include <namespace/n_input.h>
#include <source/particle/object/o_player.h>

namespace input {
    std::string* mouse_just_click(){
        std::string* dir = nullptr;

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            dir = new std::string("LEFT");
        }else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            dir = new std::string("RIGHT");
        }

        return dir;
    }

    std::pair<float, float> mouse_position(){
        Vector2 mp = GetMousePosition();

        return std::make_pair(static_cast<float>(mp.x), static_cast<float>(mp.y));
    }

    std::pair<float, float> mouse_position_player_as_pole(){
        SIGNATURE_mesh* plyMesh = G_object_player->get_mesh(); // THIS IS PLUSABLE

        std::pair<int, int> halfRes = sys::get_half_resolution();

        std::pair<float, float> mPos = mouse_position();
        mPos.first -= static_cast<float>(halfRes.first);
        mPos.second -= static_cast<float>(halfRes.second);

        return std::make_pair(static_cast<float>(plyMesh->get_value().x + mPos.first), static_cast<float>(plyMesh->get_value().y + mPos.second));
    }
};
