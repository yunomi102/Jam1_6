#pragma once
#include"setting.h"
#include<math.h>

const int playershotnum = 100;
extern circle pshot1[playershotnum];
extern circle pshot2[playershotnum];

void initplayershot(void);
void updateplayershot(void);
void drawplayershot(void);
void shot1(int rad);
void shot2(int rad);