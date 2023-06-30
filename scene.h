#pragma once
#include"setting.h"

struct scene
{
	int stageimg;
	double x;
	double y;
};

extern scene stage1[2];
const int changenum = 20;

void initscene(void);
void updatescene(void);
void drawscene(void);