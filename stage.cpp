#include"stage.h"

stagetype STtype;

stage stage1[2];
stage stage2[2];
stage stage3[2];
stage stage4[2];


//int changestage[changenum];
//double x[changenum];
//double y[changenum];

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
	}
}
void initchangestage(void)
{
	cscount = 0;
	for (int i = 0; i < changenum; i++)
	{
		cs[i].x = GetRand(1600) + 850;
		cs[i].y = GetRand(800) - 100;
		cs[i].r = GetRand(70) + 10;
		cs[i].c = GetColor(25, 25, GetRand(200) + 55);
		cs[i].fill = false;
		cs[i].enable = true;
	}
	/*
		for (int i = 0; i < changenum; i++)
	{
		changestage[i] = LoadGraph("awa03.png");
		x[i] = GetRand(700) + 850;
		y[i] = GetRand(500) - 150;
	}
	*/
}
void updatechangestage(void)
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		initchangestage();
		change = true;

		if (STtype == ST1 && push == false)
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
	if (change == true)
	{
		for (int i = 0; i < changenum; i++)
		{
			if (cs[i].x > -50)
			{
				cs[i].x -= 6;
				if (cs[i].x < 750)
				{
					cs[i].x += 0.5;
				}
				if (cs[i].x < 700)
				{
					cs[i].x += 0.5;
				}
				if (cs[i].x < 650)
				{
					cs[i].x += 0.5;
				}
				if (cs[i].x < 400)
				{
					cs[i].x += 0.5;
				}
			}
			if (cs[i].x <= -50 && cs[i].enable == true)
			{
				cs[i].enable = false;
				cscount += 1;
			}
		}
	}
	/*
		if (change == true)
	{
		for (int i = 0; i < changenum; i++)
		{
			x[i] -= 5;
			y[i] += 0;
		}
	}
	*/
}
void drawchangestage(void)
{
	if (change == true)
	{
		for (int i = 0; i < changenum; i++)
		{
			if (cs[i].enable == true)
			{
				SetDrawBlendMode(DX_BLENDMODE_ADD, 125);

				DrawExtendGraph(cs[i].x - cs[i].r, cs[i].y - cs[i].r, cs[i].x + cs[i].r, cs[i].y + cs[i].r, stagechangeimg, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
	DrawFormatString(p.x - 50, p.y + 100, GetColor(255, 255, 0), "ƒJƒEƒ“ƒg%d", cscount);
	/*
		if (change == true)
	{
		for (int i = 0; i < changenum; i++)
		{
			DrawGraph(x[i], y[i], changestage[i], true);
		}
	}
	*/
}