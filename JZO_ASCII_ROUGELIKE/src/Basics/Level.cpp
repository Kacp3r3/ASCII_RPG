#include "Level.h"



Level::Level()
	:
	 CurrentLvl(1)
	,CurrentXP(0)
	,RequiredXP(100)
{
}


Level::~Level()
{
}

void Level::addXP(size_t xp)
{
	CurrentXP += xp;
	if (RequiredXP < CurrentXP)
	{
		CurrentLvl++;
		CurrentXP -= RequiredXP;

		//Turbo skomplikowany przelicznik
		RequiredXP = size_t(CurrentLvl * 1.618);
	}
}

size_t Level::getLvl()
{
	return CurrentLvl;
}

size_t Level::getcurxp()
{
	return CurrentXP;
}

size_t Level::getreqxp()
{
	return RequiredXP;
}
