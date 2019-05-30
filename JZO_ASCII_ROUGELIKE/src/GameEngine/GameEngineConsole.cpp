#include "GameEngineConsole.h"

GameEngineConsole::GameEngineConsole()
	:
	hnd(GetStdHandle(STD_OUTPUT_HANDLE))
	, c()
	, bMove(false)
	, gui(CONSOLEW / 2, 0, CONSOLEW, CONSOLEH, p)
{
	cam.adjustFov((CONSOLEW/2)-2, CONSOLEH-2);
	drawBorder();
	gui.drawClear();
	SetConsoleTitle("Kacper Sawicki ASCII RPG");
}

GameEngineConsole::~GameEngineConsole()
{
}

void GameEngineConsole::ComposeFrame()
{
	
	if (bMove)
	{
		//calculate variables
		size_t h = (size_t)cam.getFov()._y;
		size_t w = (size_t)cam.getFov()._x;

		//Draw level
		drawLevel(_map.getWidth(), _map.getHeight(), w, h);
	}
	goTo(0, 0);
	
}

void GameEngineConsole::ProcessInput()
{
	bMove = false;
	char move='\0';
	if (_kbhit())
	{
		move = _getch();
		bMove = true;
	}

	switch (move)
	{
		case 'w':
		case 'W':
		{
			ProcessPlayerMove(Vec2d(0.0, -1.0));
			break;
		}
		case 's':
		case 'S':
		{
			ProcessPlayerMove(Vec2d(0.0, 1.0));
			break;
		}
		case 'a':
		case 'A':
		{
			ProcessPlayerMove(Vec2d(-1.0, 0.0));
			break;
		}
		case 'd':
		case 'D':
		{
			ProcessPlayerMove(Vec2d(1.0, 0.0));
			break;
		}
		case 27:
			exit(0);
		case '\0':
		default:
			break;
	}
}

void GameEngineConsole::drawBorder()
{
	for (size_t i = 0, e = (size_t)cam.getFov()._y + 2; i < e; ++i)
	{
		if (i == 0 || i == e-1)
		{
			goTo(0,i);
				for (size_t j = 0, e2 = (size_t)cam.getFov()._x+2; j < e2; ++j)
					printf("#");
		}
		else
		{
			goTo(0,i);
				printf("#");
			goTo((size_t)cam.getFov()._x+1,i);
				printf("#");
		}
	}
}

void GameEngineConsole::goTo(size_t x, size_t y)
{
	c.X = (SHORT)x;
	c.Y = (SHORT)y;
	SetConsoleCursorPosition(hnd, c);
}

void GameEngineConsole::drawLevel(size_t mx, size_t my, size_t w, size_t h)
{
	double px = p.getPos()._x;
	double py = p.getPos()._y;
	
	size_t halfx = w / 2;
	size_t halfy = h / 2;

	size_t offsetx=0;
	size_t offsety=0;


	size_t starty=(size_t)py-halfy;
	size_t startx= (size_t)px-halfx;
	size_t endy= (size_t)py+halfy;
	size_t endx= (size_t)px+halfx;

	//Oblicz offset i startowe pozycje
	if (px + halfx > mx)
	{
		offsetx = halfx-(mx- (size_t)px);
		endx = mx;
		startx = mx - w;
	}
	if (py + halfy > my)
	{
		offsety = halfy-(my- (size_t)py);
		endy = my;
		starty = my - h;
	}
	if (py - halfy < 0)
	{
		offsety = (size_t)py-halfy;
		starty = 0;
		endy = h;
	}
	if (px - halfx < 0)
	{
		offsetx = (size_t)px - halfx;
		startx = 0;
		endx = w;
	}

	
	size_t calcpx = halfx + 1 + offsetx;
	size_t calcpy = halfy + 1 + offsety;
	//Zasadnicze rysowanie zawartości
	for (size_t y=starty; y < endy; ++y)
	{
		//goTo(1, y + 1);
		size_t cury = size_t(y - (py - halfy-offsety));
		for (size_t x = startx; x < endx; ++x)
		{
				size_t curx = size_t(x - (px - halfx - offsetx));
				Tile::Content a = _map.getContent(x, y);
			if ( curx+1 != calcpx || cury+1 != calcpy)
			{
				goTo(curx + 1, cury + 1);
				switch (a)
				{
				case Tile::Content::NOTHING:
				{
					printf(" ");
					break;
				}
				case Tile::Content::WALL:
				{
					printf("@");
					break;
				}
				}
			}
		}
	}
	

	//Draw Dynamics
	goTo( calcpx , calcpy );
	printf("P");
	/*goTo(43, 0);
	printf("PX: %d      ",px);
	goTo(43, 1);
	printf("PY: %d     ",py);*/

}
