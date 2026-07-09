#include <nodes/2d/gui/gui_container.h>

GUI_container::GUI_container(DtoRawMesh rawMesh, DtoPoleset* poleSet): Gui(rawMesh, poleSet){
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(rawMesh);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
}

GUI_container::~GUI_container(){
    delete this->get_mesh();

    std::vector<GUI_action*> nd = this->get_nodes();
    for(int i = 0;i < nd.size();i++){
        delete nd[i];
    }
}

bool GUI_container::delete_checker(void* mem){
    if(mem != nullptr){
        return false;
    }
    
    return true;
}

SIGNATURE_mesh* GUI_container::get_mesh(){
    return this->mesh;
}

void GUI_container::set_mesh(SIGNATURE_mesh* value){
    this->mesh = value;
}

DtoPoleset* GUI_container::get_poleset(){
    return this->poleset;
}

void GUI_container::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

std::vector<GUI_action*> GUI_container::get_nodes(){
    return this->nodes;
}

void GUI_container::set_nodes(std::vector<GUI_action*> value){
    this->nodes = value;
}

void GUI_container::set_push_nodes(GUI_action* value){
    this->nodes.push_back(value);
}

void GUI_container::Display(){
    this->get_mesh()->Execute();

    std::vector<GUI_action*> nds = this->get_nodes();
    for(int i = 0;i < nds.size();i++){
        GUI_action* g = nds[i];
        
        bool c = this->delete_checker(g);
        if(c == true){
            this->get_nodes().erase(this->get_nodes().begin() + i);
            i--;
            continue;
        }

        nds[i]->Execute(this->get_mesh());
    }
}

void GUI_container::UpdateDrill(SIGNATURE_mesh* meshDrill){
    if(meshDrill == nullptr){
        return; // static stuff
    }

    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    float curX = this->get_mesh()->get_value().x;
    float curY = this->get_mesh()->get_value().y;

    this->get_mesh()->get_value().x = curX + this->get_poleset()->x;
    this->get_mesh()->get_value().y = curY + this->get_poleset()->y;
}

void GUI_container::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display();
}