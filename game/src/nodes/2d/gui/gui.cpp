#include <nodes/2d/gui/gui.h>

Gui::Gui(MeshInit meshInit, DtoPoleset* poleSet){
    this->set_id(identifier::generate_id("gui"));
    
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

std::string& Gui::get_id(){
    return this->id;
}

void Gui::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* Gui::get_mesh(){
    return this->mesh;
}

void Gui::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* Gui::get_poleset(){
    return this->poleset;
}

void Gui::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

void Gui::Display(){
    this->get_mesh()->Execute();
}

void Gui::UpdateDrill(SIGNATURE_mesh* meshDrill){
    if(meshDrill == nullptr){
        return; // static stuff
    }

    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void Gui::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display();
}