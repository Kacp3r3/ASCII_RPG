#include "Player.h"


Player::Player(double x, double y)
	:
	 Character(x,y)
	,items(5,Item())
{
}


Player::~Player()
{
}

bool Player::hasItem(Item::Category cat)
{
	if (cat != Item::Undefined)
	{
		return items[int(cat)].getCategory() != Item::Undefined;
	}
	return false;
}

void Player::unEquip(Item::Category cat)
{
	if (cat != Item::Undefined)
	{
		s -= items[(int)cat].getStats();
	}
}

void Player::Equip(Item & item)
{
	if (item.getCategory() != Item::Undefined)
	{
		items[(int)item.getCategory()] = item;
		s += item.getStats();
	}
}
