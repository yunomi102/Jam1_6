#pragma once
#include"DxLib.h"
#include"circle.h"
#include"player.h"
#include"playershot.h"
#include"enemy.h"
#include"enemyshot.h"
#include"stage.h"
#include"ishit.h"
#include"game.h"
#include"effect.h"

extern bool collision;
extern int playerhp;
extern int playershotdamage1;
extern int playershotdamage2;
extern int pshotcooltime;
extern int invincibletime;
extern int enemy1hp;
extern double enemy1r;
extern double enemynum1x[10];
extern double enemynum1y[10];
extern int enemy2hp;
extern double enemy2r;
extern double enemynum2x[10];
extern double enemynum2y[10];
extern int enemy3hp;
extern double enemy3r;
extern double enemynum3x[10];
extern double enemynum3y[10];
extern int enemy4hp;
extern double enemy4r;
extern double enemynum4x[10];
extern double enemynum4y[10];
extern int enemy5hp;
extern double enemy5r;
extern double enemynum5x[10];
extern double enemynum5y[10];
extern int bosshp;
extern double bossr;
extern double bossx;
extern double bossy;

void initsetting(void);
void updatesetting(void);





