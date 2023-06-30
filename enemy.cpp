#include"enemy.h"

circle ene1[enemynum1];
circle ene2[enemynum2];

int enemy1img;
int enemy2img;

void initenemy(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		ene1[i].hp = enemy1hp;
		ene1[i].x = 600;
		ene1[i].y = 200;
		ene1[i].r = 20;
		ene1[i].c = GetColor(255, 0, 0);
		ene1[i].fill = true;
		ene1[i].enable = true;
	}
	for (int i = 0; i < enemynum1; i++)
	{
		ene2[i].hp = enemy2hp;
		ene2[i].x = 600;
		ene2[i].y = 400;
		ene2[i].r = 25;
		ene2[i].c = GetColor(255, 0, 0);
		ene2[i].fill = true;
		ene2[i].enable = true;
	}
	enemy1img = LoadGraph("enemy01.png");
	enemy2img = LoadGraph("enemy02.png");
}
void updateenemy(void)
{

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
	}
}