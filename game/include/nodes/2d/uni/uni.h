#ifndef UNI_H
#define UNI_H

#include <config/c_pch.h>
#include <dto/dto_poleset.h>
#include <dto/dto_item_amount.h>
#include <dto/dto_raw_mesh.h>
#include <namespace/n_identifier.h>
#include <namespace/n_input.h>
#include <signature/s_mesh.h>
#include <singleton/st_render.h> // st render is globalize render
#include <render_type/rt.h>

class Uni { 
    public:
        Uni(std::pair<DtoRawMesh*, DtoRawMesh*> rawMesh, DtoPoleset* poleSet, DtoItemAmount itemAmountDto);
        ~Uni();

        virtual std::string& get_id();
        virtual void set_id(std::string value);

        virtual std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> get_mesh();
        virtual void set_mesh(std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> value);

        virtual SIGNATURE_mesh* get_gui_mesh();
        virtual SIGNATURE_mesh* get_object_mesh();

        virtual std::vector<SIGNATURE_mesh*> get_nodes();
        virtual void set_nodes(std::vector<SIGNATURE_mesh*> value);
        virtual void set_push_nodes(SIGNATURE_mesh* value);

        virtual void register_nodes();

        virtual DtoPoleset* get_poleset();
        virtual void set_poleset(DtoPoleset* value);

        virtual DtoItemAmount& get_item_amount();
        virtual void set_item_amount(DtoItemAmount value);

        virtual void action(SIGNATURE_mesh* childAddr);
        virtual void usage_action(SIGNATURE_mesh* childAddr);

        virtual void Execute(SIGNATURE_mesh* meshDrill);
        virtual void Display();
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill);
        
        virtual void node_erase_checker();

    private:
        std::string id;

        std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> mesh; // first is for gui & second is for object on mother of nodes
        std::vector<SIGNATURE_mesh*> nodes; // this is what gonna be on render type

        DtoPoleset* poleset;

        DtoItemAmount item_amount;
};

#endif

