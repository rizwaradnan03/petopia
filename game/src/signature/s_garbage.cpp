#include <signature/s_garbage.h>

bool SIGNATURE_garbage::delete_checker(void* mem){
    if(mem != nullptr){
        return false;
    }

    return true;
}