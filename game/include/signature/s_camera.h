#ifndef SIGNATURE_CAMERA_H
#define SIGNATURE_CAMERA_H

#include <config/c_pch.h>
#include <namespace/n_system.h>
#include <signature/s_mesh.h>

class SIGNATURE_camera {
    public:
        SIGNATURE_camera(Camera2D cam);

        Camera2D get_value();
        void set_value(Camera2D value);

        void Execute(SIGNATURE_mesh& posMesh);

    private:
        Camera2D value;
};

#endif