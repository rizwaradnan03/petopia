#ifndef OTHER_PROJECTILE_H
#define OTHER_PROJECTILE_H

#include <config/c_pch.h>
#include <dto/dto_projectile.h>
#include <signature/s_attack.h>
#include <signature/s_mesh.h>
#include <nodes/2d/oth/oth_particle.h>

class OTHER_projectile: public OTHER_particle {
    public:
        OTHER_projectile(DtoProjectileAcceleration target, DtoProjectileValue profle);
        ~OTHER_projectile();

        virtual DtoProjectileAcceleration get_target();
        virtual void set_target(DtoProjectileAcceleration value);

        virtual DtoProjectileValue get_profile();
        virtual void set_profile(DtoProjectileValue value);

        virtual SIGNATURE_mesh* get_mesh();
        virtual void set_mesh(SIGNATURE_mesh* value);

        virtual SIGNATURE_attack* get_attack();
        virtual void set_attack(SIGNATURE_attack* value);

        virtual void Execute() override;
        virtual void Display();
        virtual void action();
    private:
        DtoProjectileAcceleration target;
        DtoProjectileValue profile;
        
        SIGNATURE_mesh* mesh;
        SIGNATURE_attack* attack;
};

#endif