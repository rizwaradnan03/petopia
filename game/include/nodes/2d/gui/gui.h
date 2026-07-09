#ifndef GUI_GUI_H
#define GUI_GUI_H

#include <dto/dto_poleset.h>
#include <dto/dto_raw_mesh.h>
#include <namespace/n_identifier.h>

class SIGNATURE_mesh;

class Gui {
    public:
        Gui(DtoRawMesh rawMesh, DtoPoleset* poleSet);
        ~Gui();

        std::string& get_id();
        void set_id(std::string value);

        virtual SIGNATURE_mesh* get_mesh();
        virtual void set_mesh(SIGNATURE_mesh* value);

        virtual DtoPoleset* get_poleset();
        virtual void set_poleset(DtoPoleset* value);

        virtual void Display();
        virtual void UpdateDrill(SIGNATURE_mesh* meshDrill);
        virtual void Execute(SIGNATURE_mesh* meshDrill);

    private:
        std::string id;

        SIGNATURE_mesh* mesh;
        DtoPoleset* poleset;
};

#endif