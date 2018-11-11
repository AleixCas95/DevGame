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

			
		/*	item->data->~Entity();*/
			entities.del(item);
		}
	}

	
	return true;
}

bool j1Entities::Update(float dt) {

	for (int i = 0; i < entities.count(); ++i) {

		if (entities.At(i) != nullptr) {

			entities.At(i)->data->Update(dt); 
		}
	}
	for (int i = 0; i < entities.count(); ++i) {

		if (entities.At(i) != nullptr) {

			entities.At(i)->data->Draw();  
		}	
	}
	return true;
}

bool j1Entities::CleanUp() {
	
	for (p2List_item<Entity*>* item = entities.start; item != nullptr; item = item->next) {

	
		/*item->data->~Entity();*/
			entities.del(item);
		}
	return true;
}

bool j1Entities::SpawnEntity(int x, int y,ENTITY_TYPE type) {

	bool ret = false;

	switch (type) {

	case ENTITY_TYPE::PLAYER: {

		player = new EntityPlayer(x, y, PLAYER);
		entities.add(player);

		break; }

	default: 

		break; 
	}

	return ret;

}

EntityPlayer * j1Entities::SpawnPlayer(int x, int y)
{
	EntityPlayer* entityPlayer = new EntityPlayer(x, y, PLAYER);
	entities.add(entityPlayer);

	return entityPlayer;
}

EntityPlayer* j1Entities::GetPlayer()const{

	for (uint i = 0; i < entities.count(); ++i) {

		if (entities.At(i) != nullptr) {

			if (entities.At(i)->data->type == PLAYER) {

				return(EntityPlayer*)entities.At(i);
			}
		}
	}
	return nullptr;

}