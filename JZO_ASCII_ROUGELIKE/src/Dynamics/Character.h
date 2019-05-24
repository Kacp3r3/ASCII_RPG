#pragma once
#include "Dynamic.h"
#include "../Basics/Level.h"
class Character :
	public Dynamic,
	public Stats,
	public Level
{
public:
	Character()=delete;
	Character(double x, double y);
	~Character();
public:
	void Move(const Vec2d& move);
public:
	virtual void Update(float fElapsedTime, Dynamic* player = nullptr) {}
	virtual void OnInteract(Dynamic* player = nullptr) {}
	virtual void PerformAttack() {};
protected:
	Vec2d wLast;
};

