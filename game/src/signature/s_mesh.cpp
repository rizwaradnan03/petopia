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

Texture SIGNATURE_mesh::get_texture(){
    return this->texture;
}

void SIGNATURE_mesh::set_texture(Texture value){
    this->texture = value;
}

float SIGNATURE_mesh::get_right_position(){
    return this->get_value().x + this->get_value().w;
}

float SIGNATURE_mesh::get_left_position(){
    return this->get_value().x;
}

float SIGNATURE_mesh::get_top_position(){
    return this->get_value().y;
}

float SIGNATURE_mesh::get_bottom_position(){
    return this->get_value().y + this->get_value().h;
}

void SIGNATURE_mesh::Execute(){
    MeshInit m = this->get_value();

    Rectangle source = {0.0f, 0.0f, m.w, m.h};
    Rectangle dest = {m.x, m.y, m.w, m.h};

    Vector2 origin = {0, 0};

    // DrawTextureRec(m.texture, source, position, WHITE);
    DrawTexturePro(m.texture, source, dest, origin, 0.0f, WHITE);
}