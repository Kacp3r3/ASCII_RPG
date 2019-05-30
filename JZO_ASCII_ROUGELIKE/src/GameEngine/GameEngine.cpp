#include "GameEngine.h"

GameEngine::GameEngine() 
	: 
	 _map("res/lvl.data")
	,cam(_map.getWidth()/2
	,_map.getHeight()/2)
	,p(_map.getWidth() / 2
	,_map.getHeight() / 2)
	,hasmoved(false)
{
}


GameEngine::~GameEngine()
{
}

void GameEngine::Start()
{
	//drawGUI();
	while (true)
	{
		ProcessInput();
		if (hasmoved == true)
		{
			UpdateModels();
			ComposeFrame();
		}
	}
}

void GameEngine::ComposeFrame()
{
}

void GameEngine::UpdateModels()
{
}

void GameEngine::ProcessPlayerMove(Vec2d move)
{
	Vec2d tmp = p.getPos() + move;
	if (tmp._x > -1 && tmp._x < _map.getWidth())
	{
		if (tmp._y > -1 && tmp._y < _map.getHeight())
		{
			switch (CheckColission(tmp))
			{
			case Tile::Content::WALL:
				hasmoved = false;
				break;
			default:
				hasmoved = true;
				p.Move(move);
			}
		}
	}
}

Tile::Content GameEngine::CheckColission(Vec2d move)
{
	return _map.getContent({ (int)move._x,(int)move._y });
}
