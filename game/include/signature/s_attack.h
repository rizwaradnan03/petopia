#ifndef SIGNATURE_ATTACK_H
#define SIGNATURE_ATTACK_H

#include <dto/dto_attack.h>

class SIGNATURE_attack {
    public:
        SIGNATURE_attack(DtoAttack value);
        ~SIGNATURE_attack();

        DtoAttack get_value();
        void set_value(DtoAttack value);

    private:
        DtoAttack value;
};

#endif