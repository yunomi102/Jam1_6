#include"enemyshot.h"

circle ene1shot[enemyshotnum];
circle ene2shot[enemyshotnum];
circle ene3shot[enemyshotnum];
circle ene4shot[enemyshotnum];
circle ene5shot[enemyshotnum];
circle bossshot[enemyshotnum];

int enemyshotimg;

void initenemyshot(void)
{
	for (int i = 0; i < enemyshotnum; i++)
	{
		ene1shot[i].r = 15;
		ene1shot[i].c = GetColor(0, 0, 255);
		ene1shot[i].fill = true;
		ene1shot[i].enable = false;
		ene2shot[i].r = 15;
		ene2shot[i].c = GetColor(0, 0, 255);
		ene2shot[i].fill = true;
		ene2shot[i].enable = false;
		ene3shot[i].r = 10;
		ene3shot[i].c = GetColor(0, 0, 255);
		ene3shot[i].fill = true;
		ene3shot[i].enable = false;
		ene4shot[i].r = 15;
		ene4shot[i].c = GetColor(0, 0, 255);
		ene4shot[i].fill = true;
		ene4shot[i].enable = false;
		ene5shot[i].r = 5;
		ene5shot[i].c = GetColor(0, 0, 255);
		ene5shot[i].fill = true;
		ene5shot[i].enable = false;
		bossshot[i].r = 25;
		bossshot[i].c = GetColor(0, 0, 255);
		bossshot[i].fill = true;
		bossshot[i].enable = false;
	}
	enemyshotimg = LoadGraph("enemyshot.png");
}
bool canenemyshot(circle enemy)
{
	if (enemy.time <= 0)
	{
		if (enemy.x >= 0 &&
			enemy.x < 800 &&
			enemy.y>0 &&
			enemy.y < 600)
		{
			return true;
		}
	}
	return false;
}
void updateenemyshot(void)
{
	for (int i = 0; i < enemyshotnum; i++)
	{
		if (ene1shot[i].enable == true)
		{
			ene1shot[i].x = ene1shot[i].x + ene1shot[i].vx;
			ene1shot[i].y = ene1shot[i].y + ene1shot[i].vy;
			if (ene1shot[i].x >= 800 ||
				ene1shot[i].x < 0 ||
				ene1shot[i].y >= 600 ||
				ene1shot[i].y < 0)
			{
				ene1shot[i].enable = false;
			}
		}
		if (ene2shot[i].enable == true)
		{
			ene2shot[i].x = ene2shot[i].x + ene2shot[i].vx;
			ene2shot[i].y = ene2shot[i].y + ene2shot[i].vy;
			if (ene2shot[i].x >= 800 ||
				ene2shot[i].x < 0 ||
				ene2shot[i].y >= 600 ||
				ene2shot[i].y < 0)
			{
				ene2shot[i].enable = false;
			}
		}
		if (ene3shot[i].enable == true)
		{
			ene3shot[i].x = ene3shot[i].x + ene3shot[i].vx;
			ene3shot[i].y = ene3shot[i].y + ene3shot[i].vy;
			if (ene3shot[i].x >= 800 ||
				ene3shot[i].x < 0 ||
				ene3shot[i].y >= 600 ||
				ene3shot[i].y < 0)
			{
				ene3shot[i].enable = false;
			}
		}
		if (ene4shot[i].enable == true)
		{
			ene4shot[i].x = ene4shot[i].x + ene4shot[i].vx;
			ene4shot[i].y = ene4shot[i].y + ene4shot[i].vy;
			if (ene4shot[i].x >= 800 ||
				ene4shot[i].x < 0 ||
				ene4shot[i].y >= 600 ||
				ene4shot[i].y < 0)
			{
				ene4shot[i].enable = false;
			}
		}
		if (ene5shot[i].enable == true)
		{
			ene5shot[i].x = ene5shot[i].x + ene5shot[i].vx;
			ene5shot[i].y = ene5shot[i].y + ene5shot[i].vy;
			if (ene5shot[i].x >= 800 ||
				ene5shot[i].x < 0 ||
				ene5shot[i].y >= 600 ||
				ene5shot[i].y < 0)
			{
				ene5shot[i].enable = false;
			}
		}
		if (bossshot[i].enable == true)
		{
			bossshot[i].x = bossshot[i].x + bossshot[i].vx;
			bossshot[i].y = bossshot[i].y + bossshot[i].vy;
			if (bossshot[i].x >= 800 ||
				bossshot[i].x < 0 ||
				bossshot[i].y >= 600 ||
				bossshot[i].y < 0)
			{
				bossshot[i].enable = false;
			}
		}
	}
}
void drawenemyshot(void)
{
	for (int i = 0; i < enemyshotnum; i++)
	{
		if (ene1shot[i].enable == true)
		{
			DrawExtendGraph(ene1shot[i].x - ene1shot[i].r, ene1shot[i].y - ene1shot[i].r, ene1shot[i].x + ene1shot[i].r, ene1shot[i].y + ene1shot[i].r, enemyshotimg, ene1shot[i].fill);
		}
		if (ene2shot[i].enable == true)
		{
			DrawExtendGraph(ene2shot[i].x - ene2shot[i].r, ene2shot[i].y - ene2shot[i].r, ene2shot[i].x + ene2shot[i].r, ene2shot[i].y + ene2shot[i].r, enemyshotimg, ene2shot[i].fill);
		}
		if (ene3shot[i].enable == true)
		{
			DrawExtendGraph(ene3shot[i].x - ene3shot[i].r, ene3shot[i].y - ene3shot[i].r, ene3shot[i].x + ene3shot[i].r, ene3shot[i].y + ene3shot[i].r, enemyshotimg, ene3shot[i].fill);
		}
		if (ene4shot[i].enable == true)
		{
			DrawExtendGraph(ene4shot[i].x - ene4shot[i].r, ene4shot[i].y - ene4shot[i].r, ene4shot[i].x + ene4shot[i].r, ene4shot[i].y + ene4shot[i].r, enemyshotimg, ene4shot[i].fill);
		}
		if (ene5shot[i].enable == true)
		{
			DrawExtendGraph(ene5shot[i].x - ene5shot[i].r, ene5shot[i].y - ene5shot[i].r, ene5shot[i].x + ene5shot[i].r, ene5shot[i].y + ene5shot[i].r, enemyshotimg, ene5shot[i].fill);
		}
		if (bossshot[i].enable == true)
		{
			DrawExtendGraph(bossshot[i].x - bossshot[i].r, bossshot[i].y - bossshot[i].r, bossshot[i].x + bossshot[i].r, bossshot[i].y + bossshot[i].r, enemyshotimg, bossshot[i].fill);
		}
	}
}
void straightshot1(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene1shot[j].enable == false)
		{
			ene1shot[j].x = enemy.x + shiftx;
			ene1shot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 3.0;
			ene1shot[j].vx = speed * cos(minrad * rad);
			ene1shot[j].vy = speed * sin(minrad * rad);
			ene1shot[j].enable = true;
			break;
		}
	}
}
void straightshot2(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene2shot[j].enable == false)
		{
			ene2shot[j].x = enemy.x + shiftx;
			ene2shot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 3.5;
			ene2shot[j].vx = speed * cos(minrad * rad);
			ene2shot[j].vy = speed * sin(minrad * rad);
			ene2shot[j].enable = true;
			break;
		}
	}
}
void straightshot3(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene3shot[j].enable == false)
		{
			ene3shot[j].x = enemy.x + shiftx;
			ene3shot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 2.5;
			ene3shot[j].vx = speed * cos(minrad * rad);
			ene3shot[j].vy = speed * sin(minrad * rad);
			ene3shot[j].enable = true;
			break;
		}
	}
}
void straightshot4(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene4shot[j].enable == false)
		{
			ene4shot[j].x = enemy.x + shiftx;
			ene4shot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 3.0;
			ene4shot[j].vx = speed * cos(minrad * rad);
			ene4shot[j].vy = speed * sin(minrad * rad);
			ene4shot[j].enable = true;
			break;
		}
	}
}
void straightshot5(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene5shot[j].enable == false)
		{
			ene5shot[j].x = enemy.x + shiftx;
			ene5shot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 5.0;
			ene5shot[j].vx = speed * cos(minrad * rad);
			ene5shot[j].vy = speed * sin(minrad * rad);
			ene5shot[j].enable = true;
			break;
		}
	}
}
void straightshotboss(int rad, circle enemy, int shiftx, int shifty)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (bossshot[j].enable == false)
		{
			bossshot[j].x = enemy.x + shiftx;
			bossshot[j].y = enemy.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 4;
			bossshot[j].vx = speed * cos(minrad * rad);
			bossshot[j].vy = speed * sin(minrad * rad);
			bossshot[j].enable = true;
			bossshot[j].vvx = -bossshot[j].vx * 0.002;
			bossshot[j].vvy = -bossshot[j].vy * 0.002;
			break;
		}
	}
}
void aimshot1(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene1shot[j].enable == false)
		{
			ene1shot[j].x = ene.x;
			ene1shot[j].y = ene.y;
			double speed = 1.0;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			ene1shot[j].vx = speed * (dx / d);
			ene1shot[j].vy = speed * (dy / d);
			ene1shot[j].enable = true;
			break;
		}
	}
}
void aimshot2(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene2shot[j].enable == false)
		{
			ene2shot[j].x = ene.x;
			ene2shot[j].y = ene.y;
			double speed = 1.5;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			ene2shot[j].vx = speed * (dx / d);
			ene2shot[j].vy = speed * (dy / d);
			ene2shot[j].enable = true;
			break;
		}
	}
}
void aimshot3(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene3shot[j].enable == false)
		{
			ene3shot[j].x = ene.x;
			ene3shot[j].y = ene.y;
			double speed = 2.0;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			ene3shot[j].vx = speed * (dx / d);
			ene3shot[j].vy = speed * (dy / d);
			ene3shot[j].enable = true;
			break;
		}
	}
}
void aimshot4(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene4shot[j].enable == false)
		{
			ene4shot[j].x = ene.x;
			ene4shot[j].y = ene.y;
			double speed = 2.5;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			ene4shot[j].vx = speed * (dx / d);
			ene4shot[j].vy = speed * (dy / d);
			ene4shot[j].enable = true;
			break;
		}
	}
}
void aimshot5(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (ene5shot[j].enable == false)
		{
			ene5shot[j].x = ene.x;
			ene5shot[j].y = ene.y;
			double speed = 3;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			ene5shot[j].vx = speed * (dx / d);
			ene5shot[j].vy = speed * (dy / d);
			ene5shot[j].enable = true;
			break;
		}
	}
}
void aimshotboss(circle ene)
{
	for (int j = 0; j < enemyshotnum; j++)
	{
		if (bossshot[j].enable == false)
		{
			bossshot[j].x = ene.x;
			bossshot[j].y = ene.y;
			double speed = 3;
			double dx = p.x - ene.x;
			double dy = p.y - ene.y;
			double d = sqrt(dx * dx + dy * dy);
			bossshot[j].vx = speed * (dx / d);
			bossshot[j].vy = speed * (dy / d);
			bossshot[j].enable = true;
			bossshot[j].vvx = bossshot[j].vx * 0.01;
			bossshot[j].vvy = bossshot[j].vy * 0.01;
			break;
		}
	}
}