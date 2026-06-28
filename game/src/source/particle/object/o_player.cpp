#include <source/particle/object/o_player.h>

OBJECT_player* G_object_player = nullptr;

OBJECT_player::OBJECT_player(MeshInit meshInit, DtoCollider* collider): BODY_dynamic(meshInit, collider){
    this->set_id(identifier::generate_id("object_player"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    SIGNATURE_movement* iMovement = new SIGNATURE_movement();
    this->set_movement(iMovement);

    this->set_collider(collider);

    std::pair<int, int> hRes = sys::get_half_resolution();

    Camera2D cam = {0};
    cam.target = (Vector2){iMesh->get_value().x, iMesh->get_value().y};
    cam.offset = (Vector2){static_cast<float>(hRes.first), static_cast<float>(hRes.second)};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    SIGNATURE_camera* iCam = new SIGNATURE_camera(cam); 
    this->set_camera(iCam);

    G_object_player = this;
}

std::string& OBJECT_player::get_id(){
    return this->id;
}

void OBJECT_player::set_id(std::string value){
    this->id = value;
}

SIGNATURE_camera* OBJECT_player::get_camera(){
    return this->camera;
}

void OBJECT_player::set_camera(SIGNATURE_camera* value){
    this->camera = value;
}

SIGNATURE_mesh* OBJECT_player::get_mesh(){
    return this->mesh;
}

void OBJECT_player::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

SIGNATURE_movement* OBJECT_player::get_movement(){
    return this->movement;
}

void OBJECT_player::set_movement(SIGNATURE_movement* value){
    this->movement = value;
}

DtoCollider& OBJECT_player::get_collider(){
    return *this->collider;
}

void OBJECT_player::set_collider(DtoCollider* value){
    this->collider = value;
}

std::vector<GUI_container*> OBJECT_player::get_gui_containers(){
    return this->gui_containers;
}

void OBJECT_player::set_gui_containers(std::vector<GUI_container*> value){
    this->gui_containers = value;
}

void OBJECT_player::set_push_gui_containers(GUI_container* value){
    this->gui_containers.push_back(value);
}

UNI_item* OBJECT_player::get_hold_item(){
    return this->hold_item;
}

void OBJECT_player::set_hold_item(UNI_item* value){
    this->hold_item = value;
}

void OBJECT_player::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void OBJECT_player::object_collide(const std::vector<Body*>& objects){
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

void OBJECT_player::Display(){
    this->get_mesh()->Execute();

    std::vector<GUI_container*> gc = this->get_gui_containers();
    for(int i = 0;i < gc.size();i++){
        gc[i]->Execute(this->get_mesh());
    }

    this->get_camera()->Execute(*this->get_mesh());
}

void OBJECT_player::Execute(const std::vector<Body*>& objects){
    this->physic(objects);
    this->get_movement()->Execute(this->get_mesh());
    this->Display();

    std::pair<int, int> res = sys::get_screen_resolution();
}