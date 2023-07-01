#include"game.h"

int white;
bool gameoverflag;

int playerhpimg;

void initgame(void)
{
	white = GetColor(255, 255, 255);
	gameoverflag = false;
	playerhpimg = LoadGraph("playerhp.png");
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
		for (int i = 0; i < enemynum1; i++)
		{
			if (ene1[i].enable == true)
			{
				DrawCircle(ene1[i].x, ene1[i].y, ene1[i].r, ene1[i].c, ene1[i].fill);
			}
		}
		for (int i = 0; i < enemynum2; i++)
		{
			if (ene2[i].enable == true)
			{
				DrawCircle(ene2[i].x, ene2[i].y, ene2[i].r, ene2[i].c, ene2[i].fill);
			}
		}
		for (int i = 0; i < enemynum3; i++)
		{
			if (ene3[i].enable == true)
			{
				DrawCircle(ene3[i].x, ene3[i].y, ene3[i].r, ene3[i].c, ene3[i].fill);
			}
		}
		for (int i = 0; i < enemynum4; i++)
		{
			if (ene4[i].enable == true)
			{
				DrawCircle(ene4[i].x, ene4[i].y, ene4[i].r, ene4[i].c, ene4[i].fill);
			}
		}
		for (int i = 0; i < enemynum5; i++)
		{
			if (ene5[i].enable == true)
			{
				DrawCircle(ene5[i].x, ene5[i].y, ene5[i].r, ene5[i].c, ene5[i].fill);
			}
		}
	}
	if (p.time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155);
	}
	for (int i = 0; i < p.hp; i++)
	{
		DrawExtendGraph(5 + (i * 50), 5, 95 + (i * 50), 65, playerhpimg, true);
	}
	if (pshot1[0].time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 75);
		DrawExtendGraph(p.x - 25 * (pshot1[0].time / pshotcooltime + 1), p.y - 45 * (pshot1[0].time / pshotcooltime + 1), p.x + 35 * (pshot1[0].time / pshotcooltime + 1), p.y + 45 * (pshot1[0].time / pshotcooltime + 1), playerimg, true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}