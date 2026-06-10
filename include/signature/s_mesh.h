#ifndef SIGNATURE_MESH
#define SIGNATURE_MESH

#include <dto/dto_signature_mesh.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(MeshInit value);

        int get_x();
        void set_x(int value);

        int get_y();
        void set_y(int value);

        Texture2D get_texture();
        void set_texture(Texture2D value);

        void Execute();

    private:
        int x;
        int y;
        Texture2D texture;
};

#endif