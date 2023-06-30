#pragma once
#include"setting.h"

const int enemynum = 10;
const int enemynum1 = enemynum;
const int enemynum2 = enemynum;
const int enemynum3 = enemynum;
const int enemynum4 = enemynum;
const int enemynum5 = enemynum;
extern circle ene1[enemynum1];
extern circle ene2[enemynum2];
extern circle ene3[enemynum3];
extern circle ene4[enemynum4];
extern circle ene5[enemynum5];

extern int enemycount1;
extern int enemycount2;
extern int enemycount3;
extern int enemycount4;
extern int enemycount5;

extern int enemydownse;

void initenemy(void);
void updateenemy(void);
void drawenemy(void);