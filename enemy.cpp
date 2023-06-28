#include"enemy.h"

circle e;

void initenemy(void)
{
	e.x = 600;
	e.y = 300;
	e.r = 5;
	e.c = GetColor(255, 0, 0);
	e.fill = true;
}
void updateenemy(void)
{

}
void drawenemy(void)
{
	DrawCircle(e.x, e.y, e.r, e.c, e.fill);
}