#include"ishit.h"

void updateishit(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		if (ishit(p, ene1[i]) && p.time == 0 && p.enable == true && ene2[i].enable == true)
		{
			p.hp -= 1;
			p.time = invincibletime;
		}
	}
	for (int i = 0; i < enemynum2; i++)
	{
		if (ishit(p, ene2[i]) && p.time == 0 && p.enable == true && ene2[i].enable == true)
		{
			p.hp -= 1;
			p.time = invincibletime;
		}
	}
	for (int i = 0; i < playershotnum; i++)
	{
		for (int j = 0; j < enemynum1; j++)
		{
			if (ishit(pshot1[i], ene1[j]) &&
				pshot1[i].enable == true && ene1[j].enable == true)
			{
				pshot1[i].enable = false;
				ene1[j].hp -= pshot1[i].damage;
				if (ene1[j].hp <= 0)
				{
					ene1[j].enable = false;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene1[j]) &&
				pshot2[i].enable == true && ene1[j].enable == true)
			{
				ene1[j].hp -= pshot2[i].damage;
				if (ene1[j].hp <= 0)
				{
					ene1[j].enable = false;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		for (int j = 0; j < enemynum2; j++)
		{
			if (ishit(pshot1[i], ene2[j]) &&
				pshot1[i].enable == true && ene2[j].enable == true)
			{
				pshot1[i].enable = false;
				ene2[j].hp -= pshot1[i].damage;
				if (ene2[j].hp <= 0)
				{
					ene2[j].enable = false;
				}
			}
			if (ishit(pshot2[i], ene2[j]) &&
				pshot2[i].enable == true && ene2[j].enable == true)
			{
				ene2[j].hp -= pshot2[i].damage;
				if (ene2[j].hp <= 0)
				{
					ene2[j].enable = false;
				}
			}
		}
	}
}
bool ishit(circle c1, circle c2)
{
	double dx = c1.x - c2.x;
	double dy = c1.y - c2.y;
	double r2 = c1.r + c2.r;
	if (dx * dx + dy * dy < r2 * r2)
	{
		return true;
	}
	return false;
}