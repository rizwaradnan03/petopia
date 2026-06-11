#ifndef SIGNATURE_MOVEMENT_H
#define SIGNATURE_MOVEMENT_H

#include <config/c_pch.h>
#include <signature/s_mesh.h>

class SIGNATURE_movement {
    public:
        void Execute(SIGNATURE_mesh* mesh);
    
        std::string get_movement_state();
        void set_movement_state(std::string value);

        uint8_t get_jump_stock();
        void set_jump_stock(uint8_t value);

        std::chrono::time_point<std::chrono::high_resolution_clock>* get_elapse_jump();
        void set_elapse_jump(std::chrono::time_point<std::chrono::high_resolution_clock>* value);

    private:
        std::string movement_state;
        uint8_t jump_stock;
        std::chrono::time_point<std::chrono::high_resolution_clock>* elapse_jump;
};

#endif