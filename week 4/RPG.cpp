
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>

using namespace std;

class Weapon
{
	int damage;
	float criticalStrike;

public:
	Weapon();
	Weapon(int Damage);
	int WeaponDamage();
};


Weapon::Weapon()
{
	damage = 0;
	criticalStrike = 0;
}

Weapon::Weapon(int Damage)
{
	Damage = damage;
	criticalStrike = 2 * Damage;
}

int Weapon::WeaponDamage()
{
	if (criticalStrike = (rand() % 101) / 100 <= 0.2)
	{
		return damage;
	}
	else
	{
		return criticalStrike;
	}
}

class Player
{
	char name[30];
	int health;
	Weapon weapon;
	int level;

public:
	Player();
	Player(char*Name, int Health, Weapon weap, int Level);

	int getHealth() const;
	void setHealth(int health);
	Weapon getWeapon() const;
	void setWeapon(Weapon weapon);
	int getLevel()const;
	void setLevel(int level);

	void LevelUp();
	void Attack(Player Rival);
	bool Alive(Player p);
};

Player::Player()
{
	strcpy(name, "");
	health = 100;
	level = 0;
}

Player::Player(char*Name, int Health, Weapon weap, int Level)
{
	strcpy(Name, name);
	Health = health;
	weapon = weap;
	level = Level;
}

int Player::getHealth() const
{
	return health;
}

void Player::setHealth(int Health)
{
	health = Health;
}

Weapon Player::getWeapon()const
{
	return weapon;
}

void Player::setWeapon(Weapon weap)
{
	weapon = weap;
}

int Player::getLevel()const
{
	return level;
}

void Player::setLevel(int Level)
{
	level = Level;
}

void Player::LevelUp()
{
	level++;
	health += 2 * level;
}

void Player::Attack(Player Rival)
{
	Rival.getHealth = Rival.setHealth(Rival.getHealth() - weapon.WeaponDamage());

	if (Rival.getHealth < 0)
	{
		setLevel(getLevel() + 1);
	}
}

bool Player::Alive(Player p)
{
	if (p.getHealth() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Battleground
{
	Player **factionOne;
	int  playersInFactionOne;
	Player **factionTwo;
	int playersInFactionTwo;

public:
	Battleground(Player **FactionOne, Player **FactionTwo);

	void Fight(Player **FactionOne, Player **FactionTwo);
	void Reward(Player **FactionOne);
	void Reward(Player **FactionTwo);
	bool Alive(Player p);

	

};

Battleground::Battleground(Player **FactionOne, Player **FactionTwo)
{
	int index = 0;
	int temp, temp1;
	while (FactionOne[index] != NULL || FactionTwo[index] != NULL)
	{
		factionOne[index] = FactionOne[index];
		factionTwo[index] = FactionTwo[index];

		index++;
		temp = index;
		temp1 = index;
	}

	while (FactionOne[temp] != NULL)
	{
		factionOne[temp] = FactionOne[temp];
	}

	while (FactionOne[temp1] != NULL)
	{
		factionOne[temp1] = FactionOne[temp1];
	}
}

bool Player::Alive(Player p)
{
	if (p.getHealth() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Battleground::Fight(Player **FactionOne,Player **FactionTwo)
{
	int index1 = 0;
	int index2 = 0;
	Player temp;
	bool check = true;
	while (check)
	{
		FactionOne[index1]->Attack(*FactionTwo[index1]);

		if (!Alive(*FactionTwo[index1]))
		{
			while (FactionTwo != NULL)
			{
				*FactionTwo[index1] = *FactionTwo[index1 + 1];
			}
			index1--;
		}

		FactionTwo[index2]->Attack(*FactionOne[index2]);

		if (!Alive(*FactionOne[index2]))
		{
			while (FactionOne != NULL)
			{
				*FactionTwo[index2] = *FactionTwo[index2 + 1];
			}

			index2--;
		}

		//Недовършено
		bool flag = true;
		int p = 0;
		while (flag)
		{
			if (Alive(*FactionOne[p]))
			{
				cout << "Faction two wins!" << endl;
				Reward(FactionTwo);
				check = false;
			}

			if (Alive(*FactionOne[p]))
			{
				cout << "Faction one wins!" << endl;
				Reward(FactionOne);
				check = false;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

