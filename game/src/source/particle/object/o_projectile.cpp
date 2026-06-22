#include <source/particle/object/o_projectile.h>

OBJECT_projectile::OBJECT_projectile(MeshInit meshInit, DtoCollider* collider, DtoProjectileAcceleration, DtoTextureType keyType): BODY_static(meshInit, collider){
    this->set_id(identifier::generate_id("body_static"));

    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_collider(collider);

    std::vector<VariantType> pVar = entity::get_projectile_by_dto_texture_type(keyType);
    uint16_t dmg = std::get<uint16_t>(pVar[2]);

    this->set_damage(dmg);
}

OBJECT_projectile::~OBJECT_projectile(){
    delete this->get_mesh();
}

std::string& OBJECT_projectile::get_id(){
    return this->id;
}

void OBJECT_projectile::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* OBJECT_projectile::get_mesh(){
    return this->mesh;
}

void OBJECT_projectile::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoCollider& OBJECT_projectile::get_collider(){
    return *this->collider;
}

void OBJECT_projectile::set_collider(DtoCollider* value){
    this->collider = value;
}

DtoProjectileAcceleration& OBJECT_projectile::get_acceleration(){
    return this->acceleration;
}

void OBJECT_projectile::set_acceleration(DtoProjectileAcceleration value){
    this->acceleration = value;
}

uint16_t OBJECT_projectile::get_damage(){
    return this->damage;
}

void OBJECT_projectile::set_damage(uint16_t value){
    this->damage = value;
}

void OBJECT_projectile::action(){
    this->acceleration_action();
}

void OBJECT_projectile::acceleration_action(){
    DtoProjectileAcceleration mAccelerat = this->get_acceleration();
    SIGNATURE_mesh* mMesh = this->get_mesh();
    
    float turnX = 0;
    float turnY = 0;

    if(mesh->get_value().x != mAccelerat.target_x){
        float acl = mAccelerat.acceleration_x;
        if(mAccelerat.rev_x == true){
            acl *= -1;
        }

        turnX = this->get_mesh()->get_value().x + acl;
        if(mAccelerat.rev_x == true){
            if(turnX <= mAccelerat.target_x){
                turnX = mAccelerat.target_x;
            }
        }else{
            if(turnX >= mAccelerat.target_x){
                turnX = mAccelerat.target_x;
            }
        }
    }

    if(mesh->get_value().y != mAccelerat.target_y){
        float acl = mAccelerat.acceleration_y;
        if(mAccelerat.rev_y == true){
            acl *= -1;
        }

        turnY = this->get_mesh()->get_value().y + acl;
        if(mAccelerat.rev_y == true){
            if(turnY <= mAccelerat.target_y){
                turnY = mAccelerat.target_y;
            }
        }else{
            if(turnY >= mAccelerat.target_y){
                turnY = mAccelerat.target_y;
            }
        }
    }

    this->get_mesh()->get_value().x = turnX;
    this->get_mesh()->get_value().x = turnY;

    mMesh = this->get_mesh(); // callout
    if(mMesh->get_value().x == mAccelerat.target_x && mMesh->get_value().y == mAccelerat.target_y){
        delete this;
    }
}

void OBJECT_projectile::Execute(const std::vector<Body*>& objects){
    this->Display();
    this->action();
}

void OBJECT_projectile::Display(){
    this->get_mesh()->Execute();
}