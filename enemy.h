#pragma once
#include"DxLib.h"
#include"circle.h"

const int enemynum1 = 1;
const int enemynum2 = 1;
extern circle ene1[enemynum1];
extern circle ene2[enemynum2];

void initenemy(void);
void updateenemy(void);
void drawenemy(void);