#pragma once
#include"setting.h"

const int enemynum = 1;
const int enemynum1 = enemynum;
const int enemynum2 = enemynum;
extern circle ene1[enemynum1];
extern circle ene2[enemynum2];

extern int enemydownse;

void initenemy(void);
void updateenemy(void);
void drawenemy(void);