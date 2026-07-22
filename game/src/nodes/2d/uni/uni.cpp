#include <nodes/2d/uni/uni.h>

Uni::Uni(std::pair<DtoRawMesh*, DtoRawMesh*> rawMesh, DtoPoleset* poleSet, DtoItemAmount itemAmountDto){ // uni akan di run oleh 2 yaitu player & render type -> as player hanya akan me running core + display gui AND as render type akan run sebagai action
    this->set_id(identifier::generate_id("uni"));
    
    SIGNATURE_mesh* gMesh = nullptr;
    SIGNATURE_mesh* oMesh;

    if(rawMesh.first != nullptr){
      gMesh = new SIGNATURE_mesh(*rawMesh.first);
    }

    if(rawMesh.second != nullptr){
        oMesh = new SIGNATURE_mesh(*rawMesh.second);
    }

    this->set_mesh(std::make_pair(gMesh, oMesh));
    this->set_poleset(poleSet);
    this->set_item_amount(itemAmountDto);
}

Uni::~Uni(){
    delete this->get_gui_mesh();
    delete this->get_object_mesh();

    delete this->get_poleset();
}

std::string& Uni::get_id(){
    return this->id;
}

void Uni::set_id(std::string value){
    this->id = value;
}

std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> Uni::get_mesh(){
    return this->mesh;
}

void Uni::set_mesh(std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> value){
    this->mesh = value;
}

SIGNATURE_mesh* Uni::get_gui_mesh(){
    return this->get_mesh().first;
}

SIGNATURE_mesh* Uni::get_object_mesh(){
    return this->get_mesh().second;
}

std::vector<SIGNATURE_mesh*> Uni::get_nodes(){
    return this->nodes;
}

void Uni::set_nodes(std::vector<SIGNATURE_mesh*> value){
    this->nodes = value;
}

void Uni::set_push_nodes(SIGNATURE_mesh* value){
    this->nodes.push_back(value);
}

void Uni::register_nodes(){ // get the mouse and make own object
    std::pair<float, float> mPos = input::mouse_position_player_as_pole();

    SIGNATURE_mesh* ownObject = new SIGNATURE_mesh(*this->get_object_mesh()); // copy of it
    ownObject->get_value().x = mPos.first;
    ownObject->get_value().y = mPos.second;

    this->set_push_nodes(ownObject);
    G_render->get_select()->set_push_object(std::make_pair(this, ownObject));
}

DtoPoleset* Uni::get_poleset(){
    return this->poleset;
}

void Uni::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

DtoItemAmount& Uni::get_item_amount(){
    return this->item_amount;
}

void Uni::set_item_amount(DtoItemAmount value){
    this->item_amount = value;
}

void Uni::node_action(SIGNATURE_mesh *childAddr){
    // self actions, its like npc doing whichever
}

void Uni::node_render(SIGNATURE_mesh *childAddr){ // -> rendered on render_type
    this->node_action(childAddr);
    childAddr->Execute();
}

void Uni::action(){
    // ?? depends on what to do
}

void Uni::Display(){ // SECOND MESH ACTUALLY AN OBJECT WHICH WE WILL PUSH INTO THE RENDER SYSTEM TO EXECUTE
  SIGNATURE_mesh* gMesh  = this->get_gui_mesh();
  if(gMesh != nullptr && this->get_item_amount().amount > 0){
    gMesh->Execute();
  }
}

void Uni::UpdateDrill(SIGNATURE_mesh* meshDrill){ // mesh drill is from the container gui fuck
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    SIGNATURE_mesh* mesh = this->get_mesh().first;
    if(mesh != nullptr){
        mesh->get_value().x = xDr + mesh->get_pole().x;
        mesh->get_value().y = yDr + mesh->get_pole().y;
    }
}

void Uni::node_erase_checker(){
    for(uint8_t i = 0;i < this->get_nodes().size();i++){
        if(this->get_nodes()[i] == nullptr){
            this->nodes.erase(this->nodes.begin() + i);
            i--;
        }
    }
}

void Uni::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display(); 
}

