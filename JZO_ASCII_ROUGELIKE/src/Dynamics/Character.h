#pragma once
#include "Dynamic.h"
#include "../Basics/Level.h"
class Character :
	public Dynamic,
	public Level
{
public:
	Character()=delete;
	Character(double x, double y);
	~Character();
public:
	void Move(const Vec2d& move);
public:
	virtual void Update(Dynamic* player = nullptr) 
	{

	}
	virtual void OnInteract(Dynamic* player = nullptr) {}
	virtual void PerformAttack() {};
protected:
	Vec2d wLast;
public:
	Stats s;
};

class Enemy : public Character
{
	Enemy(double x, double y) : Character(x, y) { s.nDamage = 10; };
	void OnInteract(Dynamic* player = nullptr) {};

};

