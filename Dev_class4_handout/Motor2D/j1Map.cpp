#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		pugi::xml_node map_node;
		map_node = map_file.child(file_name).child("map");
		map_info.version= map_file.child("version").attribute("value").as_float();
		map_info.orientation = map_file.child("orientation").attribute("value").as_int();
		map_info.renderer = map_file.child("renderorder").attribute("value").as_string();
		map_info.height = map_file.child("height").attribute("value").as_uint();
		map_info.width = map_file.child("width").attribute("value").as_uint();
		map_info.tileheight = map_file.child("tileheight").attribute("value").as_uint();
		map_info.tilewidth = map_file.child("tilewidth").attribute("value").as_uint();
		map_info.nextobjectid = map_file.child("nextobjectid").attribute("value").as_uint();

	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	for (pugi::xml_node tileset = map_file.child("map").child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) {

		tileset_info.firstgid = map_file.child("firstgid").attribute("value").as_uint();
		tileset_info.name = map_file.child("name").attribute("value").as_string();
		tileset_info.tileheight = map_file.child("tileheight").attribute("value").as_uint();
		tileset_info.tilewidth = map_file.child("tilewidth").attribute("value").as_uint();
		tileset_info.spacing = map_file.child("spacing").attribute("value").as_uint();
		tileset_info.margin = map_file.child("margin").attribute("value").as_uint();
		tileset_info.image_source = map_file.child("image").attribute("source").as_string();
		tileset_info.image_height = map_file.child("image").attribute("height").as_uint();
		tileset_info.image_width = map_file.child("image").attribute("width").as_uint();

	}


	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

