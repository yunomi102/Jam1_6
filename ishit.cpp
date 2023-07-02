#include"ishit.h"

void updateishit(void)
{
	for (int i = 0; i < enemynum1; i++)
	{
		if (ishit(p, ene1[i]) && p.time == 0 && p.enable == true && ene1[i].enable == true)
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
	for (int i = 0; i < enemynum3; i++)
	{
		if (ishit(p, ene3[i]) && p.time == 0 && p.enable == true && ene3[i].enable == true)
		{
			p.hp -= 1;
			p.time = invincibletime;
		}
	}
	for (int i = 0; i < enemynum4; i++)
	{
		if (ishit(p, ene4[i]) && p.time == 0 && p.enable == true && ene4[i].enable == true)
		{
			p.hp -= 1;
			p.time = invincibletime;
		}
	}
	for (int i = 0; i < enemynum5; i++)
	{
		if (ishit(p, ene5[i]) && p.time == 0 && p.enable == true && ene5[i].enable == true)
		{
			p.hp -= 1;
			p.time = invincibletime;
		}
	}
	if (ishit(p, boss) && p.time == 0 && p.enable == true && boss.enable == true)
	{
		p.hp -= 1;
		p.time = invincibletime;
	}
	for (int i = 0; i < playershotnum; i++)
	{
		for (int j = 0; j < enemynum1; j++)
		{
			if (ishit(pshot1[i], ene1[j]) && pshot1[i].enable == true && ene1[j].enable == true)
			{
				pshot1[i].enable = false;
				ene1[j].hp -= pshot1[i].damage;
				if (ene1[j].hp <= 0)
				{
					ene1[j].enable = false;
					enemycount1 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene1[j]) && pshot2[i].enable == true && ene1[j].enable == true)
			{
				ene1[j].hp -= pshot2[i].damage;
				if (ene1[j].hp <= 0)
				{
					ene1[j].enable = false;
					enemycount1 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		for (int j = 0; j < enemynum2; j++)
		{
			if (ishit(pshot1[i], ene2[j]) && pshot1[i].enable == true && ene2[j].enable == true)
			{
				pshot1[i].enable = false;
				ene2[j].hp -= pshot1[i].damage;
				if (ene2[j].hp <= 0)
				{
					ene2[j].enable = false;
					enemycount2 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene2[j]) && pshot2[i].enable == true && ene2[j].enable == true)
			{
				ene2[j].hp -= pshot2[i].damage;
				if (ene2[j].hp <= 0)
				{
					ene2[j].enable = false;
					enemycount2 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		for (int j = 0; j < enemynum3; j++)
		{
			if (ishit(pshot1[i], ene3[j]) && pshot1[i].enable == true && ene3[j].enable == true)
			{
				pshot1[i].enable = false;
				ene3[j].hp -= pshot1[i].damage;
				if (ene3[j].hp <= 0)
				{
					ene3[j].enable = false;
					enemycount3 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene3[j]) && pshot2[i].enable == true && ene3[j].enable == true)
			{
				ene3[j].hp -= pshot2[i].damage;
				if (ene3[j].hp <= 0)
				{
					ene3[j].enable = false;
					enemycount3 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		for (int j = 0; j < enemynum4; j++)
		{
			if (ishit(pshot1[i], ene4[j]) && pshot1[i].enable == true && ene4[j].enable == true)
			{
				pshot1[i].enable = false;
				ene4[j].hp -= pshot1[i].damage;
				if (ene4[j].hp <= 0)
				{
					ene4[j].enable = false;
					enemycount4 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene4[j]) && pshot2[i].enable == true && ene4[j].enable == true)
			{
				ene4[j].hp -= pshot2[i].damage;
				if (ene4[j].hp <= 0)
				{
					ene4[j].enable = false;
					enemycount4 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		for (int j = 0; j < enemynum5; j++)
		{
			if (ishit(pshot1[i], ene5[j]) && pshot1[i].enable == true && ene5[j].enable == true)
			{
				pshot1[i].enable = false;
				ene5[j].hp -= pshot1[i].damage;
				if (ene5[j].hp <= 0)
				{
					ene5[j].enable = false;
					enemycount5 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
			if (ishit(pshot2[i], ene5[j]) && pshot2[i].enable == true && ene5[j].enable == true)
			{
				ene5[j].hp -= pshot2[i].damage;
				if (ene5[j].hp <= 0)
				{
					ene5[j].enable = false;
					enemycount5 -= 1;
					PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
				}
			}
		}
		if (ishit(pshot1[i], boss) && pshot1[i].enable == true && boss.enable == true)
		{
			pshot1[i].enable = false;
			boss.hp -= pshot1[i].damage;
			if (boss.hp <= 0)
			{
				boss.enable = false;
				PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
			}
		}
		if (ishit(pshot2[i], boss) && pshot2[i].enable == true && boss.enable == true)
		{
			boss.hp -= pshot2[i].damage;
			if (boss.hp <= 0)
			{
				boss.enable = false;
				PlaySoundMem(enemydownse, DX_PLAYTYPE_BACK);
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