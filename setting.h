#pragma once
#include"DxLib.h"
#include"circle.h"
#include"player.h"
#include"playershot.h"
#include"enemy.h"
#include"scene.h"
#include"ishit.h"
#include"game.h"

extern bool collision;
extern int playerhp;
extern int playershotdamage;
extern int pshotcooltime;
extern int invincibletime;
extern int enemy1hp;
extern int enemy2hp;

void initsetting(void);