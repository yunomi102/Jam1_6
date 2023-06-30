#include"scene.h"

scene stage1[2];
int changestage[changenum];
bool change;
double x[changenum];
double y[changenum];

void initscene(void)
{
	stage1[0].stageimg = LoadGraph("stage1.png");
	stage1[0].x = 0;
	stage1[0].y = 0;
	stage1[1].stageimg = LoadGraph("stage1Re.png");
	stage1[1].x = 800;
	stage1[1].y = 0;
	for (int i = 0; i < changenum; i++)
	{
		changestage[i] = LoadGraph("awa03.png");
		x[i] = GetRand(700)+850;
		y[i] = GetRand(500) - 150;
	}
	change = false;
}
void updatescene(void)
{
	stage1[0].x -= 1;
	stage1[1].x -= 1;
	if (stage1[0].x == -800)
	{
		stage1[0].x = 800;
	}
	if (stage1[1].x == -800)
	{
		stage1[1].x = 800;
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		change = true;
	}
	if(change==true)
	{
		for (int i = 0; i < changenum; i++)
		{
			x[i] -= 5;
			y[i] += 0;
		}
	}
}
void drawscene(void)
{
	DrawExtendGraph(stage1[0].x, stage1[0].y, stage1[0].x + 800, stage1[0].y + 600, stage1[0].stageimg, true);
	DrawExtendGraph(stage1[1].x, stage1[1].y, stage1[1].x + 800, stage1[1].y + 600, stage1[1].stageimg, true);
	if (change == true)
	{
		for (int i = 0; i < changenum; i++)
			DrawGraph(x[i], y[i], changestage[i], true);
	}
}