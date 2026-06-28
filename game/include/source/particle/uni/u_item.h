#ifndef UNI_ITEM_H
#define UNI_ITEM_H

#include <config/c_pch.h>
#include <dto/dto_poleset.h>
#include <dto/dto_signature_mesh.h>
#include <dto/dto_item_amount.h>
#include <namespace/n_identifier.h>
#include <nodes/2d/gui/gui_action.h>

class UNI_item: GUI_action {
    public:
        UNI_item(MeshInit meshInit, DtoPoleset* poleSet, DtoItemAmount itemAmountDto);
        
        std::string& get_id();
        void set_id(std::string value);

        SIGNATURE_mesh* get_mesh() override;
        void set_mesh(SIGNATURE_mesh* value) override;

        DtoPoleset* get_poleset() override;
        void set_poleset(DtoPoleset* value) override;

        DtoItemAmount& get_item_amount();
        void set_item_amount(DtoItemAmount value);

        void hit_action();

        void Display() override;
        void UpdateDrill(SIGNATURE_mesh* meshDrill) override;
        void Execute(SIGNATURE_mesh* meshDrill) override;

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;

        DtoItemAmount item_amount;
};

#endif