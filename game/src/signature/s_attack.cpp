#include <signature/s_attack.h>

SIGNATURE_attack::SIGNATURE_attack(DtoAttack value){
    this->set_value(value);
}

SIGNATURE_attack::~SIGNATURE_attack(){}

DtoAttack SIGNATURE_attack::get_value(){
    return this->value;
}

void SIGNATURE_attack::set_value(DtoAttack value){
    this->value = value;
}