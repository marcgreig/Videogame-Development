/*#include "j1App.h"
#include "j1Player.h"
#include "j1Render.h"
#include "j1Map.h"
#include "j1Window.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "p2Log.h"


j1Player::j1Player() : j1Module()
{

}


j1Player::~j1Player()
{
}

bool j1Player::Awake(pugi::xml_node & config)
{
	bool ret = true;
	config = config.child("player");

	return ret;
}

bool j1Player::Start()
{
	
	//Sets the player in the start position
	playerPos.x = 0;
	playerPos.y = 0;

	return true;
}

bool j1Player::Update(float dt)
{
	return true;
}


bool j1Player::PostUpdate()
{
	
	PositionCameraOnPlayer();

	return true;
}



bool j1Player::Load(pugi::xml_node& data)
{
	return false;
}

// Save Game State
bool j1Player::Save(pugi::xml_node& data) const
{
	data.append_child("player");

	data.child("player").append_child("position").append_attribute("x") = playerPos.x;
	data.child("player").child("position").append_attribute("y") = playerPos.y;
	
	return true;
}






bool j1Player::PositionCameraOnPlayer()
{
	uint winWidth, winHeight;
	winWidth = 0;
	winHeight = 0;
	App->win->GetWindowSize(winWidth, winHeight);
	
	App->render->camera.x = playerPos.x - App->render->camera.w / 3;
	if (App->render->camera.x < 0)App->render->camera.x = 0;
	App->render->camera.y = playerPos.y - App->render->camera.h / 2;
	if (App->render->camera.y + winHeight > App->map->data.height*App->map->data.tile_height)App->render->camera.y = App->map->data.height*App->map->data.tile_height - winWidth;
	return true;
}



bool j1Player::CleanUp()
{
	LOG("Deleting player");

	return true;

}


*/