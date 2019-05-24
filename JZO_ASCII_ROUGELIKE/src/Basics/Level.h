#ifndef LVL_H
#define LVL_H
class Level
{
public:
	Level();
	~Level();

public:
	void addXP(size_t xp);

	//Gettery
public:
	size_t getLvl();
	size_t getcurxp();
	size_t getreqxp();
private:
	size_t CurrentLvl;
	size_t CurrentXP;
	size_t RequiredXP;
};

#endif