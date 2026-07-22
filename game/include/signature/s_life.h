#ifndef SIGNATURE_LIFE_H
#define SIGNATURE_LIFE_H

#include <config/c_pch.h>
#include <dto/dto_life.h>

class SIGNATURE_life {
    public:
        SIGNATURE_life(DtoLife value);
        ~SIGNATURE_life();

        DtoLife get_value();
        void set_value(DtoLife value);

    private:
        DtoLife value;
};

#endif
