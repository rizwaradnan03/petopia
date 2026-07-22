#ifndef RENDER_TYPE_H
#define RENDER_TYPE_H

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
#include <signature/s_garbage.h>
#include <singleton/st_cache.h>
#include <singleton/st_render.h>

class Uni;
class OTHER_particle;

class RenderType: public SIGNATURE_garbage {
    public:
        RenderType(std::string worldName);
        ~RenderType();
        bool delete_checker(void *mem);

        virtual std::vector<std::pair<Uni*, SIGNATURE_mesh*>> get_objects();
        virtual void set_objects(std::vector<std::pair<Uni*, SIGNATURE_mesh*>> value);
        virtual void set_push_object(std::pair<Uni*, SIGNATURE_mesh*> value);

        virtual std::vector<OTHER_particle*> get_particles();
        virtual void set_particles(std::vector<OTHER_particle*> value);
        virtual void set_push_particle(OTHER_particle* value);

        virtual void Execute();

        private:
            std::vector<std::pair<Uni*, SIGNATURE_mesh*>> objects;
            std::vector<OTHER_particle*> particles; // ATOM IN THE WORLD ACTUALLY 
};

#endif