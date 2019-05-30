#include "Item.h"
#include "../Dynamics/Player.h"


Item::Item()
	:
	 s()
	,cat(Undefined)
	,sName("None")
{
}


Item::Item(std::string filePath)
{
	std::fstream file;
	file.open(filePath, std::ios::in);
	if (!file.good()) throw std::runtime_error("Can't open the file " + filePath + " \n");
	
	//Wczytywanie danych o przedmiocie z pliku
	file >> sName;

	int catindex;
	file >> catindex;
	cat = (Category)catindex;

	file >> s.nHealth;

	file >> s.nMaxHealth;

	file >> s.nDamage;

	file >> s.nArmor;

	file >> s.nSpeed;
}

Item::~Item()
{
}

void Item::Use(Player & ch)
{
	switch (cat)
	{
		case Useable:
		{
			ch.s += s;
			break;
		}
		case Helmet:
		case Chestplate:
		case Boots:
		case Gloves:
		case Weapon:
		{
			if (ch.hasItem(cat))
			{
				ch.unEquip(cat);
				ch.Equip(*this);
			}
			else
				ch.Equip(*this);
			break;
		}
		case Undefined:
		default:
		{
			break;
		}
	}
}
