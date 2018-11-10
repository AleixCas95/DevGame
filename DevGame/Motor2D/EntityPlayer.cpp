#include "EntityPlayer.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Audio.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "ModuleFadeToBlack.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Render.h"
#include "j1Scene.h"






EntityPlayer::EntityPlayer(int x, int y, ENTITY_TYPE type) : Entity(x, y, type) 
{


	//idle right animation  //DONE

	idle_right.PushBack({ 361,2,29,30 });
	idle_right.PushBack({ 394,2,29,30 });
	idle_right.PushBack({ 427,2,29,30 });
	idle_right.speed = 0.01f;
	idle_right.loop = true;

	//idle left animation //DONE

	idle_left.PushBack({ 690,2,29,30 });
	idle_left.PushBack({ 657,2,29,30 });
	idle_left.PushBack({ 624,2,29,30 });
	idle_left.speed = 0.01f;
	idle_left.loop = true;

	//running right animation DONE

	running_right.PushBack({ 29,53,31,29 });
	running_right.PushBack({ 61,54,32,28 });
	running_right.PushBack({ 103,54,32,38 });
	running_right.PushBack({ 139,53,29,29 });
	running_right.PushBack({ 170,52,31,30 });
	running_right.PushBack({ 205,54,32,28 });
	running_right.PushBack({ 242,55,31,27 });
	running_right.PushBack({ 278,54,28,28 });
	running_right.speed = 0.1f;
	running_right.loop = true;

	//running left animation DONE
	running_left.PushBack({ 1020,53,31,29 });
	running_left.PushBack({ 983,54,32,28 });
	running_left.PushBack({ 945,54,32,28 });
	running_left.PushBack({ 912,53,29,29 });
	running_left.PushBack({ 879,52,31,30 });
	running_left.PushBack({ 843,54,32,28 });
	running_left.PushBack({ 807,55,31,27 });
	running_left.PushBack({ 774,54,28,28 });
	running_left.speed = 0.2f;
	running_left.loop = true;

	//die right animation TO DO

	die_right.PushBack({ 33,334,19,24 });
	die_right.PushBack({ 81,345,19,24 });
	die_right.PushBack({ 132,345,22,24 });
	die_right.PushBack({ 184,345,18,24 });
	die_right.PushBack({ 237,345,15,24 });
	die_right.PushBack({ 284,345,18,24 });
	die_right.speed = 0.1f;
	die_right.loop = false;


	//die left animation TO DO

	die_left.PushBack({ 330,1327,19,24 });
	die_left.PushBack({ 282,1326,19,24 });
	die_left.PushBack({ 249,1327,22,24 });
	die_left.PushBack({ 180,1327,18,24 });
	die_left.PushBack({ 130,1327,15,24 });
	die_left.PushBack({ 80,1327,18,24 });
	die_left.speed = 0.1f;
	die_left.loop = false;


	//slide right animation TO DO

	slide_right.PushBack({ 171,130,34,17 });
	slide_right.PushBack({ 221,130,34,17 });
	slide_right.PushBack({ 271,130,34,17 });
	slide_right.PushBack({ 325,130,30,17 });
	slide_right.speed = 0.01f;
	slide_right.loop = true;

	//slide left animation TO DO

	slide_left.PushBack({ 177,1112,34,17 });
	slide_left.PushBack({ 127,1112,34,17 });
	slide_left.PushBack({ 77,1112,34,17 });
	slide_left.PushBack({ 27,1112,30,17 });
	slide_left.speed = 0.1f;
	slide_left.loop = true;

	//fall right animation done
	fall_right.PushBack({ 475,37,23,42 });
	fall_right.speed = 0.1f;
	fall_right.loop = true;

	//fall left animation done
	fall_left.PushBack({ 582,37,23,42 });
	fall_left.speed = 0.1f;
	fall_left.loop = true;


	//jumping left animation done
	jumping_left.PushBack({ 708,50,23,32 });
	jumping_left.PushBack({ 673,49,30,32 });
	jumping_left.PushBack({ 639,42,29,37 });
	jumping_left.PushBack({ 611,37,23,42 });
	jumping_left.PushBack({ 582,37,23,42 });
	jumping_left.speed = 0.1f;
	jumping_left.loop = false;

	//jumping right animation DONE
	//jumping_right.PushBack({ 314,53,31,29 });
	jumping_right.PushBack({ 349,50,23,32 });
	jumping_right.PushBack({ 377,49,30,32 });
	jumping_right.PushBack({ 412,42,29,37 });
	jumping_right.PushBack({ 446,37,23,42 });
	jumping_right.PushBack({ 475,37,23,42 });
	//jumping_right.PushBack({ 505,54,30,29 });
	jumping_right.speed = 0.1f;
	jumping_right.loop = false;


	//attack right done
	attack_right.PushBack({67,557,40,30});
	attack_right.PushBack({115,558,53,30});
	attack_right.PushBack({177,559,53,29});
	attack_right.PushBack({235,559,45,29});
	attack_right.speed = 0.1f;
	attack_right.loop = false;


	Start();

	/*App->audio->fx.add[1] = App->audio->LoadFx("audio/fx/JumpFx.wav");
	App->audio->fx.add[2] = App->audio->LoadFx("audio/fx/HurtFx.wav");*/
}
EntityPlayer::~EntityPlayer() {

	CleanUp();
}

bool EntityPlayer::Start()
{
	LoadTexture();
	App->audio->LoadFx("audio/fx/JumpFx.wav");
	App->audio->LoadFx("audio/fx/HurtFx.wav");

	FindPlayerSpawn();
	SpawnPLayer();
	is_jumping = false;
	looking_right = true;
	return true;
}

bool EntityPlayer::Update(float dt)
{

	//if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
	//	App->fade->FadeToBlack(App->scene, App->scene, 0.5f);
	//}

	if (looking_right)
		animation = &idle_right;
	else if (looking_left)
		animation = &idle_left;

	float falling_speed = playerData.gravity;
	if (can_jump)
		falling_speed -= 1.5;

	fPoint tempPos = pos;

	// numbers in CheckCollision calls are there to avoid the character from levitating in a border (collision looks cleaner)
	if (god_mode == false)
	{
		tempPos.y += falling_speed;
		if (CheckCollision(GetPlayerTile({ tempPos.x + 5, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::AIR
			&& CheckCollision(GetPlayerTile({ tempPos.x + 10, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::AIR
			&& is_jumping == false)
		{
			can_jump = false;
			is_falling = true;
			pos = tempPos;
			if (looking_left && can_jump == false)
				animation = &fall_left;
			else if (looking_right && can_jump == false)
				animation = &fall_right;
		}
		else
		{
			is_falling = false;
			can_jump = true;
		}

		if (CheckCollision(GetPlayerTile({ tempPos.x + 5, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::DEATH
			&& CheckCollision(GetPlayerTile({ tempPos.x + 10, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::DEATH)
		{
			App->audio->PlayFx(2);
			SpawnPLayer();
		}
		else if (CheckCollision(GetPlayerTile({ tempPos.x + 5, tempPos.y - animation->GetCurrentFrame().h })) == COLLISION_TYPE::DEATH
			&& CheckCollision(GetPlayerTile({ tempPos.x + 10, tempPos.y - animation->GetCurrentFrame().h })) == COLLISION_TYPE::DEATH)
		{
			App->audio->PlayFx(2);
			SpawnPLayer();
		}


		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		{
			tempPos = pos;

			tempPos.x += playerData.speed;

			if (CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y })) == COLLISION_TYPE::AIR
				&& CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::AIR)
			{
				pos.x = tempPos.x;
				if (is_falling == false)
					animation = &running_right;
			}

			else if (CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y })) == COLLISION_TYPE::WIN
				&& CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::WIN)
			{
				App->scene->LoadScene(); //with number 0, LoadScene 
			}

			looking_left = false;
			looking_right = true;
		}

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		{
			tempPos = pos;

			tempPos.x -= playerData.speed;

			if (CheckCollision(GetPlayerTile({ tempPos.x, tempPos.y })) == COLLISION_TYPE::AIR
				&& CheckCollision(GetPlayerTile({ tempPos.x, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::AIR)
			{
				if (tempPos.x >= App->render->camera.x)
					pos.x = tempPos.x;
				if (is_falling == false)
					animation = &running_left;
			}

			looking_left = true;
			looking_right = false;
		}

		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && is_jumping == false && can_jump)
		{
			App->audio->PlayFx(1);
			can_jump = false;
			jumping_left.Reset();
			jumping_right.Reset();
			is_jumping = true;
			cont = 0;
		}

		//attack right

		if ((App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT)) 
		{
				animation = &attack_right;
			
		}

		if (is_jumping)
		{
			tempPos = pos;

			tempPos.y -= playerData.jumpSpeed;
			if (CheckCollision(GetPlayerTile({ tempPos.x + 5, tempPos.y })) == COLLISION_TYPE::AIR
				&& CheckCollision(GetPlayerTile({ tempPos.x + 10, tempPos.y })) == COLLISION_TYPE::AIR)
			{
				if (tempPos.y >= App->render->camera.y)
					pos.y = tempPos.y;
				if (looking_left)
					animation = &jumping_left;
				else if (looking_right)
					animation = &jumping_right;
			}
			if (cont == 35)
			{
				is_jumping = false;
			}
		}

		/*if (App->input->GetKey(SDL_SCANCODE_C) == KEY_REPEAT)
		{
		tempPos = playerData.pos;

		tempPos.x += playerData.speed;

		if (CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y })) == COLLISION_TYPE::AIR
		&& CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::AIR)
		{
		playerData.pos.x = tempPos.x;
		animation = &slide_right;
		}

		looking_left = false;
		looking_right = true;
		}
		*/
	}
	else
	{
		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		{
			tempPos.y -= 4;
			if (tempPos.y >= App->render->camera.y)
				pos.y -= 4;
		}
		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		{
			tempPos.y += 4;
			if (tempPos.y + animation->GetCurrentFrame().h <= App->render->camera.y + App->win->height)
				pos.y += 4;
		}
		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		{
			pos.x += 4;
			animation = &running_right;
			if (CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y })) == COLLISION_TYPE::WIN
				&& CheckCollision(GetPlayerTile({ tempPos.x + animation->GetCurrentFrame().w, tempPos.y + animation->GetCurrentFrame().h })) == COLLISION_TYPE::WIN)
			{
				App->scene->LoadScene(); //with number 3 LoadScene loads the next map
			}
		}
		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		{
			if (tempPos.x >= App->render->camera.x)
				pos.x -= 4;
			animation = &running_left;
		}
	}
	
	cont++;
	return true;
}

bool EntityPlayer::CleanUp()
{
	App->tex->UnLoad(texture);
	return true;
}

bool EntityPlayer::Load(pugi::xml_node& data)
{
	pos.x = data.child("position").attribute("x").as_float();
	pos.y = data.child("position").attribute("y").as_float();

	return true;
}

bool EntityPlayer::Save(pugi::xml_node& data) const
{
	pugi::xml_node position = data.append_child("position");

	position.append_attribute("x") = (float)pos.x;
	position.append_attribute("y") = (float)pos.y;

	return true;
}

void EntityPlayer::LoadTexture()
{
	texture = App->tex->Load("textures/Player/spritesheetsmain.png");
}

int EntityPlayer::GetPlayerTile(fPoint pos) const
{
	iPoint position = App->map->WorldToMap(pos.x, pos.y);

	int tile_number = position.y * App->map->data.width + position.x;

	return tile_number;
}



void EntityPlayer::FindPlayerSpawn()
{
	p2List_item<MapLayer*>* layer = App->map->data.layers.end;
	for (int i = 0; i < (layer->data->width * layer->data->height); i++)
	{
		if (layer->data->data[i] == 82)
		{
			spawn = App->map->TileToWorld(i);
		}
	}
}

void EntityPlayer::SpawnPLayer()
{
	pos.x = spawn.x;
	pos.y = spawn.y;
	App->render->camera.x = 0;
}