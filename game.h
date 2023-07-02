#pragma once
#include"setting.h"

extern bool gameclearflag;
extern bool gameoverflag;
extern int score;

void initgame(void);
void updategame(void);
void drawgame(void);