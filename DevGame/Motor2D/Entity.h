#ifndef _ENTITY_H_
#define _ENTITY_H_



#include "SDL/include/SDL.h"
#include "p2Point.h"
#include "j1Entities.h"

enum COLLISION_TYPE
{
	GROUND,
	AIR,
	DEATH,
	WIN
};



struct EntityData
{



	float speed = 2.0f;
	float jumpSpeed = 3.0f;
	float gravity = 2.8f;


};


class Animation;

class Entity {
public:
	Entity(int x, int y, ENTITY_TYPE type);

	virtual ~Entity();

	virtual bool Update(float dt) { return true; };

	virtual int GetEntityTile(fPoint pos) const { return 0; };

	virtual COLLISION_TYPE CheckCollision(int x) const;

	virtual bool Load(pugi::xml_node& data) { return true; };

	virtual bool Save(pugi::xml_node& data) const { return true; };

	virtual void LoadTexture() {};

	virtual void FindEntitySpawn() {};

	virtual void Draw();

	

public:

	Animation * animation = nullptr;

	ENTITY_TYPE type = ENTITY_TYPE::NO_ENTITY;

	SDL_Texture* texture = nullptr;

	bool fliptexture = false;

	fPoint pos = { 0.0f,0.0f};

	bool destroy_entity = false;
};



#endif // !_ENTITY_H_

