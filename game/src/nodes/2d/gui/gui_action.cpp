#include <nodes/2d/gui/gui_action.h>

GUI_action::GUI_action(MeshInit meshInit, DtoPoleset* poleSet): GUI_click(meshInit, poleSet), GUI_point(meshInit, poleSet){
    this->set_id(identifier::generate_id("gui_action"));
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

std::string& GUI_action::get_id(){
    return this->id;
}

void GUI_action::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* GUI_action::get_mesh(){
    return this->mesh;
}

void GUI_action::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_action::get_poleset(){
    return this->poleset;
}

void GUI_action::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

void GUI_action::hit_action(){}

void GUI_action::point_action(){}

void GUI_action::action(){
    this->point_action();
    this->hit_action();
}

void GUI_action::Display(){
    this->get_mesh()->Execute();
}

void GUI_action::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void GUI_action::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display();
}