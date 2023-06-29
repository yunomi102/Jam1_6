#pragma once
#include"DxLib.h"
#include"circle.h"

const int enemynum = 1;
extern circle ene1[enemynum];

void initenemy(void);
void updateenemy(void);
void drawenemy(void);