#ifndef OTHER_PARTICLE_H
#define OTHER_PARTICLE_H

#include <config/c_pch.h>
#include <signature/s_mesh.h>
#include <singleton/st_render.h>

class OTHER_particle {
    public:
        OTHER_particle();
        ~OTHER_particle();
    
        virtual void Execute();
        virtual void Display();
};

#endif