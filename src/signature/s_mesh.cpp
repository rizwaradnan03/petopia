#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(MeshInit value){
    this->set_value(value);
}

MeshInit& SIGNATURE_mesh::get_value(){
    return this->value;
}

void SIGNATURE_mesh::set_value(MeshInit value){
    this->value = value;
}

Texture2D SIGNATURE_mesh::get_texture(){
    return this->texture;
}

void SIGNATURE_mesh::set_texture(Texture2D value){
    this->texture = value;
}

float SIGNATURE_mesh::get_right_position(){
    return this->get_value().x + (this->get_value().w / 2);
}

float SIGNATURE_mesh::get_left_position(){
    return this->get_value().x - (this->get_value().w / 2);
}

float SIGNATURE_mesh::get_top_position(){
    return this->get_value().y + (this->get_value().h / 2);
}

float SIGNATURE_mesh::get_bottom_position(){
    return this->get_value().y - (this->get_value().h / 2);
}

void SIGNATURE_mesh::Execute(){
    MeshInit m = this->get_value();

    Rectangle source = {0, 0, m.w, m.h};
    Vector2 position = {m.x, m.y};

    DrawTextureRec(m.texture, source, position, WHITE);
}