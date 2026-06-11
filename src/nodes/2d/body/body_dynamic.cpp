#include <nodes/2d/body/body_dynamic.h>

BODY_dynamic::BODY_dynamic(MeshInit meshInit): Body(meshInit){
    this->set_id(identifier::generate_id("body_dynamic"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    SIGNATURE_movement* iMovement = new SIGNATURE_movement();
    this->set_movement(iMovement);
}

std::string BODY_dynamic::get_id(){
    return this->id;
}

void BODY_dynamic::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* BODY_dynamic::get_mesh(){
    return this->mesh;
}

void BODY_dynamic::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

SIGNATURE_movement* BODY_dynamic::get_movement(){
    return this->movement;
}

void BODY_dynamic::set_movement(SIGNATURE_movement* value){
    this->movement = value;
}

void BODY_dynamic::physic(const std::vector<Body*>& objects){

}

void BODY_dynamic::object_collide(const std::vector<Body*>& objects){

}

void BODY_dynamic::Display(){
    this->get_mesh()->Execute();
}

void BODY_dynamic::Execute(const std::vector<Body*>& objects){
    this->get_movement()->Execute(this->get_mesh());
    this->physic(objects);
    this->Display();
}