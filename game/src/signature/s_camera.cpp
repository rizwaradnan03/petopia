#include <signature/s_camera.h>

SIGNATURE_camera::SIGNATURE_camera(Camera2D cam) { 
  this->set_value(cam);
  G_render->set_globalize_camera(&this->get_value());
}

Camera2D& SIGNATURE_camera::get_value() { return this->value; }

void SIGNATURE_camera::set_value(Camera2D value) { this->value = value; }

void SIGNATURE_camera::Execute(SIGNATURE_mesh &posMesh) {
  std::pair<int, int> halfRes = sys::get_half_resolution();

  Vector2 tg = (Vector2){posMesh.get_value().x, posMesh.get_value().y};
  Vector2 oft = (Vector2){static_cast<float>(halfRes.first),static_cast<float>(halfRes.second)}; 

  this->get_value().target = tg;
  this->get_value().offset = oft;
      
}
