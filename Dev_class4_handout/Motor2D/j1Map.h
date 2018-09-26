#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

typedef unsigned int uint;

enum orientation { error, orthogonal, isometric };
enum renderorder { _error, right_down, right_up, left_down, left_up };

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!

struct tileset {
	
	int firstgid = 0;
	p2SString name = nullptr;
	uint tilewidth = 0, 
		tileheight = 0,
		spacing = 0,
		margin = 0;
	p2SString image_source = nullptr;
	uint image_width = 0,
		image_height = 0;
};

// ----------------------------------------------------


// TODO 1: Create a struct needed to hold the information to Map node

struct map {
	float version = 1.0;
	enum orientation orientation = orthogonal;
	enum renderorder renderer = right_down;
	uint width = 0,
		height = 0,
		tilewidth = 0,
		tileheight = 0,
		nextobjectid = 0;
};


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:


public:

	// TODO 1: Add your struct for map info as public for now

	map	map_info;
	tileset tileset_info;
private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__