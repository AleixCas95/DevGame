#include "Entity.h"
#include "j1Input.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Map.h"
#include "j1App.h"
#include "Animation.h"
#include "p2List.h"




Entity::Entity(int x, int y, ENTITY_TYPE type): pos(x,y),type(type){}

Entity::~Entity(){

	App->tex->UnLoad(texture);

	
}

COLLISION_TYPE Entity::CheckCollision(int x)const{

	p2List_item<MapLayer*>* layer_colliders = App->map->data.layers.end;

	switch (layer_colliders->data->data[x])
	{
	default:
		break;

	case 57:
		return COLLISION_TYPE::GROUND;
		break;

	case 59:
		return COLLISION_TYPE::DEATH;
		break;

	case 81:
		return COLLISION_TYPE::WIN;
		break;
	}

	return COLLISION_TYPE::AIR;


}

void Entity::Draw(){

	

	if (animation != nullptr) {

		SDL_Rect rect_animation = animation->GetCurrentFrame();

		if (fliptexture == true) {

			App->render->Blit(texture, pos.x, pos.y, &rect_animation, 1, SDL_FLIP_HORIZONTAL);
	
		}
		else {

			App->render->Blit(texture, pos.x, pos.y, &rect_animation, 1);

		}

	}

}




