#ifndef GUI_GUI_CONTAINER_H
#define GUI_GUI_CONTAINER_H

#include <config/c_pch.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_poleset.h>
#include <nodes/2d/gui/gui.h>

class GUI_container: public Gui {
    public:
        GUI_container(MeshInit meshInit, DtoPoleset* poleSet);
        
        virtual SIGNATURE_mesh* get_mesh();
        virtual void set_mesh(SIGNATURE_mesh* value);

        virtual DtoPoleset* get_poleset();
        virtual void set_poleset(DtoPoleset* value);

        std::vector<Gui*> get_nodes();
        void set_nodes(std::vector<Gui*> value);
        void set_push_nodes(Gui* value);

        virtual void Display();
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill);
        virtual void Execute(SIGNATURE_mesh* meshDrill);

    private:
        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;

        std::vector<Gui*> nodes;
};

#endif