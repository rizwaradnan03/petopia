#include <namespace/n_physic.h>

namespace physic {
    std::string* check_collide(Body* me, Body* target){
        std::string* dir = nullptr;

        int min_x_me = me->get_mesh()->get_value().x - (me->get_mesh()->get_value().w / 2);
        int max_x_me = me->get_mesh()->get_value().x + (me->get_mesh()->get_value().w / 2);
        int min_y_me = me->get_mesh()->get_value().y - (me->get_mesh()->get_value().h / 2);
        int max_y_me = me->get_mesh()->get_value().y + (me->get_mesh()->get_value().h / 2);

        int min_x_target = target->get_mesh()->get_value().x - (target->get_mesh()->get_value().w / 2);
        int max_x_target = target->get_mesh()->get_value().x + (target->get_mesh()->get_value().w / 2);
        int min_y_target = target->get_mesh()->get_value().y - (target->get_mesh()->get_value().h / 2);
        int max_y_target = target->get_mesh()->get_value().y + (target->get_mesh()->get_value().h / 2);

        if (max_x_me < min_x_target || min_x_me > max_x_target ||
            max_y_me < min_y_target || min_y_me > max_y_target){
            return nullptr;
        }

        int dx = me->get_mesh()->get_value().x - target->get_mesh()->get_value().x;
        int dy = me->get_mesh()->get_value().y - target->get_mesh()->get_value().y;

        if (abs(dx) > abs(dy)){
            return new std::string(dx > 0 ? "LEFT" : "RIGHT");
        }else{
            return new std::string(dy > 0 ? "TOP" : "BOTTOM");
        }

        return dir;
    }
}