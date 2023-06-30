#include"playershot.h"

circle pshot[playershotnum];

void initplayershot(void)
{
	for (int i = 0; i < playershotnum; i++)
	{
		pshot[i].damage = playershotdamage;
		pshot[i].r = 10;
		pshot[i].c = GetColor(0, 255, 155);
		pshot[i].fill = true;
		pshot[i].enable = false;
		pshot[0].time = pshotcooltime;
	}
}
void updateplayershot(void)
{
	if (pshot[0].time > 0)
	{
		pshot[0].time--;
	}
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot[i].enable == true)
		{
			pshot[i].x = pshot[i].x + pshot[i].vx;
			pshot[i].y = pshot[i].y - pshot[i].vy;
			if (pshot[i].x >= 800 ||
				pshot[i].y <= 0 ||
				pshot[i].y >= 600)
			{
				pshot[i].enable = false;
			}
		}
	}
	if (gameoverflag == false)
	{
		if (pshot[0].time == 0 && CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			for (int i = 0; i < playershotnum; i++)
			{
				if (pshot[i].enable == false)
				{
					shot(350);
					shot(0);
					shot(10);
					pshot[0].time = pshotcooltime;
					break;
				}
			}
		}
	}
}
void drawplayershot(void)
{
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot[i].enable == true)
		{
			DrawCircle(pshot[i].x, pshot[i].y, pshot[i].r, pshot[i].c, pshot[i].fill);
		}
	}
}
void shot(int rad)
{
	for (int i = 0; i < playershotnum; i++)
	{
		if (pshot[i].enable == false)
		{
			pshot[i].x = p.x;
			pshot[i].y = p.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;
			double speed = 5;
			pshot[i].vx = speed * cos(minrad * rad);
			pshot[i].vy = speed * sin(minrad * rad);
			pshot[i].enable = true;
			break;
		}
	}
}