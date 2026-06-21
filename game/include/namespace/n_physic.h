#ifndef NAMESPACE_PHYSIC
#define NAMESPACE_PHYSIC

#include <config/c_pch.h>
#include <nodes/2d/body/body.h>

namespace physic {
    std::string* check_collide(Body* me, Body* target);
};

#endif