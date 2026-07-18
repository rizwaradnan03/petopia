#include <nodes/2d/uni/uni_item.h>

UNI_item::UNI_item(std::pair<DtoRawMesh*, DtoRawMesh*> rawMesh, DtoPoleset* poleSet, DtoItemAmount itemAmountDto): Uni(rawMesh, poleSet, itemAmountDto){ // uni akan di run oleh 2 yaitu player & render type -> as player hanya akan me running core + display gui AND as render type akan run sebagai action
    this->set_id(identifier::generate_id("uni_item"));
    
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

UNI_item::~UNI_item(){
    delete this->get_gui_mesh();
    delete this->get_object_mesh();

    delete this->get_poleset();
}

std::string& UNI_item::get_id(){
    return this->id;
}

void UNI_item::set_id(std::string value){
    this->id = value;
}

std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> UNI_item::get_mesh(){
    return this->mesh;
}

void UNI_item::set_mesh(std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> value){
    this->mesh = value;
}

SIGNATURE_mesh* UNI_item::get_gui_mesh(){
    return this->get_mesh().first;
}

SIGNATURE_mesh* UNI_item::get_object_mesh(){
    return this->get_mesh().second;
}

std::vector<SIGNATURE_mesh*> UNI_item::get_nodes(){
    return this->nodes;
}

void UNI_item::set_nodes(std::vector<SIGNATURE_mesh*> value){
    this->nodes = value;
}

void UNI_item::set_push_nodes(SIGNATURE_mesh* value){
    this->nodes.push_back(value);
}

void UNI_item::register_nodes(){ // get the mouse and make own object
    std::pair<float, float> mPos = input::mouse_position_player_as_pole();

    SIGNATURE_mesh* ownObject = new SIGNATURE_mesh(*this->get_object_mesh()); // copy of it
    ownObject->get_value().x = mPos.first;
    ownObject->get_value().y = mPos.second;

    this->set_push_nodes(ownObject);
    G_render->get_select()->set_push_object(std::make_pair(this, ownObject));
}

DtoPoleset* UNI_item::get_poleset(){
    return this->poleset;
}

void UNI_item::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

DtoItemAmount& UNI_item::get_item_amount(){
    return this->item_amount;
}

void UNI_item::set_item_amount(DtoItemAmount value){
    this->item_amount = value;
}

void UNI_item::usage_action(SIGNATURE_mesh *childAddr){

}

void UNI_item::action(SIGNATURE_mesh *childAddr){
    childAddr->Execute();
    this->usage_action(childAddr);
}

void UNI_item::Display(){ // SECOND MESH IS OBJECT WHICH WE WILL PUSH INTO THE RENDER SYSTEM TO EXECUTE
  SIGNATURE_mesh* mesh = this->get_mesh().first;
  if(mesh != nullptr){
    mesh->Execute();
  }
}

void UNI_item::UpdateDrill(SIGNATURE_mesh* meshDrill){ // mesh drill is from the container gui
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    SIGNATURE_mesh* mesh = this->get_mesh().first;
    if(mesh != nullptr){
        mesh->get_value().x = xDr + mesh->get_pole().x;
        mesh->get_value().y = yDr + mesh->get_pole().y;
    }
}

void UNI_item::node_erase_checker(){
    for(uint8_t i = 0;i < this->get_nodes().size();i++){
        if(this->get_nodes()[i] == nullptr){
            this->nodes.erase(this->nodes.begin() + i);
            i--;
        }
    }
}

void UNI_item::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display(); 
}

