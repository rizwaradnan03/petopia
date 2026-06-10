#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(MeshInit value){
    this->set_x(value.x);
    this->set_y(value.y);
}

int SIGNATURE_mesh::get_x(){
    return this->x;
}

void SIGNATURE_mesh::set_x(int value){
    this->x = value;
}

int SIGNATURE_mesh::get_y(){
    return this->y;
}

void SIGNATURE_mesh::set_y(int value){
    this->y = value;
}

Texture2D SIGNATURE_mesh::get_texture(){
    return this->texture;
}

void SIGNATURE_mesh::set_texture(Texture2D value){
    this->texture = value;
}