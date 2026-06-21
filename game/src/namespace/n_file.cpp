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
                if(parentKey.size() == 0){
                    int j = i + 1;
                    while(strizedBuf[j] != '\"'){
                        parentKey += strizedBuf[j];
                        j++;
                    }

                    i = j;

                }
            }else{
                if(strizedBuf[i] == ':' && parentKey.size() > 0 && (strizedBuf[i + 1] == '\"' || strizedBuf[i + 2] == '\"' || strizedBuf[i + 3] == '\"')){
                    std::string key = "";
                    std::string val = "";

                    int kQ = 0;
                    int vQ = 0;

                    
                    int kP = i;
                    while(kQ < 2){
                        if(strizedBuf[kP] == '\"'){
                            kQ++;
                        }
                        
                        if(kQ == 1 && strizedBuf[kP] != '\"'){
                            key += strizedBuf[kP];
                        }
                        
                        kP--;
                    }

                    int vP = i;
                    while(vQ < 2){
                        if(strizedBuf[vP] == '\"'){
                            vQ++;
                        }

                        if(vQ == 1 && strizedBuf[vP] != '\"'){
                            val += strizedBuf[vP];
                        }

                        vP++;
                    }
                    
                    i = vP;

                    for(int j = 0;j < key.size() / 2;j++){
                        char tmp = key[key.size() - (1 + j)];
                        key[key.size() - (1 + j)] = key[j];
                        key[j] = tmp;
                    }

                    if(key == parentKey){
                        key = "";
                    }
                    
                    std::string nmfied = parentKey + "_" + key;

                    uint8_t nm = 1;
                    for(int j = 0;j < ret.size();j++){
                        if(ret[j].first[0] == nmfied[0]){
                            for(int k = 0;k < nmfied.size();k++){
                                if(nmfied[k] != ret[j].first[k]){
                                    break;
                                }

                                if(k == nmfied.size() - 1){
                                    nm++;
                                }
                            }
                        }
                    }

                    nmfied += ((key.size() > 0 ? "_" : "") + std::to_string(nm));
                    ret.push_back(std::make_pair(nmfied, val));
                }else if(strizedBuf[i] == ']'){
                    parentKey = "";
                }
            }
        }

        for(int i = 0;i < ret.size();i++){
            bool isFloat = false;
        
            std::string ctVal = std::get<std::string>(ret[i].second);

            try{
                bool isNum = true;
                for(int j = 0;j < ctVal.size();j++){
                    if(ctVal[j] == '.'){
                        int nmbr = ctVal[j] - '0';
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