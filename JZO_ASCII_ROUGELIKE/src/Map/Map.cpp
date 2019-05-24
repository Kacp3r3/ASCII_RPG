#include "Map.h"



Map::Map()
	:
	 nWidth(0)
	,nHeight(0)
	,vTiles()
{
}

Map::Map(std::string lvlDataPath)
{
	Disk d;
	d.open(lvlDataPath, Disk::READ);
	size_t tmp;
	d.readOneNumber(tmp);
	nWidth = tmp;
	d.readOneNumber(tmp);
	nHeight = tmp;
	size_t rozmiar = nWidth * nHeight;
	vTiles.reserve(rozmiar);
	char ctmp;
	for (size_t i = 0; i < rozmiar; ++i)
	{
		d.readOneChar(ctmp);
		vTiles.emplace_back(ctmp == '0' ? Tile::Content::NOTHING : Tile::Content::WALL, ctmp == '0' ? false : true);
	}
}


Map::~Map()
{
}

Tile::Content Map::getContent(size_t x, size_t y)
{
	return vTiles[y*nWidth + x].GetContent();
}

Tile::Content Map::getContent(Vec2i pos)
{
	return vTiles[pos._y*nWidth+pos._x].GetContent();
}

size_t Map::getWidth()
{
	return nWidth;
}

size_t Map::getHeight()
{
	return nHeight;
}
