#ifndef GUI_GUI_CONTAINER_H
#define GUI_GUI_CONTAINER_H

#include <config/c_pch.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_poleset.h>
#include <nodes/2d/gui/gui.h>
#include <nodes/2d/gui/gui_action.h>

class GUI_container: public Gui {
    public:
        GUI_container(MeshInit meshInit, DtoPoleset* poleSet);
        ~GUI_container();

        virtual SIGNATURE_mesh* get_mesh();
        virtual void set_mesh(SIGNATURE_mesh* value);

        virtual DtoPoleset* get_poleset();
        virtual void set_poleset(DtoPoleset* value);

        std::vector<GUI_action*> get_nodes();
        void set_nodes(std::vector<GUI_action*> value);
        void set_push_nodes(GUI_action* value);

        virtual void Display();
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill);
        virtual void Execute(SIGNATURE_mesh* meshDrill);

    private:
        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;

        std::vector<GUI_action*> nodes;
};

#endif