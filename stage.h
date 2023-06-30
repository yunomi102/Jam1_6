#pragma once
#include"setting.h"

struct stage
{
	int stageimg;
	double x;
	double y;
};

enum stagetype
{
	ST1,
	ST2,
	ST3,
	ST4
};

extern stage stage1[2];
extern stage stage2[2];
extern stage stage3[2];
extern stage stage4[2];
const int changenum = 20;

void initscene(void);
void updatescene(void);
void drawscene(void);