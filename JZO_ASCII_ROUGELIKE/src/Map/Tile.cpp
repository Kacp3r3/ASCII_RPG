#include "Tile.h"



Tile::Tile()
	: 
	 bSolid(false)
	,eContent(NOTHING)
{
}

Tile::Tile(Content c, bool solid)
	:
	 eContent(c)
	,bSolid(solid)
{
}


Tile::~Tile()
{
}

bool Tile::isSolid() const
{
	return bSolid;
}

Tile::Content Tile::GetContent() const
{
	return eContent;
}

void Tile::makeSolid(bool x)
{
	bSolid = x;
}

void Tile::setContent(Content x)
{
	eContent = x;
}
