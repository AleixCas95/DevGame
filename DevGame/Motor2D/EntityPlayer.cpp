#include "EntityPlayer.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Audio.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "ModuleFadeToBlack.h"
#include "j1Window.h"


EntityPlayer::EntityPlayer(int x, int y, ENTITY_TYPE type) : Entity(x, y, type) {}

