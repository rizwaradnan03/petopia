#include <signature/s_movement.h>

SIGNATURE_movement::SIGNATURE_movement(){
    this->reset_avail();
}

void SIGNATURE_movement::Execute(SIGNATURE_mesh* mesh){
    float x = mesh->get_value().x;

    float mov = 2.0f;
    if(IsKeyDown(KEY_D)){
        if(this->get_available_direction()[0] == true){
            x += mov;
        }
    }else if(IsKeyDown(KEY_A)){
        if(this->get_available_direction()[1]){
            x -= mov;
        }
    }

    if(IsKeyDown(KEY_SPACE)){
        if(this->get_available_direction()[2]){
            if(this->get_jump_stock() > 0){
                this->set_jump_stock(this->get_jump_stock() - 1);
                this->set_elapse_jump(new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now()));
            }
        }
    }

    if(this->get_available_direction()[2] == true){
        if(this->get_elapse_jump() != nullptr){ // move up
            std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();
            
            std::chrono::duration<float> differ = currentTime - *this->get_elapse_jump();
            if(differ.count() < 0.5f){
                mesh->get_value().y -= mov;
            }else{
                this->set_elapse_jump(nullptr);
            }
        }
    }

    if(this->get_available_direction()[3] == true){
        if(this->get_elapse_jump() == nullptr){ // gravity
            mesh->get_value().y += mov;
        }
    }else{
        this->set_elapse_jump(nullptr);
        this->set_jump_stock(3);
    }

    mesh->get_value().x = x;
    this->reset_avail();
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

std::vector<bool> SIGNATURE_movement::get_available_direction(){
    return this->available_direction;
}

void SIGNATURE_movement::set_available_direction(std::vector<bool> value){
    this->available_direction = value;
}

void SIGNATURE_movement::reset_avail(){
    this->set_available_direction({true, true, true, true});
}
