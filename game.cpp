#include"game.h"

int white;

void initgame(void)
{
	white = GetColor(255, 255, 255);
}
void updategame(void)
{

}
void drawgame(void)
{
	DrawFormatString(700, 200, white, "‘Ì—Í%d", p.hp);
}