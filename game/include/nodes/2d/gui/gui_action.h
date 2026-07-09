#ifndef GUI_GUI_ACTION_H
#define GUI_GUI_ACTION_H

#include <dto/dto_signature_mesh.h>
#include <dto/dto_poleset.h>
#include <dto/dto_raw_mesh.h>
#include <namespace/n_identifier.h>
#include <nodes/2d/gui/gui_click.h>
#include <nodes/2d/gui/gui_point.h>

class GUI_action: public GUI_click, public GUI_point {
    public:
        using GUI_click::hit_action;
        using GUI_point::point_action;
        
        GUI_action(DtoRawMesh rawMesh, DtoPoleset* poleSet);
        ~GUI_action();

        std::string& get_id();
        void set_id(std::string value);

        virtual SIGNATURE_mesh* get_mesh() override;
        virtual void set_mesh(SIGNATURE_mesh* value) override;

        virtual DtoPoleset* get_poleset() override;
        virtual void set_poleset(DtoPoleset* value) override;

        virtual void hit_action() override;
        virtual void point_action() override;
        virtual void action();

        virtual void Display() override;
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill) override;
        virtual void Execute(SIGNATURE_mesh* meshDrill) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;
};

#endif