#ifndef __J1PLAYER_H__
#define __J1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"


struct SDL_Texture;
struct ObjectsData;


class j1Player : public j1Module
{
	//-------------Functions-----------------
public:

	j1Player();

	// Destructor
	~j1Player();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	//Called before the first frame
	bool Start();

	bool Update(float dt);
	bool PostUpdate();

	// Called each loop iteration

	bool Load(pugi::xml_node& file);
	bool Save(pugi::xml_node& file) const;

	// Called before quitting
	bool CleanUp();


	//Positions the player in the start of the current level
	void Restart();

	//Centers the camera on the player
	bool CameraOnPlayer();

private:

public:


private:

	// Player rectangle
	// SDL_Rect playerRect;

	// Player graphs
	SDL_Texture* graph = nullptr;

	// Player position and scale;
	iPoint playerPos;
	uint playerWidth;
	uint playerHeight;


	p2SString folder;
};

#endif // !__J1PLAYER_H__