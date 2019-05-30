#ifndef GAME_CONSOLE
#define GAME_CONSOLE

#define CONSOLEW 80
#define CONSOLEH 24
//Own files
#include "GameEngine.h"
#include "../ConsoleStuff/GUI.h"

//Standard libs
#include <cmath>
#include <conio.h>



class GameEngineConsole :
	public GameEngine
{
public:
	GameEngineConsole();
	~GameEngineConsole();

public:
	void ComposeFrame() override;
	void ProcessInput() override;

private:
	void drawBorder();
	void goTo(size_t x, size_t y);
	void drawLevel(size_t mx, size_t my, size_t w, size_t h);
private:
	HANDLE hnd;
	COORD c;
	GUI gui;
	bool bMove;
};

#endif