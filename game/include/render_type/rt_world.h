#ifndef RENDER_TYPE_WORLD
#define RENDER_TYPE_WORLD

#include <config/c_pch.h>
#include <engine/e_variant.h>
#include <dto/dto_collider.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_texture.h>
#include <namespace/n_file.h>
#include <namespace/n_entity.h>
#include <signature/s_garbage.h>
#include <singleton/st_cache.h>
#include <nodes/2d/body/body.h>
#include <nodes/2d/body/body_static.h>
#include <nodes/2d/body/body_dynamic.h>
#include <source/particle/object/o_player.h>
#include <render_type/rt.h>

class RENDER_TYPE_world: public RenderType, public SIGNATURE_garbage {
    public:
        RENDER_TYPE_world(std::string worldName);
        ~RENDER_TYPE_world();
        bool delete_checker(void* mem) override;

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);

        void Execute() override;

    private:
        std::vector<Body*> objects;
};

#endif