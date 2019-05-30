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
	size_t i = 1;
	Vec2t tmp((size_t)Start.X, i), tmp2((size_t)End.X, (size_t)End.Y);
	i += 8;
	ClearRectangle(tmp, tmp2);
	DrawLine(9); ++i;
	Stats(i); // 6
	DrawLine(15); ++i;//14
	Equipement(i); // 7
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

void GUI::Stats(size_t& starty)
{
	//goTo(Start.X + 1, Start.Y + i); printf("Base Stats"); ++i;//1
	goTo(Start.X + 1, Start.Y + starty); printf("Lvl    : %d",(int)player.getLvl()); printf(" XP: %d/%d       ", player.getcurxp(),player.getreqxp()); ++starty; //2
	goTo(Start.X + 1, Start.Y + starty); printf("Health : "); printf("%d/%d       ", (int)player.s.nHealth,(int)player.s.nMaxHealth); ++starty; //2
	goTo(Start.X + 1, Start.Y + starty); printf("Damage : "); printf("%d  ", (int)player.s.nDamage); ++starty; //3
	goTo(Start.X + 1, Start.Y + starty); printf("Armor  : "); printf("%d  ", (int)player.s.nArmor); ++starty; //4
	goTo(Start.X + 1, Start.Y + starty); printf("Speed  : "); printf("%d  ", (int)player.s.nSpeed); ++starty; //5
}

void GUI::Equipement(size_t& starty)
{
	std::vector<Item>& it = player.getItems();
	goTo(Start.X + 1, Start.Y + starty); printf("Equipement"); ++starty;//7
	goTo(Start.X + 1, Start.Y + starty); printf("Helmet     : %s", it[0].getName().c_str()); ++starty; //8
	goTo(Start.X + 1, Start.Y + starty); printf("Chestplate : %s", it[1].getName().c_str()); ++starty; //9
	goTo(Start.X + 1, Start.Y + starty); printf("Gloves     : %s", it[2].getName().c_str()); ++starty; //10
	goTo(Start.X + 1, Start.Y + starty); printf("Boots      : %s", it[3].getName().c_str()); ++starty; //11
	goTo(Start.X + 1, Start.Y + starty); printf("Weapon     : %s", it[4].getName().c_str()); ++starty; //12
	goTo(Start.X + 1, Start.Y + starty); printf("Gold       : %d", player.s.nGold); ++starty; //13
}

void GUI::DialogueBox(size_t &starty)
{
	int i = (int)starty;
	goTo(Start.X + 1, Start.Y + starty); printf(" "); ++starty;         //15
	goTo(Start.X + 1, Start.Y + starty); printf(" "); ++starty;         //16
	goTo(Start.X + 1, Start.Y + starty); printf(" "); ++starty;         //17
	goTo(Start.X + 1, Start.Y + starty); printf(" "); ++starty;         //18
	goTo(Start.X + 1, Start.Y + starty); printf("1. "); ++starty;         //19
	goTo(Start.X + 1, Start.Y + starty); printf("2. "); ++starty;         //20
	goTo(Start.X + 1, Start.Y + starty); printf("3. "); ++starty;         //21
	goTo(Start.X + 1, Start.Y + starty); printf("4. "); ++starty;         //22
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