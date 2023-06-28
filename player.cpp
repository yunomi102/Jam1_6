#include"player.h"

circle p;

void initplayer(void)
{
	p.x = 200;
	p.y = 300;
	p.s = 2;
	p.r = 5;
	p.c = GetColor(255, 255, 255);
	p.fill = true;
	p.hp = 2;
	p.time = 0;
}
void updateplayer(void)
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		p.y -= p.s;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		p.y += p.s;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		p.x -= p.s;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		p.x += p.s;
	}
}
void drawplayer(void)
{
	DrawCircle(p.x, p.y, p.r, p.c, p.fill);
}