#include <nodes/2d/gui/gui_container.h>

GUI_container::GUI_container(MeshInit meshInit, DtoPoleset* poleSet){
    SIGNATURE_mesh* iMesh = new SIGNATURE_mesh(meshInit);
    this->set_mesh(iMesh);

    this->set_poleset(poleSet);
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

void GUI_container::Display(){
    this->get_mesh()->Execute();

    std::vector<Gui*> nds = this->get_nodes();
    for(int i = 0;i < nds.size();i++){
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