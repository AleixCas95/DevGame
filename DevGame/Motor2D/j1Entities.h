#ifndef _J1ENTITIES_H_
#define _J1ENTITIES_H_


#include "j1Module.h"
#include "p2List.h"

class Entity;

enum ENTITY_TYPE
{
	NO_ENTITY,
	PLAYER



};

class EntityPlayer;

class j1Entities : public j1Module {

public:

	j1Entities();
	~j1Entities();

	bool Awake(pugi::xml_node& conf);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();
	bool SpawnEntity(int x, int y,ENTITY_TYPE type);

	EntityPlayer* GetPlayer()const;

public:
	p2List<Entity*> entities;


};


#endif // !_J1ENTITIES_H_

