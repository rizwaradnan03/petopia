#include <namespace/n_file.h>

namespace file {
    std::vector<std::pair<std::string, VariantType>> read_whole_file_data(std::string path, std::string* search){
        std::string fPath = "storage/" + path;
        std::ifstream file(fPath);

        if(file.is_open() == false){
            return {};
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string strizedBuf = buffer.str();
        return read_data(strizedBuf, search);
    }

    std::vector<std::pair<std::string, VariantType>> read_data(std::string& dataString, std::string* search){
        std::vector<std::pair<std::string, VariantType>> ret;
        
        uint16_t sz = dataString.size();
        
        std::string parentKey = "";
        for(int i = 0;i < sz;i++){
            if(dataString[i] == '\"'){
                if(parentKey.size() == 0){
                    int j = i + 1;
                    while(dataString[j] != '\"'){
                        parentKey += dataString[j];
                        j++;
                    }

                    i = j;

                }
            }else{
                if(dataString[i] == ':' && parentKey.size() > 0 && (dataString[i + 1] == '\"' || dataString[i + 2] == '\"' || dataString[i + 3] == '\"')){
                    std::string key = "";
                    std::string val = "";

                    int kQ = 0;
                    int vQ = 0;

                    
                    int kP = i;
                    while(kQ < 2){
                        if(dataString[kP] == '\"'){
                            kQ++;
                        }
                        
                        if(kQ == 1 && dataString[kP] != '\"'){
                            key += dataString[kP];
                        }
                        
                        kP--;
                    }

                    int vP = i;
                    while(vQ < 2){
                        if(dataString[vP] == '\"'){
                            vQ++;
                        }

                        if(vQ == 1 && dataString[vP] != '\"'){
                            val += dataString[vP];
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
                }else if(dataString[i] == ']'){
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