#ifndef RENDER_TYPE_WORLD
#define RENDER_TYPE_WORLD

#include <config/c_pch.h>
#include <dto/dto_collider.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_texture.h>
#include <engine/e_variant.h>
#include <namespace/n_entity.h>
#include <namespace/n_file.h>
#include <render_type/rt.h>
#include <singleton/st_cache.h>
#include <singleton/st_render.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/body/body_dynamic.h>
#include <nodes/2d/body/body_static.h>
#include <source/particle/object/o_player.h>

class Uni;
class OTHER_particle;
class OTHER_projectile;

class RENDER_TYPE_world : public RenderType {
  public:
    RENDER_TYPE_world(std::string worldName);
    ~RENDER_TYPE_world();
    bool delete_checker(void *mem) override;

    std::vector<std::pair<Uni*, SIGNATURE_mesh*>> get_objects() override;
    void set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value) override;
    void set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value) override;

    std::vector<OTHER_particle*> get_particles() override;
    void set_particles(std::vector<OTHER_particle*> value) override;
    void set_push_particle(OTHER_particle* value) override;

    std::vector<OTHER_projectile*> get_asb_projectiles();
    void set_asb_projectiles(std::vector<OTHER_projectile*> value);
    void set_push_asb_projectile(OTHER_projectile* value);

    OBJECT_player* get_player();
    void set_player(OBJECT_player* value);

    void Execute() override;

  private:
    std::vector<std::pair<Uni*, SIGNATURE_mesh*>> objects;
    
    std::vector<OTHER_particle*> particles; // ATOM IN THE WORLD ACTUALLY (main particle database)
    std::vector<OTHER_projectile*> asb_projectiles;

    OBJECT_player* player;
};

#endif
