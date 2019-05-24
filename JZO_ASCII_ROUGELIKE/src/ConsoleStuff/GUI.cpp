#include "GUI.h"



GUI::GUI(short startx, short starty, short endx, short endy,Player&p)
	:
	 h(GetStdHandle(STD_OUTPUT_HANDLE))
	,player(p)
{
	Start.X = startx;
	Start.Y = starty;
	End.X = endx-1;
	End.Y = endy-1;
}


GUI::~GUI()
{
}

void GUI::drawClear()
{
	//Obramowanie
	DrawBorder();
	
	//Czyszczenie œrodka
	ClearRectangle(Start, End);
	
	//Start Gui
	int i = 1;
	Stats(i); // 6
	DrawLine(6); ++i; i = 7;
	Equipement(i); // 7
	DrawLine(14); ++i;  i = 15;       //14
	Vec2t tmp((size_t)Start.X, i), tmp2((size_t)End.X, (size_t)End.Y);
	ClearRectangle(tmp, tmp2);
}

void GUI::DrawBorder()
{
	//Top
	goTo(Start.X, Start.Y);
	printf("+");
	for(size_t i = Start.X, e = End.X-1; i < e; ++i)
	{
		printf("-");
	}
	printf("+");
	//Bottom
	goTo(Start.X, End.Y);
	printf("+");
	for (size_t i = Start.X, e = End.X-1; i < e; ++i)
	{
		printf("-");
	}
	printf("+");

	//Left
	goTo(Start.X, Start.Y);
	for (size_t i = Start.Y+1, e = End.Y; i < e; ++i)
	{
		goTo(Start.X, i);
		printf("|");
	}

	//Right
	goTo(End.X, Start.Y);
	for (size_t i = Start.Y + 1, e = End.Y; i < e; ++i)
	{
		goTo(End.X, i);
		printf("|");
	}
}

void GUI::goTo(size_t x, size_t y)
{
	COORD tmp;
	tmp.X = (SHORT)x;
	tmp.Y = (SHORT)y;
	SetConsoleCursorPosition(h, tmp);
}

void GUI::ClearRectangle(COORD start, COORD end)
{
	for (size_t i = 0, e = end.Y - start.Y-1; i < e; ++i)
	{
		goTo(start.X+1, start.Y+i+1);
		for (size_t j = 0, e2 = end.X - start.X-1; j < e2; ++j) printf(" ");
	}
}

void GUI::ClearRectangle(Vec2t start, Vec2t end)
{
	COORD tmp,tmp2;
	tmp.X = (SHORT)start._x;
	tmp.Y = (SHORT)start._y;
	tmp2.X = (SHORT)end._x;
	tmp2.Y = (SHORT)end._y;
	ClearRectangle(tmp, tmp2);
}

void GUI::DrawLine(size_t starty)
{
	goTo(Start.X+1, starty);
	for(size_t j = 0, e2 = End.X - Start.X - 1; j < e2; ++j) printf("-");
}

void GUI::Stats(size_t starty)
{
	int i = (int)starty;
	goTo(Start.X + 1, Start.Y + i); printf("Base Stats"); ++i;//1
	goTo(Start.X + 1, Start.Y + i); printf("Health : "); printf("%d/%d       ", (int)player.nHealth,(int)player.nMaxHealth); ++i; //2
	goTo(Start.X + 1, Start.Y + i); printf("Damage : "); printf("%d  ", (int)player.nDamage); ++i; //3
	goTo(Start.X + 1, Start.Y + i); printf("Armor  : "); printf("%d  ", (int)player.nArmor); ++i; //4
	goTo(Start.X + 1, Start.Y + i); printf("Speed  : "); printf("%d  ", (int)player.nSpeed); ++i; //5
}

void GUI::Equipement(size_t starty)
{
	int i = (int)starty;
	goTo(Start.X + 1, Start.Y + i); printf("Equipement"); ++i;//7
	goTo(Start.X + 1, Start.Y + i); printf("Helmet     : "); ++i; //8
	goTo(Start.X + 1, Start.Y + i); printf("Chestplate : "); ++i; //9
	goTo(Start.X + 1, Start.Y + i); printf("Gloves     : "); ++i; //10
	goTo(Start.X + 1, Start.Y + i); printf("Boots      : "); ++i; //11
	goTo(Start.X + 1, Start.Y + i); printf("Weapon     : "); ++i; //12
	goTo(Start.X + 1, Start.Y + i); printf("Gold       : "); ++i; //13
}

void GUI::DialogueBox(size_t starty)
{
	int i = (int)starty;
	goTo(Start.X + 1, Start.Y + i); printf(" "); ++i;         //15
	goTo(Start.X + 1, Start.Y + i); printf(" "); ++i;         //16
	goTo(Start.X + 1, Start.Y + i); printf(" "); ++i;         //17
	goTo(Start.X + 1, Start.Y + i); printf(" "); ++i;         //18
	goTo(Start.X + 1, Start.Y + i); printf("1. "); ++i;         //19
	goTo(Start.X + 1, Start.Y + i); printf("2. "); ++i;         //20
	goTo(Start.X + 1, Start.Y + i); printf("3. "); ++i;         //21
	goTo(Start.X + 1, Start.Y + i); printf("4. "); ++i;         //22
}


//+-------------------------------------- +
//|Base Stats                            |
//|Health : 100 / 100                    |
//|Damage : 20                           |
//|Armor : 5                             |
//|Speed : 5                             |
//|--------------------------------------|
//|Equipement                            |
//|Helmet : None                         |
//|Chestplate : None                     |
//|Gloves : None                         |
//|Boots : None                          |
//|                                      |
//|                                      |
//|######################################|
//|--------------------------------------|
//|Paladyn                               |
//|                                      |
//|                                      |
//|                                      |
//|1.                                    |
//|2.                                    |
//|3.                                    |
//|4.                                    |
//+-------------------------------------- +