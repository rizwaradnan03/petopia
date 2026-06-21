#ifndef BODY_STATIC_BODY
#define BODY_STATIC_BODY

#include <dto/dto_collider.h>
#include <dto/dto_signature_mesh.h>
#include <namespace/n_physic.h>
#include <signature/s_mesh.h>
#include <signature/s_movement.h>
#include <nodes/2d/body/body.h>

class BODY_static: public Body {
    public:
        BODY_static(MeshInit meshInit, DtoCollider* collider);
        ~BODY_static();

        virtual std::string& get_id() override;
        virtual void set_id(std::string value) override;

        virtual SIGNATURE_mesh* get_mesh() override;
        virtual void set_mesh(SIGNATURE_mesh* value) override;

        virtual DtoCollider& get_collider();
        virtual void set_collider(DtoCollider* value);

        virtual void Display() override;
        virtual void Execute(const std::vector<Body*>& objects) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;

        DtoCollider* collider;
};

#endif