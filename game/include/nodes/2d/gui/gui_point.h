#ifndef GUI_GUI_POINT_H
#define GUI_GUI_POINT_H

#include <namespace/n_input.h>
#include <namespace/n_identifier.h>
#include <nodes/2d/gui/gui.h>

class GUI_point: public Gui {
    public:
        GUI_point(MeshInit meshInit, DtoPoleset* poleSet);
        ~GUI_point();

        std::string& get_id();
        void set_id(std::string id);

        virtual SIGNATURE_mesh* get_mesh() override;
        virtual void set_mesh(SIGNATURE_mesh* value) override;

        virtual DtoPoleset* get_poleset() override;
        virtual void set_poleset(DtoPoleset* value) override;

        virtual void point_action();

        virtual void Display() override;
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill) override;
        virtual void Execute(SIGNATURE_mesh* meshDrill) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;
};

#endif