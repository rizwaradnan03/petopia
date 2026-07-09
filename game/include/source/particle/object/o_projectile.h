#ifndef OBJECT_PROJECTILE_H
#define OBJECT_PROJECTILE_H

#include <config/c_pch.h>
#include <dto/dto_projectile.h>
#include <dto/dto_signature_mesh.h>
#include <namespace/n_entity.h>
#include <signature/s_mesh.h>
#include <nodes/2d/body/body_static.h>

class OBJECT_projectile: public BODY_static {
    public:
        OBJECT_projectile(DtoRawMesh rawMesh, DtoCollider* collider, DtoProjectileAcceleration projectAccelerationDto, DtoTextureType textureKey);
        ~OBJECT_projectile();

        std::string& get_id() override;
        void set_id(std::string value) override;

        SIGNATURE_mesh* get_mesh() override;
        void set_mesh(SIGNATURE_mesh* value) override;

        DtoCollider& get_collider();
        void set_collider(DtoCollider* value);

        DtoProjectileAcceleration& get_acceleration();
        void set_acceleration(DtoProjectileAcceleration value);

        uint16_t get_damage();
        void set_damage(uint16_t value);

        void action();
        void acceleration_action();

        void Execute(const std::vector<Body*>& objects) override;
        void Display() override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;

        DtoCollider* collider;
        DtoProjectileAcceleration acceleration;

        uint16_t damage;
};

#endif