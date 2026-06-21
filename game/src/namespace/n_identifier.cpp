#include <namespace/n_identifier.h>

namespace identifier {
    std::string generate_id(const std::string& text){
        auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();

        return std::to_string(timestamp) + "_" + text;
    }

    std::string get_node_type_from_id(std::string& id){
        std::string ret = "";

        bool isCol = false;
        for(int i = id.size() - 1;i >= 0;i--){
            if(id[i] == '_' && isCol == false){
                isCol = true;   
            }else{
                if(isCol == true){
                    ret += id[i];
                }
            }
        }

        for(int i = 0;i < ret.size() / 2;i++){
            char tmp = ret[ret.size() - (1 + i)];
            ret[ret.size() - (1 + i)] = ret[i];
            ret[i] = tmp;
        }

        return ret;
    }
};