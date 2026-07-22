#include <nodes/2d/oth/oth_projectile.h>

OTHER_projectile::OTHER_projectile(DtoProjectileAcceleration target, DtoProjectileValue profle): OTHER_particle(){
    this->set_target(target);
    this->set_profile(profile);
}

OTHER_projectile::~OTHER_projectile(){
    delete this->get_mesh();
}

DtoProjectileAcceleration OTHER_projectile::get_target(){
    return this->target;
}

void OTHER_projectile::set_target(DtoProjectileAcceleration value){
    this->target = value;
}

DtoProjectileValue OTHER_projectile::get_profile(){
    return this->profile;
}

void OTHER_projectile::set_profile(DtoProjectileValue value){
    this->profile = value;
}

SIGNATURE_mesh* OTHER_projectile::get_mesh(){
    return this->mesh;
}

void OTHER_projectile::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

SIGNATURE_attack* OTHER_projectile::get_attack(){
    return this->attack;
}

void OTHER_projectile::set_attack(SIGNATURE_attack* value){
    this->attack = value;
}

void OTHER_projectile::Display(){ // WE'RE NOT GONNA RENDER VIA MESH, we do this instead
    Texture tx = this->get_profile().texture; // TAKEN from the profile
    SIGNATURE_mesh* m = this->get_mesh();

    Rectangle source = {0.0f, 0.0f, m->get_value().w, m->get_value().h};
    Rectangle dest = {m->get_value().x, m->get_value().y, m->get_value().w, m->get_value().h};

    Vector2 origin = {0, 0};

    DrawTexturePro(tx, source, dest, origin, 0.0f, WHITE);
}

void OTHER_projectile::Execute(){ 
    this->Display();
}

void OTHER_projectile::action(){
    SIGNATURE_mesh* m = this->get_mesh();
    DtoProjectileAcceleration tg = this->get_target();

    if(m->get_value().x == tg.target_x && m->get_value().y == tg.target_y){
        delete this;
    }

    float cX = tg.rev_x == false ? m->get_value().x + tg.acceleration_x : m->get_value().x - tg.acceleration_x;
    float cY = tg.rev_y == false ? m->get_value().y + tg.acceleration_y : m->get_value().y - tg.acceleration_y;

    // OVER CHECKER
    if(tg.rev_x == true){ 
        if(cX >= tg.target_x) cX = tg.target_x;
    }else{
        if(cX <= tg.target_x) cX = tg.target_x;
    }

    if(tg.rev_y == true){ 
        if(cY >= tg.target_y) cY = tg.target_y;
    }else{
        if(cY <= tg.target_y) cY = tg.target_y;
    }
}