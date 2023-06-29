#include"game.h"

int white;
bool gameoverflag;

void initgame(void)
{
	white = GetColor(255, 255, 255);
	gameoverflag = false;
}
void updategame(void)
{
	if (p.hp == 0)
	{
		gameoverflag = true;
		p.enable = false;
	}
}
void drawgame(void)
{
	DrawFormatString(700, 200, white, "‘Ì—Í%d", p.hp);
}