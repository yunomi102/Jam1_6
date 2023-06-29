#include"enemy.h"

circle ene1[enemynum];

void initenemy(void)
{
	for(int i=0;i< enemynum;i++)
	{
		ene1[i].x = 600;
		ene1[i].y = 300;
		ene1[i].r = 5;
		ene1[i].c = GetColor(255, 0, 0);
		ene1[i].fill = true;
	}
}
void updateenemy(void)
{

}
void drawenemy(void)
{
	for (int i = 0; i < enemynum; i++)
	{
		DrawCircle(ene1[i].x, ene1[i].y, ene1[i].r, ene1[i].c, ene1[i].fill);
	}
}