#include"setting.h"

bool collision;
int playerhp;
int playershotdamage1;
int playershotdamage2;
int pshotcooltime;
int invincibletime;
int enemy1hp;
double enemy1r;
double enemynum1x[enemynum1];
double enemynum1y[enemynum1];
int enemy2hp;
double enemy2r;
double enemynum2x[enemynum2];
double enemynum2y[enemynum2];
int enemy3hp;
double enemy3r;
double enemynum3x[enemynum3];
double enemynum3y[enemynum3];
int enemy4hp;
double enemy4r;
double enemynum4x[enemynum4];
double enemynum4y[enemynum4];
int enemy5hp;
double enemy5r;
double enemynum5x[enemynum5];
double enemynum5y[enemynum5];
int bosshp;
double bossr;
double bossx;
double bossy;

int hpuptime;
void initsetting(void)
{
	collision = false;	   //“–‚½‚è”»’è
	playerhp = 3;          //ƒvƒŒƒCƒ„[‚ÌHP
	playershotdamage1 = 20;//ƒvƒŒƒCƒ„[ƒVƒ‡ƒbƒg1‚Ìƒ_ƒ[ƒW
	playershotdamage2 = 1; //ƒvƒŒƒCƒ„[ƒVƒ‡ƒbƒg2‚Ìƒ_ƒ[ƒW
	pshotcooltime = 100;   //ƒvƒŒ[ƒ„[ƒVƒ‡ƒbƒg‚ÌƒN[ƒ‹ƒ^ƒCƒ€
	invincibletime = 300;  //ƒvƒŒƒCƒ„[‚Ì–³“GŽžŠÔ
	enemy1hp = 60;         //“G1‚ÌHP
	enemy2hp = 60;         //“G2‚ÌHP
	enemy3hp = 60;         //“G3‚ÌHP
	enemy4hp = 60;         //“G4‚ÌHP
	enemy5hp = 60;         //“G5‚ÌHP
	bosshp = 100;          //ƒ{ƒX‚ÌHP
	enemy1r = 25;          //“G1‚Ì”¼Œa
	enemy2r = 35;          //“G2‚Ì”¼Œa
	enemy3r = 45;          //“G3‚Ì”¼Œa
	enemy4r = 55;          //“G4‚Ì”¼Œa
	enemy5r = 65;          //“G5‚Ì”¼Œa
	bossr = 100;           //ƒ{ƒX‚Ì”¼Œa
	//“G1‚ÌÀ•W
	enemynum1x[0] = 900;
	enemynum1y[0] = 300;
	enemynum1x[1] = 1000;
	enemynum1y[1] = 300;
	enemynum1x[2] = 1100;
	enemynum1y[2] = 300;
	enemynum1x[3] = 1200;
	enemynum1y[3] = 300;
	enemynum1x[4] = 1300;
	enemynum1y[4] = 300;
	enemynum1x[5] = 1400;
	enemynum1y[5] = 300;
	enemynum1x[6] = 1500;
	enemynum1y[6] = 300;
	enemynum1x[7] = 1600;
	enemynum1y[7] = 300;
	enemynum1x[8] = 1700;
	enemynum1y[8] = 300;
	enemynum1x[9] = 1800;
	enemynum1y[9] = 300;
	//“G2‚ÌÀ•W
	enemynum2x[0] = 900;
	enemynum2y[0] = 300;
	enemynum2x[1] = 1000;
	enemynum2y[1] = 300;
	enemynum2x[2] = 1100;
	enemynum2y[2] = 300;
	enemynum2x[3] = 1200;
	enemynum2y[3] = 300;
	enemynum2x[4] = 1300;
	enemynum2y[4] = 300;
	enemynum2x[5] = 1400;
	enemynum2y[5] = 300;
	enemynum2x[6] = 1500;
	enemynum2y[6] = 300;
	enemynum2x[7] = 1600;
	enemynum2y[7] = 300;
	enemynum2x[8] = 1700;
	enemynum2y[8] = 300;
	enemynum2x[9] = 1800;
	enemynum2y[9] = 300;
	//“G3‚ÌÀ•W
	enemynum3x[0] = 900;
	enemynum3y[0] = 300;
	enemynum3x[1] = 1000;
	enemynum3y[1] = 300;
	enemynum3x[2] = 1100;
	enemynum3y[2] = 300;
	enemynum3x[3] = 1200;
	enemynum3y[3] = 300;
	enemynum3x[4] = 1300;
	enemynum3y[4] = 300;
	enemynum3x[5] = 1400;
	enemynum3y[5] = 300;
	enemynum3x[6] = 1500;
	enemynum3y[6] = 300;
	enemynum3x[7] = 1600;
	enemynum3y[7] = 300;
	enemynum3x[8] = 1700;
	enemynum3y[8] = 300;
	enemynum3x[9] = 1800;
	enemynum3y[9] = 300;
	//“G4‚ÌÀ•W
	enemynum4x[0] = 900;
	enemynum4y[0] = 300;
	enemynum4x[1] = 1000;
	enemynum4y[1] = 300;
	enemynum4x[2] = 1100;
	enemynum4y[2] = 300;
	enemynum4x[3] = 1200;
	enemynum4y[3] = 300;
	enemynum4x[4] = 1300;
	enemynum4y[4] = 300;
	enemynum4x[5] = 1400;
	enemynum4y[5] = 300;
	enemynum4x[6] = 1500;
	enemynum4y[6] = 300;
	enemynum4x[7] = 1600;
	enemynum4y[7] = 300;
	enemynum4x[8] = 1700;
	enemynum4y[8] = 300;
	enemynum4x[9] = 1800;
	enemynum4y[9] = 300;
	//“G5‚ÌÀ•W
	enemynum5x[0] = 900;
	enemynum5y[0] = 300;
	enemynum5x[1] = 1000;
	enemynum5y[1] = 300;
	enemynum5x[2] = 1100;
	enemynum5y[2] = 300;
	enemynum5x[3] = 1200;
	enemynum5y[3] = 300;
	enemynum5x[4] = 1300;
	enemynum5y[4] = 300;
	enemynum5x[5] = 1400;
	enemynum5y[5] = 300;
	enemynum5x[6] = 1500;
	enemynum5y[6] = 300;
	enemynum5x[7] = 1600;
	enemynum5y[7] = 300;
	enemynum5x[8] = 1700;
	enemynum5y[8] = 300;
	enemynum5x[9] = 1800;
	enemynum5y[9] = 300;
	//ƒ{ƒX‚ÌÀ•W
	bossx = 1000;
	bossy = 300;
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