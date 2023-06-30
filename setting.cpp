#include"setting.h"

bool collision;
int playerhp;
int playershotdamage;
int pshotcooltime;
int invincibletime;
int enemy1hp;
int enemy2hp;

void initsetting(void)
{
	collision = false;    //当たり判定
	playerhp = 2;         //プレイヤーのHP
	playershotdamage = 10;//プレイヤーショットのダメージ
	pshotcooltime = 100;  //プレーヤーショットのクールタイム
	invincibletime = 300; //プレイヤーの無敵時間
	enemy1hp = 30;        //敵1のHP
	enemy2hp = 30;        //敵2のHP
}