#include <source/particle/gui/g_item.h>

GUI_item::GUI_item(MeshInit meshInit, DtoPoleset* poleSet, DtoItemAmount itemAmountDto): GUI_action(meshInit, poleSet){
    this->set_id(identifier::generate_id("gui_item"));
    
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
    this->set_item_amount(itemAmountDto);
}

std::string& GUI_item::get_id(){
    return this->id;
}

void GUI_item::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* GUI_item::get_mesh(){
    return this->mesh;
}

void GUI_item::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_item::get_poleset(){
    return this->poleset;
}

void GUI_item::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

DtoItemAmount& GUI_item::get_item_amount(){
    return this->item_amount;
}

void GUI_item::set_item_amount(DtoItemAmount value){
    this->item_amount = value;
}

void GUI_item::Display(){
    this->get_mesh()->Execute();
}

void GUI_item::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void GUI_item::hit_action(){
    std::string* inp = input::mouse_just_click();
    if(inp == nullptr || *inp == "RIGHT"){
        return;
    }

    // proc
}

void GUI_item::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->hit_action();
    this->Display();
}