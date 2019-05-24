#ifndef MAP_H
#define MAP_H
//My files
#include "Tile.h"
#include "../Utility/Disk.h"
#include "../Utility/Vec2.h"
// Std libs
#include <vector>
#include <string>
class Map
{
public:
	Map();
	Map(std::string lvlDataPath);
	~Map();

public:
	//Getery
	Tile::Content getContent(size_t x, size_t y);
	Tile::Content getContent(Vec2i pos);
	size_t getWidth();
	size_t getHeight();
	//Settery
private:
	std::vector<Tile> vTiles;
	size_t nWidth;
	size_t nHeight;
};

#endif