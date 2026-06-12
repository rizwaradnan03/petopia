#include <namespace/n_file.h>

namespace file {
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> read_whole_file_data(std::string path, std::string* search){
        std::vector<std::pair<std::string, std::variant<int, float, std::string>>> ret;

        std::string fPath = "storage/" + path;
        std::ifstream file(fPath);

        if(file.is_open() == false){
            return {};
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string strizedBuf = buffer.str();
        uint16_t sz = strizedBuf.size();

        std::string parentKey = "";
        for(int i = 0;i < sz;i++){
            if(strizedBuf[i] == '\"'){
                int cp;
                for(int j = i + 1;j < sz;j++){
                    if(strizedBuf[j] == '\"'){
                        cp = j + 1;
                        break;
                    }

                    parentKey += strizedBuf[j];
                }

                i = cp;

                std::string key = "";
                std::string val = "";
                bool isValTurn = false;
                for(int j = i;j < sz;j++){
                    bool isDo = false;

                    if(strizedBuf[j] == '\"'){
                        for(int k = j + 1;k < sz;k++){
                            if(strizedBuf[k] == '\"'){
                                i = k;
                                break;
                            }

                            val += strizedBuf[k];
                            
                            ret.push_back(std::make_pair(parentKey, val));
                            parentKey = "";
                            key = "";
                            val = "";
                        }

                        isDo = true;
                    }else if(strizedBuf[j] == '{'){
                        for(int k = j + 1;k < sz;k++){
                            if(strizedBuf[k] != ' ' && strizedBuf[k] != ':' && strizedBuf[k] != '\"' && strizedBuf[k] != ',' && strizedBuf[k] != '}'){
                                if(isValTurn == false){
                                    key += strizedBuf[k];
                                }else{
                                    val += strizedBuf[k];
                                }
                            }else{
                                if(strizedBuf[k] == '\"'){
                                    if(isValTurn == true){
                                        std::string namified = parentKey + "_" + key;
                                        ret.push_back(std::make_pair(namified, val));

                                        key = "";
                                        val = "";
                                        isValTurn = false;
                                    }

                                    if(isValTurn == false){
                                        isValTurn = true;
                                    }
                                }else if(strizedBuf[k] == '}'){
                                    isDo = true;
                                    break;
                                }
                            }
                        }

                    }else if(strizedBuf[j] == '['){
                        for(int k = j + 1;k < sz;k++){
                            if(strizedBuf[k] != ' ' && strizedBuf[k] != ':' && strizedBuf[k] != '\"' && strizedBuf[k] != ',' && strizedBuf[k] != '{' && strizedBuf[k] != '}'){
                                if(isValTurn = false){
                                    key += strizedBuf[k];
                                }else{
                                    val += strizedBuf[k];
                                }
                            }else{
                                if(strizedBuf[k] == '\"'){
                                    if(isValTurn == true){
                                        uint8_t indexOfNaming = 1;

                                        std::string namified = parentKey + "_" + key;

                                        for(int g = 0;g < ret.size();g++){
                                            for(int b = 0;b < namified.size();b++){
                                                if(namified[b] != ret[g].first[b]){
                                                    break;
                                                }

                                                if(b == namified.size() - 1){
                                                    indexOfNaming++;
                                                }
                                            }
                                        }

                                        namified += "_" + indexOfNaming;

                                        ret.push_back(std::make_pair(namified, val));

                                        key = "";
                                        val = "";
                                        isValTurn = false;
                                    }

                                    if(isValTurn == false){
                                        isValTurn = true;
                                    }
                                }else if(strizedBuf[k] == ']'){
                                    isDo = true;
                                    break;
                                }
                            }
                        }
                    }

                    if(isDo = true){
                        i = j;
                        break;
                    }
                }

                parentKey = "";
            }
        }
        
        for(int i = 0;i < ret.size();i++){
            bool isFloat = false;
        
            std::string ctVal = std::get<std::string>(ret[i].second);

            try{
                bool isNum = true;
                for(int j = 0;j < ctVal.size();j++){
                    if(ctVal[j] == '.' && (ctVal[j - 1] - '0')){
                        isNum = false;
                    }
                }

                if(isNum == false){
                    ret[i].second = std::stof(ctVal);
                }else{
                    ret[i].second = std::stoi(ctVal);
                }
            }catch(...){

            }
        }

        if(search != nullptr){
            std::string src = *search;

            for(int i = 0;i < ret.size();i++){
                for(int j = 0;j < src.size();j++){
                    if(src[j] != ret[i].first[j]){
                        ret.erase(ret.begin() + i);

                        break;
                    }
                }
            }
        }

        return ret;
    }
};