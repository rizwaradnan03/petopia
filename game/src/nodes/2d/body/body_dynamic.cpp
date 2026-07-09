#include <nodes/2d/body/body_dynamic.h>

BODY_dynamic::BODY_dynamic(DtoRawMesh rawMesh, DtoCollider* collider): Body(rawMesh, collider){
    this->set_id(identifier::generate_id("body_dynamic"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    SIGNATURE_movement* iMovement = new SIGNATURE_movement();
    this->set_movement(iMovement);

    this->set_collider(collider);
}

BODY_dynamic::~BODY_dynamic(){
    delete this->get_mesh();
    delete this->get_movement();
}

std::string& BODY_dynamic::get_id(){
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

DtoCollider& BODY_dynamic::get_collider(){
    return *this->collider;
}

void BODY_dynamic::set_collider(DtoCollider* value){
    this->collider = value;
}

void BODY_dynamic::physic(const std::vector<Body*>& objects){

}

void BODY_dynamic::object_collide(const std::vector<Body*>& objects){
    DtoCollider* colCopy = &this->get_collider();
    if(colCopy == nullptr){
        return;
    }

    bool avail[] = {true, true, true, true};
    for(int i = 0;i < objects.size();i++){
        if(objects[i]->get_id() == this->get_id()){
            continue;
        }

        bool is_caught = false;
        for(int j = 0;j < this->get_collider().mask.size();j++){
            if(this->get_collider().mask[j] == objects[i]->get_collider().layer){
                is_caught = true;
                break;
            }
        }

        if(is_caught == true){
            std::string* colCheck = physic::check_collide(this, objects[i]);
            if(colCheck == nullptr){
                return;
            }

            std::vector<bool> cpy = this->get_movement()->get_available_direction();
            if(*colCheck == "RIGHT"){
                cpy[0] = false;
            }else if(*colCheck == "LEFT"){
                cpy[1] = false;
            }else if(*colCheck == "TOP"){
                cpy[2] = false;
            }else if(*colCheck == "BOTTOM"){
                cpy[3] = false;
            }

            this->get_movement()->set_available_direction(cpy);
        }
    }
}

void BODY_dynamic::Display(){
    this->get_mesh()->Execute();
}

void BODY_dynamic::Execute(const std::vector<Body*>& objects){
    this->physic(objects);
    this->get_movement()->Execute(this->get_mesh());
    this->Display();
}