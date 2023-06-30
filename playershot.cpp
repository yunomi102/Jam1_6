#include"playershot.h"

circle pshot1[playershotnum];
circle pshot2[playershotnum];
int enemyshotimg1;
int enemyshotimg2;

void initplayershot(void)
{
	for (int i = 0; i < playershotnum; i++)
	{
		pshot1[i].damage = playershotdamage1;
		pshot1[i].r = 15;
		pshot1[i].c = GetColor(0, 255, 155);
		pshot1[i].fill = true;
		pshot1[i].enable = false;
		pshot1[0].time = pshotcooltime;
	}
	enemyshotimg1 = LoadGraph("shot01.png");
	for (int i = 0; i < playershotnum; i++)
	{
		pshot2[i].damage = playershotdamage2;
		pshot2[i].r = 15;
		pshot2[i].c = GetColor(0, 255, 155);
		pshot2[i].fill = true;
		pshot2[i].enable = false;
		pshot2[0].time = pshotcooltime;
	}
	enemyshotimg2 = LoadGraph("shot02.png");
}
void updateplayershot(void)
{
	if (pshot1[0].time > 0 && p.enable == true)
	{
		pshot1[0].time--;
	}
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot1[i].enable == true)
		{
			pshot1[i].x = pshot1[i].x + pshot1[i].vx;
			pshot1[i].y = pshot1[i].y - pshot1[i].vy;
			if (pshot1[i].x >= 800 ||
				pshot1[i].y <= 0 ||
				pshot1[i].y >= 600)
			{
				pshot1[i].enable = false;
			}
		}
		if (pshot2[i].enable == true)
		{
			pshot2[i].x = pshot2[i].x + pshot2[i].vx;
			pshot2[i].y = pshot2[i].y - pshot2[i].vy;
			if (pshot2[i].x >= 800 ||
				pshot2[i].y <= 0 ||
				pshot2[i].y >= 600)
			{
				pshot2[i].enable = false;
			}
		}
	}
	if (pshot1[0].time == 0 && CheckHitKey(KEY_INPUT_SPACE) == 1 && CheckHitKey(KEY_INPUT_LSHIFT) == 1)
	{
		for (int i = 0; i < playershotnum; i++)
		{
			if (pshot2[i].enable == false && p.enable == true)
			{
				shot2(350);
				shot2(0);
				shot2(10);
				pshot1[0].time = pshotcooltime;
				break;
			}
		}
	}
	else if (pshot1[0].time == 0 && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		for (int i = 0; i < playershotnum; i++)
		{
			if (pshot1[i].enable == false && p.enable == true)
			{
				shot1(345);
				shot1(0);
				shot1(15);
				pshot1[0].time = pshotcooltime;
				break;
			}
		}
	}
}
void drawplayershot(void)
{
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot1[i].enable == true)
		{
			DrawExtendGraph(pshot1[i].x - 20, pshot1[i].y - 20, pshot1[i].x + 20, pshot1[i].y + 20, enemyshotimg1, true);
		}
		if (pshot2[i].enable == true)
		{
			DrawExtendGraph(pshot2[i].x - 20, pshot2[i].y - 20, pshot2[i].x + 20, pshot2[i].y + 20, enemyshotimg2, true);
		}
	}
}
void shot1(int rad)
{
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot1[i].enable == false)
		{
			pshot1[i].x = p.x;
			pshot1[i].y = p.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 2.5;
			pshot1[i].vx = speed * cos(minrad * rad);
			pshot1[i].vy = speed * sin(minrad * rad);
			pshot1[i].enable = true;
			break;
		}
	}
}
void shot2(int rad)
{
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot2[i].enable == false)
		{
			pshot2[i].x = p.x;
			pshot2[i].y = p.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 2.5;
			pshot2[i].vx = speed * cos(minrad * rad);
			pshot2[i].vy = speed * sin(minrad * rad);
			pshot2[i].enable = true;
			break;
		}
	}
}