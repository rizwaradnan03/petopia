#include <source/particle/uni/u_item.h>

UNI_item::UNI_item(DtoRawMesh rawMesh, DtoPoleset* poleSet, DtoItemAmount itemAmountDto): GUI_action(rawMesh, poleSet){
    this->set_id(identifier::generate_id("uni_item"));
    
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
    this->set_item_amount(itemAmountDto);
}

std::string& UNI_item::get_id(){
    return this->id;
}

void UNI_item::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* UNI_item::get_mesh(){
    return this->mesh;
}

void UNI_item::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* UNI_item::get_poleset(){
    return this->poleset;
}

void UNI_item::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

DtoItemAmount& UNI_item::get_item_amount(){
    return this->item_amount;
}

void UNI_item::set_item_amount(DtoItemAmount value){
    this->item_amount = value;
}

void UNI_item::Display(){
    this->get_mesh()->Execute();
}

void UNI_item::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void UNI_item::hit_action(){
    std::string* inp = input::mouse_just_click();
    if(inp == nullptr || *inp == "RIGHT"){
        return;
    }

    // proc
}

void UNI_item::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->hit_action();
    this->Display();
}