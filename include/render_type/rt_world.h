#ifndef RENDER_TYPE_WORLD
#define RENDER_TYPE_WORLD

#include <render_type/rt.h>
#include <nodes/2d/body/body.h>
#include <render_type/rt.h>

class RENDER_TYPE_world: public RenderType {
    public:
        RENDER_TYPE_world(std::vector<Body*> objects);

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);

    private:
        std::vector<Body*> objects;
};

#endif