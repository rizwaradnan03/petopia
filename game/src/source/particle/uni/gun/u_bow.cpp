#include <source/particle/uni/gun/u_bow.h>

UNI_GUN_BOW::UNI_GUN_BOW(DtoTextureType variant, DtoPoleset* poleSet, DtoItemAmount itemAmountDto): UNI_gun({}, poleSet, itemAmountDto){ // uni akan di run oleh 2 yaitu player & render type -> as player hanya akan me running core + display gui AND as render type akan run sebagai action
    this->set_id(identifier::generate_id("uni_gun_bow"));
    
    DtoRawMesh gRM;
    gRM.cartesian.w = 30;
    gRM.cartesian.h = 30; 
    gRM.cartesian.x = 0;
    gRM.cartesian.y = 0;
    gRM.rawTextures = {
        std::make_pair("default", "GUN_BOW")
    };

    SIGNATURE_mesh* gMesh = new SIGNATURE_mesh(gRM);
    SIGNATURE_mesh* oMesh = new SIGNATURE_mesh(*gMesh);

    this->set_mesh(std::make_pair(gMesh, oMesh));
    this->set_poleset(poleSet);
    this->set_item_amount(itemAmountDto);
}

UNI_GUN_BOW::~UNI_GUN_BOW(){
    delete this->get_gui_mesh();
    delete this->get_object_mesh();

    delete this->get_poleset();
}

std::string& UNI_GUN_BOW::get_id(){
    return this->id;
}

void UNI_GUN_BOW::set_id(std::string value){
    this->id = value;
}

std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> UNI_GUN_BOW::get_mesh(){
    return this->mesh;
}

void UNI_GUN_BOW::set_mesh(std::pair<SIGNATURE_mesh*, SIGNATURE_mesh*> value){
    this->mesh = value;
}

SIGNATURE_mesh* UNI_GUN_BOW::get_gui_mesh(){
    return this->get_mesh().first;
}

SIGNATURE_mesh* UNI_GUN_BOW::get_object_mesh(){
    return this->get_mesh().second;
}

std::vector<SIGNATURE_mesh*> UNI_GUN_BOW::get_nodes(){
    return this->nodes;
}

void UNI_GUN_BOW::set_nodes(std::vector<SIGNATURE_mesh*> value){
    this->nodes = value;
}

void UNI_GUN_BOW::set_push_nodes(SIGNATURE_mesh* value){
    this->nodes.push_back(value);
}

void UNI_GUN_BOW::register_nodes(){ // get the mouse and make own object
    std::pair<float, float> mPos = input::mouse_position_player_as_pole();

    SIGNATURE_mesh* ownObject = new SIGNATURE_mesh(*this->get_object_mesh()); // copy of it
    ownObject->get_value().x = mPos.first;
    ownObject->get_value().y = mPos.second;

    this->set_push_nodes(ownObject);
    G_render->get_select()->set_push_object(std::make_pair(this, ownObject));
}

DtoPoleset* UNI_GUN_BOW::get_poleset(){
    return this->poleset;
}

void UNI_GUN_BOW::set_poleset(DtoPoleset* value){
    this->poleset = value;
}

DtoItemAmount& UNI_GUN_BOW::get_item_amount(){
    return this->item_amount;
}

void UNI_GUN_BOW::set_item_amount(DtoItemAmount value){
    this->item_amount = value;
}

void UNI_GUN_BOW::node_action(SIGNATURE_mesh *childAddr){

}

void UNI_GUN_BOW::node_render(SIGNATURE_mesh *childAddr){
    this->node_action(childAddr);
    childAddr->Execute();
}

void UNI_GUN_BOW::action(){ // JADI YANG AKAN DI RENDER PADA TANGAN ITEM PADA PLAYER ADALAH OBJECT ()
    // TODO: force the position stick into the player
    this->render_object(); // render object as holded item

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        std::pair<float, float> mPos = input::mouse_position_player_as_pole();
        float mem[] = {mPos.first, mPos.second};
    
        uint8_t lw = 0;
        if(mPos.second < mPos.first){
            lw = 1;
        }
    
        float calc[] = {mem[0] / mem[lw], mem[1] / mem[lw]}; // TODO: BUT WE DONT EVEN KNOW WHAT KIND OF PROJECTILE DO WE NEED TO USE
    } 
}

void UNI_GUN_BOW::Display(){
  SIGNATURE_mesh* gMesh = this->get_gui_mesh();
  if(gMesh != nullptr && this->get_item_amount().amount > 0){
    this->render_gui();
  }
}

void UNI_GUN_BOW::UpdateDrill(SIGNATURE_mesh* meshDrill){
    float xDr = meshDrill->get_value().x;
    float yDr = meshDrill->get_value().y;

    SIGNATURE_mesh* mesh = this->get_mesh().first;
    if(mesh != nullptr){
        mesh->get_value().x = xDr + mesh->get_pole().x;
        mesh->get_value().y = yDr + mesh->get_pole().y;
    }
}

void UNI_GUN_BOW::node_erase_checker(){
    for(uint8_t i = 0;i < this->get_nodes().size();i++){
        if(this->get_nodes()[i] == nullptr){
            this->nodes.erase(this->nodes.begin() + i);
            i--;
        }
    }
}

void UNI_GUN_BOW::render_gui(){
    this->get_gui_mesh()->Execute();
}

void UNI_GUN_BOW::render_object(){
    this->get_object_mesh()->Execute();
}

void UNI_GUN_BOW::Execute(SIGNATURE_mesh* meshDrill){
    this->UpdateDrill(meshDrill);
    this->Display(); 
}

