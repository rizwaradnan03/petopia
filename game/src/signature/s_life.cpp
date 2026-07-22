#include <signature/s_life.h>

SIGNATURE_life::SIGNATURE_life(DtoLife value){
    this->set_value(value);
}

SIGNATURE_life::~SIGNATURE_life(){}

DtoLife SIGNATURE_life::get_value(){
    return this->value;
}

void SIGNATURE_life::set_value(DtoLife value){
    this->value = value;
}