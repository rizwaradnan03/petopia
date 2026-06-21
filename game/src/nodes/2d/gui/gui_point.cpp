#include <nodes/2d/gui/gui_point.h>

GUI_point::GUI_point(MeshInit meshInit, DtoPoleset* poleSet): Gui(meshInit, poleSet){
    this->set_id(identifier::generate_id("gui_point"));
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

std::string& GUI_point::get_id(){
    return this->id;
}

void GUI_point::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* GUI_point::get_mesh(){
    return this->mesh;
}

void GUI_point::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_point::get_poleset(){
    return this->poleset;
}

void GUI_point::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

void GUI_point::Display(){
    this->get_mesh()->Execute();
}

void GUI_point::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void GUI_point::point_action(){
    // proc
}

void GUI_point::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->point_action();
    this->Display();
}