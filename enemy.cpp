#include"enemy.h"

circle ene1[enemynum1];
circle ene2[enemynum2];
circle ene3[enemynum3];
circle ene4[enemynum4];
circle ene5[enemynum5];

int enemy1img;
int enemy2img;
int enemy3img;
int enemy4img;
int enemy5img;

int enemycount1;
int enemycount2;
int enemycount3;
int enemycount4;
int enemycount5;

int enemydownse;

void initenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		ene1[i].hp = enemy1hp;
		ene1[i].x = 900 + 100 * i;
		ene1[i].y = 300;
		ene1[i].r = 20;
		ene1[i].c = GetColor(255, 0, 0);
		ene1[i].fill = true;
		ene1[i].enable = true;
	}
	enemy1img = LoadGraph("enemy01.png");
	for (int i = 0; i < enemynum2; i++)
	{
		ene2[i].hp = enemy2hp;
		ene2[i].x = 900 + 100 * i;
		ene2[i].y = 300;
		ene2[i].r = 25;
		ene2[i].c = GetColor(255, 0, 0);
		ene2[i].fill = true;
		ene2[i].enable = true;
	}
	enemy2img = LoadGraph("enemy02.png");
	for (int i = 0; i < enemynum3; i++)
	{
		ene3[i].hp = enemy3hp;
		ene3[i].x = 900 + 100 * i;
		ene3[i].y = 300;
		ene3[i].r = 25;
		ene3[i].c = GetColor(255, 0, 0);
		ene3[i].fill = true;
		ene3[i].enable = true;
	}
	enemy3img = LoadGraph("enemy04.png");
	enemydownse = LoadSoundMem("maou_se_8bit08.mp3");
	enemycount1 = enemynum1;
	enemycount2 = enemynum2;
	enemycount3 = enemynum3;
	enemycount4 = enemynum4;
	enemycount5 = enemynum5;
}
void updateenemy(void)
{
	if (STtype == ST1)
	{
		for (int i = 0; i < enemynum1; i++)
		{
			ene1[i].x -= 2;
			if (ene1[i].x < 10 && ene1[i].enable == true)
			{
				ene1[i].enable = false;
				enemycount1 -= 1;
			}
		}
	}
	else if (STtype == ST2)
	{
		for (int i = 0; i < enemynum2; i++)
		{
			ene2[i].x -= 2;
			if (ene2[i].x < 10 && ene2[i].enable == true)
			{
				ene2[i].enable = false;
				enemycount2 -= 1;
			}
		}
	}
	else if (STtype == ST3)
	{
		for (int i = 0; i < enemynum3; i++)
		{
			ene3[i].x -= 2;
			if (ene3[i].x < 10 && ene3[i].enable == true)
			{
				ene3[i].enable = false;
				enemycount3 -= 1;
			}
		}
	}
	else if (STtype == ST4)
	{

	}
}
void drawenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		if (ene1[i].enable == true)
		{
			DrawExtendGraph(ene1[i].x - 30, ene1[i].y - 45, ene1[i].x + 30, ene1[i].y + 45, enemy1img, ene1[i].fill);
		}
		if (ene2[i].enable == true)
		{
			DrawExtendGraph(ene2[i].x - 50, ene2[i].y - 45, ene2[i].x + 40, ene2[i].y + 25, enemy2img, ene2[i].fill);
		}
		if (ene3[i].enable == true)
		{
			DrawExtendGraph(ene3[i].x - 50, ene3[i].y - 45, ene3[i].x + 40, ene3[i].y + 25, enemy3img, ene3[i].fill);
		}
	}
}