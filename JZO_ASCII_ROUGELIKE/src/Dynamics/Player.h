#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player()=delete;
	Player(double x, double y);
	~Player();
public:
	virtual void OnInteract(Dynamic* player = nullptr) override {}
};

