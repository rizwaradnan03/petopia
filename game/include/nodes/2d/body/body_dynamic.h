#ifndef BODY_DYNAMIC_BODY
#define BODY_DYNAMIC_BODY

#include <dto/dto_collider.h>
#include <dto/dto_raw_mesh.h>
#include <dto/dto_signature_mesh.h>
#include <namespace/n_physic.h>
#include <signature/s_mesh.h>
#include <signature/s_movement.h>
#include <nodes/2d/body/body.h>

class BODY_dynamic: public Body {
    public:
        BODY_dynamic(DtoRawMesh rawMesh, DtoCollider* collider);
        ~BODY_dynamic();

        virtual std::string& get_id() override;
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

#endif