#ifndef BASICS_H
#define BASICS_H

#include "../Utility/Vec2.h"

class Coords
{
public:
	Coords(Vec2d& crd) : wPos(crd) {};
	Coords(double x,double y) : wPos(x,y) {};
	~Coords() {};
	Vec2d wPos;
};


class Stats
{
public:
	Stats() :nHealth(0), nMaxHealth(0), nDamage(0), nArmor(0), nSpeed(0) {};
	Stats(double hp, double dmg,double arm, double spd) : nHealth(hp),nMaxHealth(hp), nDamage(dmg), nArmor(arm), nSpeed(spd) {}
	~Stats() {};
	double nHealth;
	double nMaxHealth;
	double nDamage;
	double nArmor;
	double nSpeed;

	Stats& operator +=(const Stats& rhs)
	{
		nHealth += rhs.nHealth;
		nMaxHealth += rhs.nMaxHealth;
		nDamage += rhs.nDamage;
		nArmor += rhs.nArmor;
		nSpeed += rhs.nSpeed;
		return *this;
	}
};

#endif
