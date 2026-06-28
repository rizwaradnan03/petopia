#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(MeshInit value){
    this->set_value(value);

    float xV = value.w / 2;
    float yV = value.h / 2;

    MeshPole mP;
    mP.x = xV;
    mP.y = yV;
    this->set_pole(mP);
}

MeshInit& SIGNATURE_mesh::get_value(){
    return this->value;
}

void SIGNATURE_mesh::set_value(MeshInit value){
    this->value = value;
}

MeshPole& SIGNATURE_mesh::get_pole(){
    return this->pole;
}

void SIGNATURE_mesh::set_pole(MeshPole value){
    this->pole = value;
}

Texture SIGNATURE_mesh::get_texture(){
    return this->texture;
}

void SIGNATURE_mesh::set_texture(Texture value){
    this->texture = value;
}

float SIGNATURE_mesh::get_right_position(){
    return this->get_value().x + this->get_pole().x;
}

float SIGNATURE_mesh::get_left_position(){
    return this->get_value().x - this->get_pole().x;
}

float SIGNATURE_mesh::get_top_position(){
    return this->get_value().y - this->get_pole().y;
}

float SIGNATURE_mesh::get_bottom_position(){
    return this->get_value().y + this->get_pole().y;
}

void SIGNATURE_mesh::Execute(){
    MeshPole mP = this->get_pole();
    MeshInit m = this->get_value();

    // m.x += mP.x;
    // m.y -= mP.y;

    float xV = m.x - mP.x;
    float yV = m.y - mP.y;

    Rectangle source = {0.0f, 0.0f, m.w, m.h};
    Rectangle dest = {xV, yV, m.w, m.h};

    Vector2 origin = {0, 0};

    DrawTexturePro(m.texture, source, dest, origin, 0.0f, WHITE);
}