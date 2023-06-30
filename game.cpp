#include"game.h"

int white;
bool gameoverflag;
bool collision;

void initgame(void)
{
	collision = false;
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
	if(collision==true)
	{
		DrawCircle(p.x, p.y, p.r, p.c, p.fill);
		for (int i = 0; i < enemynum; i++)
		{
			if(ene1[i].enable==true)
			{
				DrawCircle(ene1[i].x, ene1[i].y, ene1[i].r, ene1[i].c, ene1[i].fill);
			}
			if (ene2[i].enable == true)
			{
				DrawCircle(ene2[i].x, ene2[i].y, ene2[i].r, ene2[i].c, ene2[i].fill);
			}
		}
	}
	DrawFormatString(100, 100, white, "体力%d", p.hp);
	DrawFormatString(100, 150, white, "無敵時間%d", p.time);
	DrawFormatString(100, 200, white, "クールタイム%d", pshot[0].time);

}