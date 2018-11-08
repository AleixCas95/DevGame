#ifndef _ENTITYPLAYER_H_
#define _ENTITYPLAYER_H_


#include "Entity.h"
#include "j1Entities.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Audio.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "ModuleFadeToBlack.h"
#include "j1Window.h"
#include "j1Entities.h"

class EntityPlayer:public Entity {

public:

	EntityPlayer(int x,int y, ENTITY_TYPE type);
	~EntityPlayer() ;

};



#endif // _ENTITYPLAYER_H_
