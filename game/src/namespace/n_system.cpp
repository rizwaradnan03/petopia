#include <namespace/n_system.h>

namespace sys {
    std::pair<int, int> get_screen_resolution(){
        int w = get_resolution_width();
        int h = get_resolution_height();

        return std::make_pair(w, h);
    }

    int get_resolution_width(){
        return GetScreenWidth();
    }

    int get_resolution_height(){
        return GetScreenHeight();
    }

    std::pair<int, int> get_half_resolution(){
        std::pair<int, int> res = get_screen_resolution();

        return std::make_pair(res.first / 2, res.second / 2);
    }

    int get_half_width(){
        return get_resolution_width() / 2;
    }

    int get_half_height(){
        return get_resolution_height() / 2;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> get_current_time(){
        return std::chrono::high_resolution_clock::now();
    }
};