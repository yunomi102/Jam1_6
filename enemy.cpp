#include"enemy.h"

circle ene1[enemynum1];
circle ene2[enemynum2];
circle ene3[enemynum3];
circle ene4[enemynum4];
circle ene5[enemynum5];
circle boss;

int enemycount1;
int enemycount2;
int enemycount3;
int enemycount4;
int enemycount5;

int enemy1img;
int enemy2img;
int enemy3img;
int enemy4img;
int enemy5img;
int bossimg;

int enemydownse;

void initenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		ene1[i].hp = enemy1hp;
		ene1[i].x = enemynum1x[i];
		ene1[i].y = enemynum1y[i];
		ene1[i].r = enemy1r;
		ene1[i].c = GetColor(255, 0, 0);
		ene1[i].fill = true;
		ene1[i].enable = true;
		ene1[i].time = 100;
	}
	enemy1img = LoadGraph("enemy01.png");
	for (int i = 0; i < enemynum2; i++)
	{
		ene2[i].hp = enemy2hp;
		ene2[i].x = enemynum2x[i];
		ene2[i].y = enemynum2y[i];
		ene2[i].r = enemy2r;
		ene2[i].c = GetColor(255, 0, 0);
		ene2[i].fill = true;
		ene2[i].enable = true;
		ene2[i].time = 100;
	}
	enemy2img = LoadGraph("enemy02.png");
	for (int i = 0; i < enemynum3; i++)
	{
		ene3[i].hp = enemy3hp;
		ene3[i].x = enemynum3x[i];
		ene3[i].y = enemynum3y[i];
		ene3[i].r = enemy3r;
		ene3[i].c = GetColor(255, 0, 0);
		ene3[i].fill = true;
		ene3[i].enable = true;
		ene3[i].time = 100;
	}
	enemy3img = LoadGraph("enemy03.png");
	for (int i = 0; i < enemynum4; i++)
	{
		ene4[i].hp = enemy4hp;
		ene4[i].x = enemynum4x[i];
		ene4[i].y = enemynum4y[i];
		ene4[i].r = enemy4r;
		ene4[i].c = GetColor(255, 0, 0);
		ene4[i].fill = true;
		ene4[i].enable = true;
		ene4[i].time = 100;
	}
	enemy4img = LoadGraph("enemy04.png");
	for (int i = 0; i < enemynum5; i++)
	{
		ene5[i].hp = enemy5hp;
		ene5[i].x = enemynum5x[i];
		ene5[i].y = enemynum5y[i];
		ene5[i].r = enemy5r;
		ene5[i].c = GetColor(255, 0, 0);
		ene5[i].fill = true;
		ene5[i].enable = true;
		ene5[i].time = 100;
	}
	enemy5img = LoadGraph("enemy05.png");
	boss.hp = bosshp;
	boss.x = bossx;
	boss.y = bossy;
	boss.r = bossr;
	boss.c = GetColor(255, 0, 0);
	boss.fill = true;
	boss.enable = true;
	bossimg = LoadGraph("boss.png");
	enemydownse = LoadSoundMem("maou_se_8bit08.mp3");
	enemycount1 = enemynum1;
	enemycount2 = enemynum2;
	enemycount3 = enemynum3;
	enemycount4 = enemynum4;
	enemycount5 = enemynum5;
}
void updateenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		if (ene1[i].time > 0)
		{
			ene1[i].time--;
		}
		if (canenemyshot(ene1[i]) && ene1[i].enable == true)
		{
			aimshot1(ene1[i]);
			straightshot1(170, ene1[i], 0, 0);
			straightshot1(190, ene1[i], 0, 0);
			ene1[i].time = 250;
		}
	}
	for (int i = 0; i < enemynum2; i++)
	{
		if (ene2[i].time > 0)
		{
			ene2[i].time--;
		}
		if (canenemyshot(ene2[i]) && ene2[i].enable == true)
		{
			aimshot2(ene2[i]);
			straightshot2(175, ene2[i], 0, 0);
			straightshot2(180, ene2[i], 0, 0);
			straightshot2(185, ene2[i], 0, 0);
			ene2[i].time = 250;
		}
	}
	for (int i = 0; i < enemynum3; i++)
	{
		if (ene3[i].time > 0)
		{
			ene3[i].time--;
		}
		if (canenemyshot(ene3[i]) && ene3[i].enable == true)
		{
			aimshot3(ene3[i]);
			straightshot3(165, ene3[i], 0, 0);
			straightshot3(175, ene3[i], 0, 0);
			straightshot3(185, ene3[i], 0, 0);
			straightshot3(195, ene3[i], 0, 0);
			ene3[i].time = 250;
		}
	}
	for (int i = 0; i < enemynum4; i++)
	{
		if (ene4[i].time > 0)
		{
			ene4[i].time--;
		}
		if (canenemyshot(ene4[i]) && ene4[i].enable == true)
		{
			aimshot4(ene4[i]);
			straightshot4(90, ene4[i], 0, 0);
			straightshot4(135, ene4[i], 0, 0);
			straightshot4(180, ene4[i], 0, 0);
			straightshot4(225, ene4[i], 0, 0);
			straightshot4(270, ene4[i], 0, 0);
			ene4[i].time = 250;
		}
	}
	for (int i = 0; i < enemynum5; i++)
	{
		if (ene5[i].time > 0)
		{
			ene5[i].time--;
		}
		if (canenemyshot(ene5[i]) && ene5[i].enable == true)
		{
			straightshot5(170, ene5[i], 0, 0);
			straightshot5(190, ene5[i], -2, 0);
			straightshot5(175, ene5[i], -4, 0);
			straightshot5(185, ene5[i], -6, 0);
			straightshot5(180, ene5[i], -8, 0);
			straightshot5(165, ene5[i], -10, 0);
			ene5[i].time = 250;
		}
	}
	if (boss.time > 0)
	{
		boss.time--;
	}
	if (canenemyshot(boss) && boss.enable == true)
	{
		aimshotboss(boss);
		straightshotboss(0, boss, 0, 0);
		straightshotboss(45, boss, 0, 0);
		straightshotboss(90, boss, 0, 0);
		straightshotboss(135, boss, 0, 0);
		straightshotboss(180, boss, 0, 0);
		straightshotboss(225, boss, 0, 0);
		straightshotboss(270, boss, 0, 0);
		straightshotboss(315, boss, 0, 0);
		boss.time = 150;
	}
	if (p.enable == true)
	{
		if (STtype == ST1)
		{
			for (int i = 0; i < enemynum1; i++)
			{
				ene1[i].x -= 1;
				if (ene1[i].x < -50 && ene1[i].enable == true)
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
				ene2[i].x -=0.9;
				if (ene2[i].x < -50 && ene2[i].enable == true)
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
				ene3[i].x -= 1.2;
				if (ene3[i].x < -50 && ene3[i].enable == true)
				{
					ene3[i].enable = false;
					enemycount3 -= 1;
				}
			}
		}
		else if (STtype == ST4)
		{
			for (int i = 0; i < enemynum4; i++)
			{
				ene4[i].x -= 0.75;
				if (ene4[i].x < -50 && ene4[i].enable == true)
				{
					ene4[i].enable = false;
					enemycount4 -= 1;
				}
			}
		}
		else if (STtype == ST5)
		{
			for (int i = 0; i < enemynum5; i++)
			{
				ene5[i].x -= 3;
				if (ene5[i].x < -50 && ene5[i].enable == true)
				{
					ene5[i].enable = false;
					enemycount5 -= 1;
				}
			}
		}
		else if (STtype == STB)
		{
			if (boss.x >= 400)
			{
				boss.x -= 2;
			}
		}
	}
}
void drawenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		if (ene1[i].enable == true)
		{
			DrawExtendGraph(ene1[i].x - (ene1[i].r * 1.4), ene1[i].y - ene1[i].r + (ene1[i].r / 5), ene1[i].x + (ene1[i].r * 1.4), ene1[i].y + ene1[i].r + (ene1[i].r / 5), enemy1img, ene1[i].fill);
		}
	}
	for (int i = 0; i < enemynum2; i++)
	{
		if (ene2[i].enable == true)
		{
			DrawExtendGraph(ene2[i].x - (ene2[i].r * 2), ene2[i].y - (ene2[i].r * 1.5), ene2[i].x + (ene2[i].r + (ene2[i].r / 5 * 2)), ene2[i].y + ene2[i].r, enemy2img, ene2[i].fill);
		}
	}
	for (int i = 0; i < enemynum3; i++)
	{
		if (ene3[i].enable == true)
		{
			DrawExtendGraph(ene3[i].x - (ene3[i].r * 1.3), ene3[i].y - (ene3[i].r * 1.1), ene3[i].x + (ene3[i].r * 1.3), ene3[i].y + (ene3[i].r * 1.1), enemy3img, ene3[i].fill);
		}
	}
	for (int i = 0; i < enemynum4; i++)
	{
		if (ene4[i].enable == true)
		{
			DrawExtendGraph(ene4[i].x - (ene4[i].r * 1.3), ene4[i].y - (ene4[i].r * 1.3), ene4[i].x + (ene4[i].r * 1.1), ene4[i].y + (ene4[i].r * 1.1), enemy4img, ene4[i].fill);
		}
	}
	for (int i = 0; i < enemynum5; i++)
	{
		if (ene5[i].enable == true)
		{
			DrawExtendGraph(ene5[i].x - ene5[i].r, ene5[i].y - ene5[i].r, ene5[i].x + ene5[i].r, ene5[i].y + ene5[i].r, enemy5img, ene5[i].fill);
		}
	}
	if (boss.enable == true)
	{
		DrawExtendGraph(boss.x - boss.r, boss.y - boss.r, boss.x + boss.r, boss.y + boss.r, bossimg, boss.fill);
	}
}