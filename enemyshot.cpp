#include"enemyshot.h"

circle ene1shot[enemyshotnum];
circle ene2shot[enemyshotnum];
circle ene3shot[enemyshotnum];
circle ene4shot[enemyshotnum];
circle ene5shot[enemyshotnum];
circle bossshot[enemyshotnum];

void initenemyshot(void)
{
	for (int i = 0; i < enemyshotnum; i++)
	{
		ene1shot[i].r = 10;
		ene1shot[i].c = GetColor(0, 0, 255);
		ene1shot[i].fill = true;
		ene1shot[i].enable = false;
		ene2shot[i].r = 10;
		ene2shot[i].c = GetColor(0, 0, 255);
		ene2shot[i].fill = true;
		ene2shot[i].enable = false;
		ene3shot[i].r = 10;
		ene3shot[i].c = GetColor(0, 0, 255);
		ene3shot[i].fill = true;
		ene3shot[i].enable = false;
		ene4shot[i].r = 10;
		ene4shot[i].c = GetColor(0, 0, 255);
		ene4shot[i].fill = true;
		ene4shot[i].enable = false;
		ene5shot[i].r = 10;
		ene5shot[i].c = GetColor(0, 0, 255);
		ene5shot[i].fill = true;
		ene5shot[i].enable = false;
		bossshot[i].r = 10;
		bossshot[i].c = GetColor(0, 0, 255);
		bossshot[i].fill = true;
		bossshot[i].enable = false;
	}
}
void updateenemyshot(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		DrawFormatString(300, 50 + (i * 50), GetColor(255, 255, 255), "%f", ene1[i].time);
		if (ene1[i].enable == true)
		{
			if (ene1[i].time <= 0)
			{
				
				for (int j = 0; j < enemyshotnum; j++)
				{
					straightshot(180, ene1[i], ene1shot[i], 0, 0);
				}
			}

			if (ene1shot[i].enable == true)
			{
				ene1shot[i].x = ene1shot[i].x + ene1shot[i].vx;
				ene1shot[i].y = ene1shot[i].y + ene1shot[i].vy;
			}
			if (ene1[i].time > 0 && ene1[i].x <= 800 && ene1[i].x > 0 && ene1[i].y <= 600 && ene1[i].y > 0)
			{
				ene1[i].time--;
			}
			else if (ene1[i].time <= 0)
			{
				DrawString(200, 400, "ahfueiaagaweo", GetColor(255, 255, 255));
			}
			/*
						if (ene1shot[i].x >= 800 ||
				ene1shot[i].x < 0 ||
				ene1shot[i].y >= 600 ||
				ene1shot[i].y < 0)
			{
				ene1shot[i].enable = false;
			}
			*/

		}
	}
}
void drawenemyshot(void)
{
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
}
void straightshot(int rad, circle enemy, circle enemyshot, int shiftx, int shifty)
{
	for (int k = 0; k < enemyshotnum; k++)
	{
		if (enemyshot.enable == false)
		{
			enemyshot.x = enemy.x + shiftx;
			enemyshot.y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 3.0;
			enemyshot.vx = speed * cos(minrad * rad);
			enemyshot.vy = speed * sin(minrad * rad);
			enemyshot.enable = true;
			break;
		}
	}
}
void aimShot(circle ene, circle enemyshot)
{
	for (int k = 0; k < enemyshotnum; k++)
	{
		if (enemyshot.enable == false)
		{
			enemyshot.x = ene.x;
			enemyshot.y = ene.y;
			double speed = 3.0;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			enemyshot.vx = speed * (dx / d);
			enemyshot.vy = speed * (dy / d);
			enemyshot.enable = true;
			break;
		}
	}
}