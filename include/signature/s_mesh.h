#ifndef SIGNATURE_MESH
#define SIGNATURE_MESH

#include <dto/dto_signature_mesh.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(MeshInit value);

        float get_x();
        void set_x(float value);

        float get_y();
        void set_y(float value);

        Texture2D get_texture();
        void set_texture(Texture2D value);

        void Execute();

    private:
        float x;
        float y;
        Texture2D texture;
};

#endif