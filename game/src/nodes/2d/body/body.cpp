#include <nodes/2d/body/body.h>

Body::Body(MeshInit meshInit, DtoCollider* collider){
    this->set_id(identifier::generate_id("body"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);
    this->set_collider(collider);
}

Body::~Body(){
    delete this->get_mesh();
}

std::string& Body::get_id(){
    return this->id;
}

void Body::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* Body::get_mesh(){
    return this->mesh;
}

void Body::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoCollider& Body::get_collider(){
    return *this->collider;
}

void Body::set_collider(DtoCollider* value){
    this->collider = value;
}

void Body::Display(){
    this->get_mesh()->Execute();
}

void Body::Execute(const std::vector<Body*>& objects){
    this->Display();
}