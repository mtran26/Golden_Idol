//Actors.cpp

#include "Actors.h"
using namespace std;

int Actor::getHP()
{
	return hp;
}

int Actor::getDP()
{
	return dp;
}

int Actor::decreaseHP(Actor& enemy)  
//if it is a certain weapon, hp will decrease a set amount, can be negative
//Decreases the hp of the enemy.
{
	damagePoints = sp + wielding.getDmgAmount();
	enemy.hp -= randInt(damagePoints);
	//cout << enemy.m_name << " HP now = " << enemy.hp << endl;

	return enemy.hp;
};

void Actor::attack(Actor& enemy)
{
	wielding.text();
	cout << "the " << enemy.wielding.getWielder();

	int atkrPts = enemy.getDP();
	int defendPts = getDP();

	if (randInt(atkrPts) >= randInt(defendPts))
	{
		decreaseHP(enemy);

		if (enemy.hp < 0)
		{
			cout << " dealing a final blow.\n";

			if (enemy.m_name == "Player")
			{
				cout << "Game Over!\n";
				cout << "Press q to exit game.\n";
				return;
			}

			return;
		}

		cout << " and hits.\n";
	}
	else
		cout << " and misses.\n";
}

void Actor::setAP(int n)
{ ap = n; };

void Actor::setSP(int n)
{ sp = n; };

void Actor::setDP(int n)
{ dp = n; }

Coord Actor::getPosition()
{ return m_pos; }

void Actor::setPosition(int& r, int& c)
{
	if ((r < 1) || (c > 15) || (c < 1) || (r > 58))
		return;
	m_pos.m_c = c; m_pos.m_r = r;
}

Player::Player()
{
	m_name = "Player"; hp = 20, ap = 2, sp = 2, dp = 2; wielding.setWielder(m_name); wielding.setWeapon(1);
}

void Player::changeHP(int n)
{
	if (hp = 50)
		return;
	else if (hp > 50)
		hp = 50;
	else{
		hp += n;
		changeHP(hp);
	}
}

void Player::displayStats()
{
	cout << ", Hit points: " << hp << ", Armor: " << ap << ", Strength: " << sp << ", Dexterity: " << dp << endl;
	cout << "\nPress q to exit game." << endl;
}

void Player::changeWeapon(string& weaponName)
//Changes the weapon and the dexterity of the player dependent on the bonus. 
{
	int prevDex = wielding.dexBonus();
	int dex = dp - prevDex;

	cout << "Weapon name = " << weaponName << endl;
	if (weaponName == "mace")
		wielding.setWeapon(0);
	else if (weaponName == "short sword")
		wielding.setWeapon(1);
	else if (weaponName == "long sword")
		wielding.setWeapon(2);
	else if (weaponName == "magic fangs of sleep")
		wielding.setWeapon(3);
	else if (weaponName == "magic axe")
		wielding.setWeapon(4);
	else{}

	dex += wielding.dexBonus();
	setDP(dex);
}

string Player::readScroll(string& scrollType)
//When a player chooses a scroll from the inventory, the specific line prints and its effect is applied.
{ 
	if (scrollType == "scroll of teleportation")
		return "You feel your body wrenched in space and time.\n";

	if (scrollType == "scroll of enhance armor")
	{
		ap += randInt(2) + 1;
		return "Your armor glows blue.\n";
	}
	if (scrollType == "scroll of strength")
	{
		sp += randInt(2) + 1;
		return "Your muscles bulge.\n";
	}
	if (scrollType == "scroll of enhance health")
	{
		//MAX HP += randInt(5) + 3;
		return "You feel your heart beating stronger.\n";
	}
	if (scrollType == "scroll of enhance dexterity")
	{
		dp += 1;
		return "You feel like less of a klutz.\n";
	}
}

Bogeyman::Bogeyman()
//HP = 5-10, AP = 2, SP = DP = 2-3, Weapon = short sword
{
	m_name = "Bogeyman"; hp = randInt(6) + 5, ap = 2, sp = randInt(2) + 2,
		dp = randInt(2) + 2 + wielding.dexBonus(); wielding.setWielder(m_name); wielding.setWeapon(0);
}

Snakewoman::Snakewoman()
{
	m_name = "Snakewoman"; hp = randInt(4) + 3, ap = 3, sp = 2, dp = 3 + wielding.dexBonus();
	wielding.setWielder(m_name); wielding.setWeapon(3);
}

Dragon::Dragon()
{
	m_name = "Dragon";  hp = randInt(6) + 20, ap = 4, sp = 4, dp = 4 + wielding.dexBonus();
	wielding.setWielder(m_name); wielding.setWeapon(2);
}

Goblin::Goblin()
{
	m_name = "Goblin"; hp = randInt(6) + 15, ap = 1, sp = 3, dp = 1 + wielding.dexBonus();
	wielding.setWielder(m_name); wielding.setWeapon(1);
}
