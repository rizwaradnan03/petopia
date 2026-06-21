#ifndef NAMESPACE_INPUT_H
#define NAMESPACE_INPUT_H

#include <config/c_pch.h>

class OBJECT_player;

namespace input {
    std::string* mouse_just_click();

    std::pair<float, float> mouse_position();
    std::pair<float, float> mouse_position_player_as_pole();
};

#endif