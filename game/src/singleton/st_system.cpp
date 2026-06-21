#include <singleton/st_system.h>

SINGLETON_system* G_system = nullptr;

SINGLETON_system::SINGLETON_system(){
    CURL* crl;
    this->set_curl(crl);
}

CURL* SINGLETON_system::get_curl(){
    return this->curl;
}

void SINGLETON_system::set_curl(CURL* value){
    this->curl = value;
}

std::string* SINGLETON_system::get_access_token(){
    return this->access_token;
}

void SINGLETON_system::set_access_token(std::string* value){
    this->access_token = value;
}

std::vector<std::pair<std::string, VariantType>> SINGLETON_system::get_attribute(){
    return this->attribute;
}

void SINGLETON_system::set_attribute(std::vector<std::pair<std::string, VariantType>> value){
    this->attribute = value;
}

std::string* auth_login(DtoCurl curlDto){
    std::vector<std::pair<std::string, VariantType>> val;

    return nullptr;
}

std::vector<std::pair<std::string, VariantType>> SINGLETON_system::get_fetch(DtoCurl curlDto){
    try{
        CURLcode res;        
        std::string resp;

        curl_global_init(CURL_GLOBAL_DEFAULT);

        curl = curl_easy_init();
        if(!this->get_curl()){
            return {};
        }

        curl_easy_setopt(this->get_curl(), CURLOPT_URL, curlDto.uri); // write the target
        curl_easy_setopt(this->get_curl(), CURLOPT_WRITEFUNCTION, callback::write_curl); // write the callback
        curl_easy_setopt(this->get_curl(), CURLOPT_WRITEDATA, &resp); // write the response 

        res = curl_easy_perform(this->get_curl()); // do!
        if(res == CURLE_OK){
            std::cout << "response : " << resp << std::endl;
        }

        curl_easy_cleanup(this->get_curl());
        curl_global_cleanup();

        std::vector<std::pair<std::string, VariantType>> toRet = file::read_data(resp, nullptr);

        return toRet;
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    return {};
}

void SINGLETON_system::set_post(DtoCurl curlDto){
    
}