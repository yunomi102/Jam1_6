#include"stage.h"

stagetype STtype;

stage stage1[2];
stage stage2[2];
stage stage3[2];
stage stage4[2];

int changestage[changenum];
bool change;
double x[changenum];
double y[changenum];

bool push;
void initscene(void)
{
	push = false;
	STtype = ST1;
	stage1[0].stageimg = LoadGraph("stage01.png");
	stage1[0].x = 0;
	stage1[0].y = 0;
	stage1[1].stageimg = LoadGraph("stage01Re.png");
	stage1[1].x = 800;
	stage1[1].y = 0;
	stage2[0].stageimg = LoadGraph("stage02.jpg");
	stage2[0].x = 0;
	stage2[0].y = 0;
	stage2[1].stageimg = LoadGraph("stage02Re.jpg");
	stage2[1].x = 1200;
	stage2[1].y = 0;
	stage3[0].stageimg = LoadGraph("stage03.png");
	stage3[0].x = 0;
	stage3[0].y = 0;
	stage3[1].stageimg = LoadGraph("stage03Re.png");
	stage3[1].x = 800;
	stage3[1].y = 0;
	stage4[0].stageimg = LoadGraph("stage04.jpg");
	stage4[0].x = 0;
	stage4[0].y = 0;
	stage4[1].stageimg = LoadGraph("stage04Re.jpg");
	stage4[1].x = 800;
	stage4[1].y = 0;

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
	if (STtype == ST1)
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
	}
	else if (STtype == ST2)
	{
		stage2[0].x -= 2;
		stage2[1].x -= 2;
		if (stage2[0].x == -1200)
		{
			stage2[0].x = 1200;
		}
		if (stage2[1].x == -1200)
		{
			stage2[1].x = 1200;
		}
	}
	else if (STtype == ST3)
	{
		stage3[0].x -= 1;
		stage3[1].x -= 1;
		if (stage3[0].x == -800)
		{
			stage3[0].x = 800;
		}
		if (stage3[1].x == -800)
		{
			stage3[1].x = 800;
		}
	}
	else if (STtype == ST4)
	{
		stage4[0].x -= 1;
		stage4[1].x -= 1;
		if (stage4[0].x == -800)
		{
			stage4[0].x = 800;
		}
		if (stage4[1].x == -800)
		{
			stage4[1].x = 800;
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		change = true;
		if (STtype == ST1&& push==false)
		{
			STtype = ST2;
			push = true;
		}
		else if (STtype == ST2 && push == false)
		{
			STtype = ST3;
			push = true;
		}
		else if (STtype == ST3 && push == false)
		{
			STtype = ST4;
			push = true;
		}
	}
	else
	{
		push = false;
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
	if(STtype == ST1)
	{
		DrawExtendGraph(stage1[0].x, stage1[0].y, stage1[0].x + 800, stage1[0].y + 600, stage1[0].stageimg, true);
		DrawExtendGraph(stage1[1].x, stage1[1].y, stage1[1].x + 800, stage1[1].y + 600, stage1[1].stageimg, true);
	}
	else if (STtype == ST2)
	{
		DrawExtendGraph(stage2[0].x, stage2[0].y, stage2[0].x + 1200, stage2[0].y + 600, stage2[0].stageimg, true);
		DrawExtendGraph(stage2[1].x, stage2[1].y, stage2[1].x + 1200, stage2[1].y + 600, stage2[1].stageimg, true);
	}
	else if (STtype == ST3)
	{
		DrawExtendGraph(stage3[0].x, stage3[0].y, stage3[0].x + 800, stage3[0].y + 600, stage3[0].stageimg, true);
		DrawExtendGraph(stage3[1].x, stage3[1].y, stage3[1].x + 800, stage3[1].y + 600, stage3[1].stageimg, true);
	}
	else if (STtype == ST4)
	{
		DrawExtendGraph(stage4[0].x, stage4[0].y, stage4[0].x + 800, stage4[0].y + 600, stage4[0].stageimg, true);
		DrawExtendGraph(stage4[1].x, stage4[1].y, stage4[1].x + 800, stage4[1].y + 600, stage4[1].stageimg, true);
	}
	if (change == true)
	{
		for (int i = 0; i < changenum; i++)
			DrawGraph(x[i], y[i], changestage[i], true);
	}
}