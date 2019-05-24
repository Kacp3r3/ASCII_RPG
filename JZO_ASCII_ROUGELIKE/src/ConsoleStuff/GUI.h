#ifndef GUI_H
#define GUI_H

//Std libs
#include <Windows.h>
#include <cstdio>
#include "../Dynamics/Player.h"

//MyLibs
#include "../Camera/Camera.h"
class GUI
{
public:
	GUI(short startx, short starty, short endx, short endy, Player& p);
	~GUI();

public:
	void drawClear();

	//Poruszanie sie po Konsoli
private:
	void DrawBorder();
	void goTo(size_t x, size_t y);
	void ClearRectangle(COORD start, COORD end);
	void ClearRectangle(Vec2t start, Vec2t end);
	void DrawLine(size_t startx);

	//Odpowiednie sekcje
private:
	void Stats(size_t starty);
	void Equipement(size_t starty);
	void DialogueBox(size_t starty);
	void FightInfo(size_t starty);
private:
	HANDLE h;
	COORD Start;
	COORD End;
	Player& player;
};



#endif