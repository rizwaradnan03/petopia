#include <signature/s_camera.h>

SIGNATURE_camera::SIGNATURE_camera(Camera2D cam){
    this->set_value(cam);
}

Camera2D SIGNATURE_camera::get_value(){
    return this->value;
}

void SIGNATURE_camera::set_value(Camera2D value){
    this->value = value;
}

void SIGNATURE_camera::Execute(SIGNATURE_mesh& posMesh){
    std::pair<int, int> halfRes = sys::get_half_resolution();

    Camera2D cam = this->get_value();
    cam.target = (Vector2){posMesh.get_value().x, posMesh.get_value().y};
    cam.offset = (Vector2){static_cast<float>(halfRes.first), static_cast<float>(halfRes.second)};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    this->set_value(cam);
}