#include "namespace/n_system.h"
#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(DtoRawMesh value) {
  std::vector<std::pair<std::string, std::vector<Texture>>> txt;
  for (uint8_t i = 0; i < value.rawTextures.size(); i++) {
    std::vector<Texture> textObjects =
        G_cache->get_all_objects_with_the_similar_title(
            value.rawTextures[i].second);
    txt.push_back(std::make_pair(value.rawTextures[i].first, textObjects));
  }

  MeshInit init;
  init.x = value.cartesian.x;
  init.y = value.cartesian.y;
  init.w = value.cartesian.w;
  init.h = value.cartesian.h;
  init.selected_texture = std::make_pair(txt[0].first, 0);
  init.texture = txt;

  this->set_value(init);

  float xV = value.cartesian.w / 2;
  float yV = value.cartesian.h / 2;

  MeshPole mP;
  mP.x = xV;
  mP.y = yV;
  this->set_pole(mP);
}

MeshInit &SIGNATURE_mesh::get_value() { return this->value; }

void SIGNATURE_mesh::set_value(MeshInit value) { this->value = value; }

MeshPole &SIGNATURE_mesh::get_pole() { return this->pole; }

void SIGNATURE_mesh::set_pole(MeshPole value) { this->pole = value; }

Texture SIGNATURE_mesh::get_texture() { return this->texture; }

void SIGNATURE_mesh::set_texture(Texture value) { this->texture = value; }

float SIGNATURE_mesh::get_right_position() {
  return this->get_value().x + this->get_pole().x;
}

float SIGNATURE_mesh::get_left_position() {
  return this->get_value().x - this->get_pole().x;
}

float SIGNATURE_mesh::get_top_position() {
  return this->get_value().y - this->get_pole().y;
}

float SIGNATURE_mesh::get_bottom_position() {
  return this->get_value().y + this->get_pole().y;
}

void SIGNATURE_mesh::change_animation(std::string &anim) {
  this->get_value().selected_texture.first = anim;
  this->get_value().selected_texture.second = 0;
}

void SIGNATURE_mesh::Execute() {
  MeshPole mP = this->get_pole();
  MeshInit m = this->get_value();

  if (m.force_time_limit.second == nullptr) {
    for (uint8_t i = 0; i < m.texture.size(); i++) {
      if (m.texture[i].first == m.selected_texture.first) {
        if (m.texture[i].second.size() > 1) {
          m.force_time_limit = std::make_pair(
              new float(0.2),
              new std::chrono::time_point<std::chrono::high_resolution_clock>(
                  sys::get_current_time()));
          break;
        }
      }
    }
  }

  float xV = m.x - mP.x;
  float yV = m.y - mP.y;

  Rectangle source = {0.0f, 0.0f, m.w, m.h};
  Rectangle dest = {xV, yV, m.w, m.h};

  Vector2 origin = {0, 0};

  Texture tx;
  if (m.force_time_limit.first == nullptr &&
      m.force_time_limit.second == nullptr) {
    tx = m.texture[0].second[0];
  } else {
    std::vector<Texture> candidate;
    for (uint8_t i = 0; i < m.texture.size(); i++) {
      if (m.texture[i].first == m.selected_texture.first) {
        candidate = m.texture[i].second;
        break;
      }
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime =
        sys::get_current_time();

    std::chrono::duration<float> differ =
        currentTime - *m.force_time_limit.second;
    if (differ.count() >= *m.force_time_limit.first) {
      m.selected_texture.second = (
          m.selected_texture.second >= candidate.size() - 1
              ? 0
              : m.selected_texture.second + 1);
    }

    tx = candidate[m.selected_texture.second];
  }

  DrawTexturePro(tx, source, dest, origin, 0.0f, WHITE);
}
