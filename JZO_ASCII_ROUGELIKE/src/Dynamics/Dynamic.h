#ifndef DYN_H
#define DYN_H

#include <string>
#include "../Utility/Vec2.h"
#include "../Basics/Basics.h"
class Dynamic
{
public:
	Dynamic()=delete;
	Dynamic(double x, double y);
	~Dynamic();

public:
	Vec2d getPos();

public:
	virtual void Update(float fElapsedTime, Dynamic* player = nullptr) {}
	virtual void OnInteract(Dynamic* player = nullptr) {}
protected:
	Coords cPos;
	bool bSolidVsMap;
	bool bSolidVsDyn;
	bool bFriendly;
	bool bIsAttackable;

	std::string sName;
};

#endif