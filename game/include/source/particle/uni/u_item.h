#ifndef UNI_ITEM_H
#define UNI_ITEM_H

#include <config/c_pch.h>
#include <dto/dto_poleset.h>
#include <dto/dto_item_amount.h>
#include <dto/dto_raw_mesh.h>
#include <namespace/n_identifier.h>
#include <signature/s_mesh.h>
#include <nodes/2d/gui/gui_action.h>

class UNI_item: public GUI_action { // uni item adalah item dalam in game, dia bersifat uni
    public:
        UNI_item(DtoRawMesh rawMesh, DtoPoleset* poleSet, DtoItemAmount itemAmountDto);
        
        std::string& get_id();
        void set_id(std::string value);

        SIGNATURE_mesh* get_mesh();
        void set_mesh(SIGNATURE_mesh* value);

        DtoPoleset* get_poleset();
        void set_poleset(DtoPoleset* value);

        DtoItemAmount& get_item_amount();
        void set_item_amount(DtoItemAmount value);

        void hit_action();

        void Display();
        void UpdateDrill(SIGNATURE_mesh* meshDrill);
        void Execute(SIGNATURE_mesh* meshDrill);

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;

        DtoItemAmount item_amount;
};

#endif