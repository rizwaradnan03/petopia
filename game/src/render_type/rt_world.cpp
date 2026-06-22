#include <render_type/rt_world.h>

RENDER_TYPE_world::RENDER_TYPE_world(std::string worldName): RenderType(){
    std::string strized = "render/world/" + worldName;
    std::vector<std::pair<std::string, VariantType>> datas = file::read_whole_file_data(strized, new std::string("block"));

    std::vector<Body*> obj;
    
    std::pair<std::string, float> x = std::make_pair("block_x_1", 0.0);
    std::pair<std::string, float> y = std::make_pair("block_y_1", 0.0);
    std::pair<std::string, float> w = std::make_pair("block_w_1", 0.0);
    std::pair<std::string, float> h = std::make_pair("block_h_1", 0.0);
    std::pair<std::string, DtoTextureType> tx = std::make_pair("block_texture_1", DtoTextureType::BLOCK_DIRT);

    bool hasX = false;
    bool hasY = false;
    bool hasW = false;
    bool hasH = false;
    bool hasTX = false;

    for(int i = 0;i < datas.size();i++){
        std::string* dir = nullptr;
        std::string dpl;

        try{
            float val = std::get<float>(datas[i].second);
            if(datas[i].first == x.first){
                hasX = true;
                x.second = val;
                dir = new std::string("x");
                dpl = x.first;
            }else if(datas[i].first == y.first){
                hasY = true;
                y.second = val;
                dir = new std::string("y");
                dpl = y.first;
            }else if(datas[i].first == w.first){
                hasW = true;
                w.second = val;
                dir = new std::string("w");
                dpl = w.first;
            }else if(datas[i].first == h.first){
                hasH = true;
                h.second = val;
                dir = new std::string("h");
                dpl = h.first;
            }
        }catch(...){
            if(datas[i].first == tx.first){
                hasTX = true;
                dir = new std::string("tx");
                if(std::holds_alternative<std::string>(datas[i].second)){
                    std::string strf = std::get<std::string>(datas[i].second);
                    tx.second = *entity::get_texture_type_by_name(strf);
                }
    
                dpl = tx.first;
            }
        }

        
        if(dir != nullptr){ // replacing
            std::string cnt = "";
            for(int j = dpl.size() - 1;j >= 0;j--){
                if(dpl[j] == '_'){
                    break;
                }

                cnt += dpl[j];
            }

            for(int j = 0;j < cnt.size() / 2;j++){
                char tmp = cnt[(cnt.size() - (1 + j))];
                cnt[(cnt.size() - (1 + j))] = cnt[j];
                cnt[j] = tmp;
            }

            int nbrized = std::stoi(cnt);
            nbrized++;

            cnt = std::to_string(nbrized);
            for(int j = cnt.size() - 1;j >= 0;j--){
                if(*dir == "x"){
                    x.first[x.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == "y"){
                    y.first[y.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == "w"){
                    w.first[w.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == "h"){
                    h.first[h.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == "tx"){
                    tx.first[tx.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }
            }
        }

        if(hasX == true && hasY == true && hasW == true && hasH == true && hasTX == true){
            DtoCollider* col = new DtoCollider();
            col->layer = 1;
            col->mask = {};
            
            MeshInit mesh;
            mesh.x = x.second;
            mesh.y = y.second;
            mesh.w = w.second;
            mesh.h = h.second;
            mesh.texture = G_cache->get_by_texture_type_object(tx.second);

            Body* bd = new BODY_static(mesh, col);
    
            hasX = false;
            hasY = false;
            hasW = false;
            hasH = false;
            hasTX = false;

            obj.push_back(bd);
        }

        delete dir;
    }

    this->set_objects(obj);
}

RENDER_TYPE_world::~RENDER_TYPE_world(){
    std::vector<Body*> obj = this->get_objects();
    for(int i = 0;i < obj.size();i++){
        delete obj[i];
    }
}

bool RENDER_TYPE_world::delete_checker(void* mem){
    if(mem != nullptr){
        return false;
    }

    return true;
}

std::vector<Body*> RENDER_TYPE_world::get_objects(){
    return this->objects;
}

void RENDER_TYPE_world::set_objects(std::vector<Body*> value){
    this->objects = value;
}

void RENDER_TYPE_world::Execute(){
    std::vector<Body*> objs = this->get_objects();

    for(int i = 0;i < objs.size();i++){
        Body* b = objs[i];
        
        bool c = this->delete_checker(b);
        if(c == true){
            this->get_objects().erase(this->get_objects().begin() + i);
            i--;
            continue;
        }

        b->Execute(objs);
    }
}