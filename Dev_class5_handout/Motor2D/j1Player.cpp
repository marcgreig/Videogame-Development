#include "p2Log.h"
#include "j1Player.h"
#include "SDL/include/SDL.h"
j1Player::j1Player() : j1Module() {}

j1Player::~j1Player() {}

bool j1Player::Awake(pugi::xml_node& config) 
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Player::Create() {
	int SDL_RenderDrawRect(SDL_Renderer* renderer, const SDL_Rect* rect);
}

void j1Player::Move() {}

bool j1Player::CleanUp() 
{
	LOG("Unloading player");
	player_file.reset();
	return true;

}

//Load player
bool j1Player::Load(const char* file_name) 
{
	return false;
}

bool j1Player::Save(pugi::xml_node &) const
{
	return false;
}

