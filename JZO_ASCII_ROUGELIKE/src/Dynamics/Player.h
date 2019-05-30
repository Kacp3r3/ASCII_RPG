#ifndef PLAYER_H
#define PLAYER_H

//Own libs
#include "Character.h"
#include "../Item/Item.h"

//std libs
#include <vector>
class Player :
	public Character
{
public:
	Player()=delete;
	Player(double x, double y);
	~Player();
public:
	virtual void OnInteract(Dynamic* player = nullptr) override {}


public:
	std::vector<Item>& getItems() { return items; };
	bool hasItem(Item::Category cat);
	void unEquip(Item::Category cat);
	void Equip(Item& item);
private:
	std::vector<Item> items;
};

#endif