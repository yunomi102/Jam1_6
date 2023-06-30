#pragma once
#include"setting.h"
#include<math.h>

const int playershotnum = 100;
extern circle pshot[playershotnum];

void initplayershot(void);
void updateplayershot(void);
void drawplayershot(void);
void shot(int rad);