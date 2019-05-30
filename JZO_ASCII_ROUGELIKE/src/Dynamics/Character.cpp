#include "Character.h"


Character::Character(double x, double y)
	:
	 Dynamic(x,y)
	,s(100,10,5,1)
{
}


Character::~Character()
{
}

void Character::Move(const Vec2d & move)
{
	cPos.wPos += move;
}
