#ifndef ITEM_H
#define ITEM_H

//Std libs
#include <fstream>
#include <string>

//Own libs
#include "../Basics/Basics.h"

class Player;

class Item
{
public:
	enum Category
	{
		Undefined = -1,
		Helmet = 0,
		Chestplate = 1,
		Gloves = 2,
		Boots = 3,
		Weapon = 4,
		Useable = 5,
	};
public:
	Item();
	Item(std::string filePath);
	~Item();


public:
	void Use(Player &sp);
public:
	Category getCategory() { return cat; }
	Stats& getStats() { return s; }
	std::string getName() { return sName; }
private:
	Category cat;
	Stats s;
	std::string sName;
};
#endif