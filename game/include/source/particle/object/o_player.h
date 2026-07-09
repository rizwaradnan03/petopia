#ifndef OBJECT_PLAYER_H
#define OBJECT_PLAYER_H

#include <config/c_pch.h>
#include <namespace/n_system.h>
#include <namespace/n_input.h>
#include <namespace/n_system.h>
#include <signature/s_camera.h>
#include <signature/s_mesh.h>
#include <signature/s_movement.h>
#include <singleton/st_cache.h>
#include <nodes/2d/body/body_dynamic.h>
#include <nodes/2d/gui/gui_container.h>
#include <source/particle/uni/u_item.h>
#include <source/particle/gui/g_inventory.h>

class OBJECT_player: public BODY_dynamic {
    public:
        OBJECT_player(DtoRawMesh rawMesh, DtoCollider* collider);

        std::string& get_id() override;
        void set_id(std::string value) override;

        SIGNATURE_camera* get_camera();
        void set_camera(SIGNATURE_camera* value);

        SIGNATURE_mesh* get_mesh() override;
        void set_mesh(SIGNATURE_mesh* value) override;

        SIGNATURE_movement* get_movement();
        void set_movement(SIGNATURE_movement* value);

        DtoCollider& get_collider();
        void set_collider(DtoCollider* value);

        std::vector<GUI_container*> get_gui_containers();
        void set_gui_containers(std::vector<GUI_container*> value);
        void set_push_gui_containers(GUI_container* value);

        UNI_item* get_hold_item();
        void set_hold_item(UNI_item* value);

        void physic(const std::vector<Body*>& objects);
        void object_collide(const std::vector<Body*>& objects);

        void Display() override;
        void Execute(const std::vector<Body*>& objects) override;

    private:
        std::string id;

        SIGNATURE_camera* camera;
        SIGNATURE_mesh* mesh;
        SIGNATURE_movement* movement;

        DtoCollider* collider;

        std::vector<GUI_container*> gui_containers;

        UNI_item* hold_item;
};

extern OBJECT_player* G_object_player;

#endif