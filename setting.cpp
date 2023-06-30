#include"setting.h"

bool collision;
int playerhp;
int playershotdamage1;
int playershotdamage2;
int pshotcooltime;
int invincibletime;
int enemy1hp;
int enemy2hp;
int hpuptime;

void initsetting(void)
{
	//当たり判定
	collision = false;

	playerhp = 2;          //プレイヤーのHP
	playershotdamage1 = 20;//プレイヤーショット1のダメージ
	playershotdamage2 = 1; //プレイヤーショット2のダメージ
	pshotcooltime = 100;   //プレーヤーショットのクールタイム
	invincibletime = 300;  //プレイヤーの無敵時間
	enemy1hp = 60;         //敵1のHP
	enemy2hp = 60;         //敵2のHP
}
void updatesetting(void)
{
	if (CheckHitKey(KEY_INPUT_J) == 1)
	{
		collision = true;
	}
	if (CheckHitKey(KEY_INPUT_K) == 1)
	{
		collision = false;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		hpuptime++;
		if (hpuptime == 50)
		{
			p.hp += 1;
			hpuptime = 0;
		}
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		hpuptime--;
		if (hpuptime == -50)
		{
			p.hp -= 1;
			hpuptime = 0;
		}
	}
	else
	{
		hpuptime = 0;
	}
	if (p.hp > 0)
	{
		p.enable = true;
		gameoverflag = false;
	}
}