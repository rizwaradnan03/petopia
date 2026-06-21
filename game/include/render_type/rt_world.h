#ifndef RENDER_TYPE_WORLD
#define RENDER_TYPE_WORLD

#include <config/c_pch.h>
#include <engine/e_variant.h>
#include <dto/dto_collider.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_texture.h>
#include <namespace/n_file.h>
#include <namespace/n_entity.h>
#include <singleton/st_cache.h>
#include <render_type/rt.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/body/body_static.h>
#include <nodes/2d/body/body_dynamic.h>

class RENDER_TYPE_world: public RenderType {
    public:
        RENDER_TYPE_world(std::string worldName);
        ~RENDER_TYPE_world();

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);

        void Execute() override;

    private:
        std::vector<Body*> objects;
};

#endif