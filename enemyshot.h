#pragma once
#include"setting.h"
#include<math.h>

const int enemyshotnum = 200;
extern circle ene1shot[enemyshotnum];
extern circle ene2shot[enemyshotnum];
extern circle ene3shot[enemyshotnum];
extern circle ene4shot[enemyshotnum];
extern circle ene5shot[enemyshotnum];
extern circle bossshot[enemyshotnum];

void straightshot1(int rad, circle enemy, int shiftx, int shifty);
void straightshot2(int rad, circle enemy, int shiftx, int shifty);
void straightshot3(int rad, circle enemy, int shiftx, int shifty);
void straightshot4(int rad, circle enemy, int shiftx, int shifty);
void straightshot5(int rad, circle enemy, int shiftx, int shifty);
void straightshotboss(int rad, circle enemy, int shiftx, int shifty);
void aimshot1(circle ene);
void aimshot2(circle ene);
void aimshot3(circle ene);
void aimshot4(circle ene);
void aimshot5(circle ene);
void aimshotboss(circle ene);

bool canenemyshot(circle enemy);

void initenemyshot(void);
void updateenemyshot(void);
void drawenemyshot(void);