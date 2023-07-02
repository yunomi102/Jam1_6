#include"playershot.h"

circle pshot1[playershotnum];
circle pshot2[playershotnum];

int playershotimg1;
int playershotimg2;

int shot1se;
int shot2se;

void initplayershot(void)
{
	pshot1[0].time = 0;
	for (int i = 0; i < playershotnum; i++)
	{
		pshot1[i].damage = playershotdamage1;
		pshot1[i].r = 15;
		pshot1[i].c = GetColor(0, 255, 155);
		pshot1[i].fill = true;
		pshot1[i].enable = false;
	}
	playershotimg1 = LoadGraph("shot01.png");
	shot1se = LoadSoundMem("shot1se.mp3");
	for (int i = 0; i < playershotnum; i++)
	{
		pshot2[i].damage = playershotdamage2;
		pshot2[i].r = 15;
		pshot2[i].c = GetColor(0, 255, 155);
		pshot2[i].fill = true;
		pshot2[i].enable = false;
	}
	playershotimg2 = LoadGraph("shot02.png");
	shot2se = LoadSoundMem("shot2se.mp3");
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
			if (pshot1[i].x > 800 ||
				pshot1[i].x < 0 ||
				pshot1[i].y < 0 ||
				pshot1[i].y > 600)
			{
				pshot1[i].enable = false;
			}
		}
		if (pshot2[i].enable == true)
		{
			pshot2[i].x = pshot2[i].x + pshot2[i].vx;
			pshot2[i].y = pshot2[i].y - pshot2[i].vy;
			if (pshot2[i].x >= 800 ||
				pshot2[i].x < 0 ||
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
				PlaySoundMem(shot2se, DX_PLAYTYPE_BACK);
				shot2(320);
				shot2(345);
				shot2(0);
				shot2(15);
				shot2(40);
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
				PlaySoundMem(shot1se, DX_PLAYTYPE_BACK);
				shot1(270);
				shot1(340);
				shot1(350);
				shot1(0);
				shot1(10);
				shot1(20);
				shot1(90);
				shot1(180);
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
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 250);
			DrawExtendGraph(pshot1[i].x - 20, pshot1[i].y - 20, pshot1[i].x + 20, pshot1[i].y + 20, playershotimg1, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		if (pshot2[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
			DrawExtendGraph(pshot2[i].x - 20, pshot2[i].y - 20, pshot2[i].x + 20, pshot2[i].y + 20, playershotimg2, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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