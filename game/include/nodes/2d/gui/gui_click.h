#ifndef GUI_GUI_CLICK_H
#define GUI_GUI_CLICK_H

#include <config/c_pch.h>
#include <namespace/n_input.h>
#include <namespace/n_identifier.h>
#include <nodes/2d/gui/gui.h>

class GUI_click: public Gui {
    public:
        GUI_click(MeshInit meshInit, DtoPoleset* poleSet);
        ~GUI_click();

        std::string& get_id();
        void set_id(std::string value);

        virtual SIGNATURE_mesh* get_mesh() override;
        virtual void set_mesh(SIGNATURE_mesh* value) override;

        virtual DtoPoleset* get_poleset() override;
        virtual void set_poleset(DtoPoleset* value) override;

        virtual void hit_action();

        virtual void Display() override;
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill) override;
        virtual void Execute(SIGNATURE_mesh* meshDrill) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;
};

#endif