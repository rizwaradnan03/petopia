#include <nodes/2d/gui/gui_click.h>

GUI_click::GUI_click(DtoRawMesh rawMesh, DtoPoleset* poleSet): Gui(rawMesh, poleSet){
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

GUI_click::~GUI_click(){
    delete this->get_mesh();
}

std::string& GUI_click::get_id(){
    return this->id;
}

void GUI_click::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* GUI_click::get_mesh(){
    return this->mesh;
}

void GUI_click::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_click::get_poleset(){
    return this->poleset;
}

void GUI_click::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

void GUI_click::Display(){
    this->get_mesh()->Execute();
}

void GUI_click::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void GUI_click::hit_action(){
    std::string* inp = input::mouse_just_click();
    if(inp == nullptr || *inp == "RIGHT"){
        return;
    }

    // proc
}

void GUI_click::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->hit_action();
    this->Display();
}