#include <render_type/rt_world.h>

RENDER_TYPE_world::RENDER_TYPE_world(std::string worldName): RenderType(){
    std::string strized = "render/world/" + worldName;
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> datas = file::read_whole_file_data(strized, new std::string("block"));

    std::vector<Body*> obj;
    
    std::pair<std::string, float*> x = std::make_pair("block_x_0", nullptr);
    std::pair<std::string, float*> y = std::make_pair("block_y_0", nullptr);
    std::pair<std::string, float*> w = std::make_pair("block_w_0", nullptr);
    std::pair<std::string, float*> h = std::make_pair("block_h_0", nullptr);
    std::pair<std::string, DtoTextureType*> tx = std::make_pair("block_texture_0", nullptr);

    for(int i = 0;i < datas.size();i++){
        char* dir = nullptr;
        std::string dpl;

        float val = std::get<float>(datas[i].second);
        if(datas[i].first == x.first){
            x.second = new float(val);
            dir = new char('x');
            dpl = x.first;        
        }else if(datas[i].first == y.first){
            y.second = new float(val);
            dir = new char('y');
            dpl = y.first;
        }else if(datas[i].first == w.first){
            w.second = new float(val);
            dir = new char('w');
            dpl = w.first;
        }else if(datas[i].first == h.first){
            h.second = new float(val);
            dir = new char('h');
            dpl = h.first;
        }
        
        if(dir != nullptr){
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
                if(*dir == 'x'){
                    x.first[x.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == 'y'){
                    y.first[y.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == 'w'){
                    w.first[w.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }else if(*dir == 'h'){
                    h.first[h.first.size() - (1 + (cnt.size() - (j + 1)))] = cnt[j];
                }
            }
        }

        if(x.second != nullptr && y.second != nullptr && w.second != nullptr && h.second != nullptr){
            DtoCollider* col;
            col->layer = 1;
            col->mask = {};
            
            MeshInit mesh;
            mesh.x = *x.second;
            mesh.y = *y.second;
            mesh.w = *w.second;
            mesh.h = *h.second;
            // mexh.texture = 

            Body* bd = new BODY_static(mesh, col);

            x.second = nullptr;
            y.second = nullptr;
            w.second = nullptr;
            h.second = nullptr;
        }
    }

    this->set_objects(objects);
}

std::vector<Body*> RENDER_TYPE_world::get_objects(){
    return this->objects;
}

void RENDER_TYPE_world::set_objects(std::vector<Body*> value){
    this->objects = value;
}