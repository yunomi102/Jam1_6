#include"stage.h"

stagetype STtype;

stage stage1[2];
stage stage2[2];
stage stage3[2];
stage stage4[2];

circle cs[changenum];
bool change;
bool push;
int cscount;
int stagechangeimg;

void initstage(void)
{
	STtype = ST1;
	stage1[0].stageimg = LoadGraph("stage01.png");
	stage1[0].x = 0;
	stage1[0].y = 0;
	stage1[1].stageimg = LoadGraph("stage01Re.png");
	stage1[1].x = 800;
	stage1[1].y = 0;
	stage2[0].stageimg = LoadGraph("stage02.png");
	stage2[0].x = 0;
	stage2[0].y = 0;
	stage2[1].stageimg = LoadGraph("stage02Re.png");
	stage2[1].x = 1200;
	stage2[1].y = 0;
	stage3[0].stageimg = LoadGraph("stage03.png");
	stage3[0].x = 0;
	stage3[0].y = 0;
	stage3[1].stageimg = LoadGraph("stage03Re.png");
	stage3[1].x = 800;
	stage3[1].y = 0;
	stage4[0].stageimg = LoadGraph("stage04.png");
	stage4[0].x = 0;
	stage4[0].y = 0;
	stage4[1].stageimg = LoadGraph("stage04Re.png");
	stage4[1].x = 800;
	stage4[1].y = 0;
	push = false;
	change = false;
	stagechangeimg = LoadGraph("Awa01.png");
}
void updatestage(void)
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
		stage2[0].x -= 1;
		stage2[1].x -= 1;
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
}
void drawstage(void)
{
	if (STtype == ST1)
	{
		DrawExtendGraph(stage1[0].x, stage1[0].y, stage1[0].x + 800, stage1[0].y + 600, stage1[0].stageimg, true);
		DrawExtendGraph(stage1[1].x, stage1[1].y, stage1[1].x + 800, stage1[1].y + 600, stage1[1].stageimg, true);
	}
	else if (STtype == ST2)
	{
		DrawExtendGraph(stage2[0].x, stage2[0].y, stage2[0].x + 1200, stage2[0].y + 600, stage2[0].stageimg, true);
		DrawExtendGraph(stage2[1].x, stage2[1].y, stage2[1].x + 1200, stage2[1].y + 600, stage2[1].stageimg, true);
		if (cscount != 255)
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
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - cscount);
			DrawExtendGraph(stage1[0].x, stage1[0].y, stage1[0].x + 800, stage1[0].y + 600, stage1[0].stageimg, true);
			DrawExtendGraph(stage1[1].x, stage1[1].y, stage1[1].x + 800, stage1[1].y + 600, stage1[1].stageimg, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if (cscount == 255)
		{
			change = false;
		}
	}
	else if (STtype == ST3)
	{
		DrawExtendGraph(stage3[0].x, stage3[0].y, stage3[0].x + 800, stage3[0].y + 600, stage3[0].stageimg, true);
		DrawExtendGraph(stage3[1].x, stage3[1].y, stage3[1].x + 800, stage3[1].y + 600, stage3[1].stageimg, true);
		if (cscount != 255)
		{
			stage2[0].x -= 1;
			stage2[1].x -= 1;
			if (stage2[0].x == -1200)
			{
				stage2[0].x = 1200;
			}
			if (stage2[1].x == -1200)
			{
				stage2[1].x = 1200;
			}
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - cscount);
			DrawExtendGraph(stage2[0].x, stage2[0].y, stage2[0].x + 1200, stage2[0].y + 600, stage2[0].stageimg, true);
			DrawExtendGraph(stage2[1].x, stage2[1].y, stage2[1].x + 1200, stage2[1].y + 600, stage2[1].stageimg, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if (cscount == 255)
		{
			change = false;
		}
	}
	else if (STtype == ST4)
	{
		DrawExtendGraph(stage4[0].x, stage4[0].y, stage4[0].x + 800, stage4[0].y + 600, stage4[0].stageimg, true);
		DrawExtendGraph(stage4[1].x, stage4[1].y, stage4[1].x + 800, stage4[1].y + 600, stage4[1].stageimg, true);
		if (cscount != 255)
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
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - cscount);
			DrawExtendGraph(stage3[0].x, stage3[0].y, stage3[0].x + 800, stage3[0].y + 600, stage3[0].stageimg, true);
			DrawExtendGraph(stage3[1].x, stage3[1].y, stage3[1].x + 800, stage3[1].y + 600, stage3[1].stageimg, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if (cscount == 255)
		{
			change = false;
		}
	}
}
void initchangestage(void)
{
	cscount = 0;
	for (int i = 0; i < changenum; i++)
	{
		cs[i].x = GetRand(1600) + 900;
		cs[i].vx = cs[i].x / (GetRand(100) + 150);
		cs[i].y = GetRand(800) - 100;
		cs[i].r = GetRand(90) + 10;
		cs[i].c = GetColor(25, 25, GetRand(200) + 55);
		cs[i].fill = false;
		cs[i].enable = true;
		change = true;
	}
}
void updatechangestage(void)
{
	if (STtype == ST1 && enemycount1 == 0)
	{
		initchangestage();
		STtype = ST2;
	}
	else if (STtype == ST2 && enemycount2 == 0)
	{
		initchangestage();
		STtype = ST3;
	}
	else if (STtype == ST3 && enemycount3 == 0)
	{
		initchangestage();
		STtype = ST4;
	}
	if (change == true)
	{
		for (int i = 0; i < changenum; i++)
		{
			cs[i].x -= cs[i].vx;
			if (cs[i].x <= -50 && cs[i].enable == true)
			{
				cs[i].enable = false;
				cscount += 1;
			}
		}
	}
}
void drawchangestage(void)
{
	if (change == true)
	{
		for (int i = 0; i < 150; i++)
		{
			if (cs[i].enable == true)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);

				DrawExtendGraph(cs[i].x - cs[i].r, cs[i].y - cs[i].r, cs[i].x + cs[i].r, cs[i].y + cs[i].r, stagechangeimg, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
}