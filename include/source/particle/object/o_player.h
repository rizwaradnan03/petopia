#ifndef OBJECT_PLAYER_H
#define OBJECT_PLAYER_H

#include <config/c_pch.h>
#include <namespace/n_input.h>
#include <nodes/2d/body/body_dynamic.h>

class OBJECT_player: public BODY_dynamic {
    public:
        OBJECT_player(MeshInit meshInit, DtoCollider* collider);

        virtual std::string get_id() override;
        virtual void set_id(std::string value) override;

        virtual SIGNATURE_mesh* get_mesh() override;
        virtual void set_mesh(SIGNATURE_mesh* value) override;

        virtual SIGNATURE_movement* get_movement();
        virtual void set_movement(SIGNATURE_movement* value);

        virtual DtoCollider& get_collider();
        virtual void set_collider(DtoCollider* value);

        virtual void physic(const std::vector<Body*>& objects);
        virtual void object_collide(const std::vector<Body*>& objects);

        virtual void Display() override;
        virtual void Execute(const std::vector<Body*>& objects) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        SIGNATURE_movement* movement;

        DtoCollider* collider;
};

extern OBJECT_player* G_object_player;

#endif