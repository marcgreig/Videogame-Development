#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2Point.h"
#include "j1Module.h"

class j1Player : public j1Module
{
public:

	j1Player();

	// Destructor
	virtual ~j1Player();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	void Create();

	// Called each loop iteration
	void Move();

	// Called before quitting
	bool CleanUp();

	bool Load(const char* path);
	bool Save(pugi::xml_node&) const;

private:

	bool LoadMap();

public:

	iPoint pos(int x, int y) {}

private:

	pugi::xml_document	player_file;
	p2SString			folder;

};

#endif __j1PLAYER_H__
