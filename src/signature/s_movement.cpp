#include <signature/s_movement.h>

void SIGNATURE_movement::Execute(SIGNATURE_mesh* mesh){
    float x = mesh->get_x();

    float mov = 2.0f;
    if(IsKeyDown(KEY_D)){
        x += mov;
    }else if(IsKeyDown(KEY_A)){
        x -= mov;
    }

    if(IsKeyDown(KEY_SPACE)){
        if(this->get_jump_stock() > 0){
            this->set_jump_stock(this->get_jump_stock() - 1);
            this->set_elapse_jump(new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now()));
        }
    }

    mesh->set_x(x);
}

std::string SIGNATURE_movement::get_movement_state(){
    return this->movement_state;
}

void SIGNATURE_movement::set_movement_state(std::string value){
    this->movement_state = value;
}

uint8_t SIGNATURE_movement::get_jump_stock(){
    return this->jump_stock;
}

void SIGNATURE_movement::set_jump_stock(uint8_t value){
    this->jump_stock = value;
}

std::chrono::time_point<std::chrono::high_resolution_clock>* SIGNATURE_movement::get_elapse_jump(){
    return this->elapse_jump;
}

void SIGNATURE_movement::set_elapse_jump(std::chrono::time_point<std::chrono::high_resolution_clock>* value){
    this->elapse_jump = value;
}