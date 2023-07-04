#include"game.h"

int white;
bool gameclearflag;
bool gameoverflag;
int score;

int playerhpimg;

void initgame(void)
{
	white = GetColor(255, 255, 255);
	gameclearflag = false;
	gameoverflag = true;
	score = 0;
	playerhpimg = LoadGraph("playerhp.png");
}
void updategame(void)
{
	if (boss.enable == false)
	{
		gameclearflag = true;
	}
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
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155);
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
		if (boss.enable == true)
		{
			DrawCircle(boss.x, boss.y, boss.r, boss.c, boss.fill);
		}
		for (int i = 0; i < enemyshotnum; i++) 
		{
			if (ene1shot[i].enable == true)
			{
				DrawCircle(ene1shot[i].x, ene1shot[i].y, ene1shot[i].r, ene1shot[i].c, ene1shot[i].fill);
			}
			if (ene2shot[i].enable == true)
			{
				DrawCircle(ene2shot[i].x, ene2shot[i].y, ene2shot[i].r, ene2shot[i].c, ene2shot[i].fill);
			}
			if (ene3shot[i].enable == true)
			{
				DrawCircle(ene3shot[i].x, ene3shot[i].y, ene3shot[i].r, ene3shot[i].c, ene3shot[i].fill);
			}
			if (ene4shot[i].enable == true)
			{
				DrawCircle(ene4shot[i].x, ene4shot[i].y, ene4shot[i].r, ene4shot[i].c, ene4shot[i].fill);
			}
			if (ene5shot[i].enable == true)
			{
				DrawCircle(ene5shot[i].x, ene5shot[i].y, ene5shot[i].r, ene5shot[i].c, ene5shot[i].fill);
			}
			if (bossshot[i].enable == true)
			{
				DrawCircle(bossshot[i].x, bossshot[i].y, bossshot[i].r, bossshot[i].c, bossshot[i].fill);
			}
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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
	DrawFormatString(650, 50, white, "score:%d", score);
}