#include <nodes/2d/body/body_static.h>

BODY_static::BODY_static(DtoRawMesh rawMesh, DtoCollider* collider): Body(rawMesh, collider){
    this->set_id(identifier::generate_id("body_static"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    this->set_collider(collider);
}

BODY_static::~BODY_static(){
    delete this->get_mesh();
}

std::string& BODY_static::get_id(){
    return this->id;
}

void BODY_static::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* BODY_static::get_mesh(){
    return this->mesh;
}

void BODY_static::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoCollider& BODY_static::get_collider(){
    return *this->collider;
}

void BODY_static::set_collider(DtoCollider* value){
    this->collider = value;
}

void BODY_static::Display(){
    this->get_mesh()->Execute();
}

void BODY_static::Execute(const std::vector<Body*>& objects){
    this->Display();
}