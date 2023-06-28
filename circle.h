#pragma once
#include"DxLib.h"

struct circle
{
	double x;
	double y;
	double s;
	int r;
	int c;
	bool fill;
	bool enable;
	int hp;//自機の残機と敵の体力
	int damage;//敵の体力を実装する場合の自機の玉のダメージ
	int time;//無敵時間などで使用
};

bool ishit(circle c1, circle c2);