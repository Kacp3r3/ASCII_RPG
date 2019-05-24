#include "Dynamic.h"

Dynamic::Dynamic(double x, double y)
	:
	cPos(x,y)
{
}


Dynamic::~Dynamic()
{
}

Vec2d Dynamic::getPos()
{
	return cPos.wPos;
}
