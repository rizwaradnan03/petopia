#ifndef SIGNATURE_MESH_H
#define SIGNATURE_MESH_H

#include <dto/dto_raw_mesh.h>
#include <dto/dto_signature_mesh.h>
#include <namespace/n_system.h>
#include <singleton/st_cache.h>

class SIGNATURE_mesh {
public:
  SIGNATURE_mesh(DtoRawMesh value); // name and alike

  MeshInit &get_value();
  void set_value(MeshInit value);

  MeshPole &get_pole();
  void set_pole(MeshPole value);

  Texture get_texture();
  void set_texture(Texture value);

  float get_right_position();
  float get_left_position();
  float get_top_position();
  float get_bottom_position();

  void change_animation(std::string &anim);

  void Execute();

private:
  MeshInit value;
  Texture texture;

  MeshPole pole;
};

#endif
