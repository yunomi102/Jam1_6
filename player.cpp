#include"player.h"

circle p;

void initplayer(void)
{
	p.x = 200;
	p.y = 300;
	p.vx = 1.5;
	p.vy = 2;
	p.r = 5;
	p.c = GetColor(255, 255, 255);
	p.fill = true;
	p.hp = 2;
	p.time = 0;
}
void updateplayer(void)
{
	if (CheckHitKey(KEY_INPUT_W) == 1 && p.y > 0)
	{
		p.y -= p.vy;
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1)
		{
			p.y -= p.vy;
		}
	}
	if (CheckHitKey(KEY_INPUT_S) == 1 && p.y < 599)
	{
		p.y += p.vy;
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1)
		{
			p.y += p.vy;
		}
	}
	if (CheckHitKey(KEY_INPUT_A) == 1 && p.x > 0)
	{
		p.x -= p.vx;
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1)
		{
			p.x -= p.vx;
		}
	}
	if (CheckHitKey(KEY_INPUT_D) == 1 && p.x < 799)
	{
		p.x += p.vx;
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1)
		{
			p.x += p.vx;
		}
	}
	if (p.time > 0)
	{
		p.time--;
	}
}
void drawplayer(void)
{
	if (p.time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155);
	}
	DrawCircle(p.x, p.y, p.r, p.c, p.fill);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}