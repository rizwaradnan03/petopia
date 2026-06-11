#include <namespace/n_identifier.h>

namespace identifier {
    std::string generate_id(const std::string& text){
        auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();

        return std::to_string(timestamp) + "_" + text;
    }
};