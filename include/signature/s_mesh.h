#ifndef SIGNATURE_MESH
#define SIGNATURE_MESH

#include <dto/dto_signature_mesh.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(MeshInit value);

        MeshInit& get_value();
        void set_value(MeshInit value);

        Texture2D get_texture();
        void set_texture(Texture2D value);

        void Execute();

    private:
        MeshInit value;
        Texture2D texture;
};

#endif