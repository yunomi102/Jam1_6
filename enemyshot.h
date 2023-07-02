#pragma once
#include"setting.h"
#include<math.h>

const int enemyshotnum = 100;
extern circle ene1shot[enemyshotnum];
extern circle ene2shot[enemyshotnum];
extern circle ene3shot[enemyshotnum];
extern circle ene4shot[enemyshotnum];
extern circle ene5shot[enemyshotnum];
extern circle bossshot[enemyshotnum];

void initenemyshot(void);
void updateenemyshot(void);
void drawenemyshot(void);

void straightshot(int rad, circle enemy, circle enemyshot, int shiftx, int shifty);
void aimShot(circle ene, circle enemyshot);