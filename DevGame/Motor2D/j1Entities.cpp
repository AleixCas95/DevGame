#include "j1Entities.h"
#include "Entity.h"
#include "j1Textures.h"
#include "j1Map.h"
#include "j1Render.h"
#include "p2Log.h"
#include "j1Window.h"
#include "j1Audio.h"
#include "EntityPlayer.h"


j1Entities::j1Entities(){

	name.create("entities");

}


j1Entities::~j1Entities(){}

bool j1Entities::Awake(pugi::xml_node& config){

	bool ret = true;
	return ret;
}

bool j1Entities::Start(){

	return true;
}

bool j1Entities::PreUpdate() {

	for (p2List_item<Entity*>* item = entities.start; item != nullptr; item = item->next) {

		if (item->data->destroy_entity==true) {

			
			delete(item);
			entities.del(item);
		}
	}

	
	return true;
}

bool j1Entities::Update(float dt) {

	for (int i = 0; i < entities.count(); ++i) {

		if (entities[i] != nullptr) {

			entities[i]->Update(dt);
		}
	}
	for (int i = 0; i < entities.count(); ++i) {

		if (entities[i] != nullptr) {

			entities[i]->Draw();
		}	
	}
	return true;
}

bool j1Entities::CleanUp() {
	
	for (p2List_item<Entity*>* item = entities.start; item != nullptr; item = item->next) {

			delete(item);
			entities.del(item);
		}
	return true;
}

bool j1Entities::SpawnEntity(int x, int y,ENTITY_TYPE type) {

	bool ret = false;

	/*switch (type) {

	case ENTITY_TYPE::PLAYER: {

		EntityPlayer* entityPlayer = new EntityPlayer(x, y, PLAYER);
		entities.add(entityPlayer);

		break; }

	default: 

		break; 
	}*/

	return ret;

}

EntityPlayer* j1Entities::GetPlayer()const{

	for (uint i = 0; i < entities.count(); ++i) {

		if (entities[i] != nullptr) {

			if (entities[i]->type == PLAYER) {

				return(EntityPlayer*)entities[i];
			}
		}
	}
	return nullptr;

}