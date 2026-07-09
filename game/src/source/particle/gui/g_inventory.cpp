#include <source/particle/gui/g_inventory.h>
#include <source/particle/object/o_player.h>

GUI_inventory::GUI_inventory(DtoRawMesh rawMesh, DtoPoleset* poleSet): GUI_container(rawMesh, poleSet){
    this->set_id(identifier::generate_id("gui_inventory"));
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

GUI_inventory::~GUI_inventory(){
    delete this->get_mesh();

    std::vector<GUI_action*> nd = this->get_nodes();
    for(int i = 0;i < nd.size();i++){
        delete nd[i];
    }
}

bool GUI_inventory::delete_checker(void* mem){
    if(mem != nullptr){
        return false;
    }
    
    return true;
}

std::string& GUI_inventory::get_id(){
    return this->id;
}

void GUI_inventory::set_id(std::string value){
    this->id = value;
}

SIGNATURE_mesh* GUI_inventory::get_mesh(){
    return this->mesh;
}

void GUI_inventory::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_inventory::get_poleset(){
    return this->poleset;
}

void GUI_inventory::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

std::vector<GUI_action*> GUI_inventory::get_nodes(){
    return this->nodes;
}

void GUI_inventory::set_nodes(std::vector<GUI_action*> value){
    this->nodes = value;
}

std::string* GUI_inventory::get_selected_item_id(){
    return this->selected_item_id;
}

void GUI_inventory::set_selected_item_id(std::string* value){
    this->selected_item_id = value;
}

void GUI_inventory::set_push_nodes(GUI_action* value){
    this->nodes.push_back(value);
}

void GUI_inventory::Display(){
    this->get_mesh()->Execute();

    std::vector<GUI_action*> nds = this->get_nodes();
    for(int i = 0;i < nds.size();i++){
        GUI_action* g = nds[i];

        bool b = this->delete_checker(g);
        if(b == true){
            this->get_nodes().erase(this->get_nodes().begin() + i);
            i--;
            continue;
        }

        g->Execute(this->get_mesh());
    }
}

void GUI_inventory::UpdateDrill(SIGNATURE_mesh* meshDrill){
    if(meshDrill == nullptr){
        return;
    }

    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    DtoPoleset* pSet = this->get_poleset();

    float calcX = xDr + pSet->x;
    float calcY = yDr + pSet->y;

    this->get_mesh()->get_value().x = calcX;
    this->get_mesh()->get_value().y = calcY;
}

void GUI_inventory::action(){
    this->select_item_action();
}

void GUI_inventory::select_item_action(){
    std::vector<GUI_action*> nd = this->get_nodes();
    for(int i = 0;i < nd.size();i++){
        SIGNATURE_mesh* ndMesh = nd[i]->get_mesh();

        int right = ndMesh->get_right_position();
        int left = ndMesh->get_left_position();
        int top = ndMesh->get_top_position();
        int bottom = ndMesh->get_bottom_position();

        if(right && left && top && bottom){
            if(this->get_selected_item_id() != nullptr){
                if(nd[i]->get_id() == *this->get_selected_item_id()){
                    UNI_item* cstAction = dynamic_cast<UNI_item*>(nd[i]);
                    G_object_player->set_hold_item(cstAction);
                }
            }else{
                std::string* refId = &nd[i]->get_id();
                this->set_selected_item_id(refId);
            }
        }
    }
}

void GUI_inventory::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display();

    std::cout << "Y INVENTORY : " << this->get_mesh()->get_value().y << std::endl;

    this->action();
}