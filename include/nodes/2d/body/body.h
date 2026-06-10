#ifndef BODY_BODY_H
#define BODY_BODY_H

#include <config/c_pch.h>

class Body {
    public:
        Body(mesh* mesh, Mesh* mesh, Material* material, Trait* trait);
        ~Body();

        virtual std::string get_id() override;
        virtual void set_id(std::string value) override;

        virtual mesh* get_mesh();
        virtual void set_mesh(mesh* value);

        virtual Mesh* get_mesh();
        virtual void set_mesh(Mesh* value);

        virtual Material* get_material();
        virtual void set_material(Material* value);

        virtual Trait* get_trait();
        virtual void set_trait(Trait* value);

        virtual Attribute* get_attribute();
        virtual void set_attribute(Attribute* value);

        virtual Box_hit* get_box_hit();
        virtual void set_box_hit(Box_hit* value);

        virtual void Execute(const std::vector<Body*>& objects);
        virtual void Display();
        
        virtual void physic(const std::vector<Body*>& objects);
        virtual void object_collide(const std::vector<Body*>& objects);

    private:
        std::string id;

        mesh* mesh;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;
        Trait* trait;

        Box_hit* box_hit;
};

#endif