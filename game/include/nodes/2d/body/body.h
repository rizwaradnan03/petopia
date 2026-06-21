#ifndef BODY_BODY_H
#define BODY_BODY_H

#include <config/c_pch.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_collider.h>
#include <namespace/n_identifier.h>
#include <signature/s_mesh.h>

class Body {
    public:
        Body(MeshInit meshInit, DtoCollider* collider);

        virtual std::string& get_id();
        virtual void set_id(std::string value);

        virtual SIGNATURE_mesh* get_mesh();
        virtual void set_mesh(SIGNATURE_mesh* value);

        virtual DtoCollider& get_collider();
        virtual void set_collider(DtoCollider* value);

        virtual void Display();
        virtual void Execute(const std::vector<Body*>& objects);
        
        // virtual void physic(const std::vector<Body*>& objects);
        // virtual void object_collide(const std::vector<Body*>& objects);

    private:
        std::string id;
        
        DtoCollider* collider;

        SIGNATURE_mesh* mesh;
};

#endif