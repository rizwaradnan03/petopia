#ifndef GUI_INVENTORY_H
#define GUI_INVENTORY_H

#include <config/c_pch.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_poleset.h>
#include <namespace/n_identifier.h>
#include <nodes/2d/gui/gui_container.h>
#include <nodes/2d/gui/gui_action.h>

class OBJECT_player;

class GUI_inventory: public GUI_container {
    public:
        GUI_inventory(MeshInit meshInit, DtoPoleset* poleSet);
        ~GUI_inventory();

        bool delete_checker(void* mem) override;

        std::string& get_id();
        void set_id(std::string value);

        SIGNATURE_mesh* get_mesh();
        void set_mesh(SIGNATURE_mesh* value);

        DtoPoleset* get_poleset();
        void set_poleset(DtoPoleset* value);

        std::vector<GUI_action*> get_nodes();
        void set_nodes(std::vector<GUI_action*> value);
        void set_push_nodes(GUI_action* value);

        std::string* get_selected_item_id();
        void set_selected_item_id(std::string* value);

        void Display();
        void UpdateDrill(SIGNATURE_mesh* meshDrill);

        void action();
        void select_item_action();

        void Execute(SIGNATURE_mesh* meshDrill);

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;

        std::vector<GUI_action*> nodes;

        std::string* selected_item_id;
};

#endif