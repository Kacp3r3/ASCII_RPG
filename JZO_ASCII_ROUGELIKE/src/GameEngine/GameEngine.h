#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "../Map/Map.h"
#include "../Camera/Camera.h"
#include "../Dynamics/Player.h"

#include <Windows.h>
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void Start();
protected:
	virtual void ComposeFrame() = 0;
	virtual void ProcessInput() = 0;
	void UpdateModels();

protected:
	void ProcessPlayerMove(Vec2d move);
	Tile::Content CheckColission(Vec2d move);
protected:
	Map _map;
	Camera cam;
	Player p;
};
#endif
