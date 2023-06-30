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
		p.enable = false;
		gameoverflag = true;
	}
}
void drawgame(void)
{
	if (collision == true)
	{
		if (p.enable == true)
		{
			DrawCircle(p.x, p.y, p.r, p.c, p.fill);
		}
		for (int i = 0; i < playershotnum; i++)
		{
			if (pshot1[i].enable == true)
			{
				DrawCircle(pshot1[i].x, pshot1[i].y, pshot1[i].r, pshot1[i].c, pshot1[i].fill);
			}
			if (pshot2[i].enable == true)
			{
				DrawCircle(pshot2[i].x, pshot2[i].y, pshot2[i].r, pshot2[i].c, pshot2[i].fill);
			}
		}
		for (int i = 0; i < enemynum; i++)
		{
			if (ene1[i].enable == true)
			{
				DrawCircle(ene1[i].x, ene1[i].y, ene1[i].r, ene1[i].c, ene1[i].fill);
			}
			if (ene2[i].enable == true)
			{
				DrawCircle(ene2[i].x, ene2[i].y, ene2[i].r, ene2[i].c, ene2[i].fill);
			}
		}
	}
	DrawFormatString(p.x - 30, p.y - 50, white, "体力%d", p.hp);
	DrawFormatString(p.x - 40, p.y + 40, white, "無敵時間%d", p.time);
	DrawFormatString(p.x - 50, p.y + 55, white, "クールタイム%d", pshot1[0].time);
}