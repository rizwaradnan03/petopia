#ifndef SIGNATURE_MESH
#define SIGNATURE_MESH

#include <dto/dto_signature_mesh.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(MeshInit value);

        MeshInit& get_value();
        void set_value(MeshInit value);

        Texture get_texture();
        void set_texture(Texture value);

        float get_right_position();
        float get_left_position();
        float get_top_position();
        float get_bottom_position();

        void Execute();

    private:
        MeshInit value;
        Texture texture;
};

#endif