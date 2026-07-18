#ifndef RENDER_TYPE_WORLD
#define RENDER_TYPE_WORLD

#include <config/c_pch.h>
#include <dto/dto_collider.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_texture.h>
#include <engine/e_variant.h>
#include <namespace/n_entity.h>
#include <namespace/n_file.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/body/body_dynamic.h>
#include <nodes/2d/body/body_static.h>
#include <render_type/rt.h>
#include <singleton/st_cache.h>
#include <singleton/st_render.h>

class Uni;

class RENDER_TYPE_world : public RenderType {
  public:
    RENDER_TYPE_world(std::string worldName);
    ~RENDER_TYPE_world();
    bool delete_checker(void *mem) override;

    std::vector<std::pair<Uni*, SIGNATURE_mesh*>> get_objects() override;
    void set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value) override;
    void set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value) override;

    void Execute() override;

  private:
    std::vector<std::pair<Uni*, SIGNATURE_mesh*>> objects;
};

#endif
