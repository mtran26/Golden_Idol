
//GameObjects.cpp

#include "GameObjects.h"
#include <string>
#include <iostream>
using namespace std;

Weapon::Weapon()
{
	weaponTypes[0] = "mace";
	weaponTypes[1] = "short sword";
	weaponTypes[2] = "long sword";
	weaponTypes[3] = "magic fangs of sleep";
	weaponTypes[4] = "magic axe";
	
	index = randInt(4);
	setWeapon(index);
}	

int Weapon::dexBonus()
{
	return dexterityBonus;
}

void Weapon::setWielder(string wielderName)
{
	wielder = wielderName;
}

int Weapon::getDmgAmount()
{
	return damageAmount;
}


void Weapon::setWeapon(int randName)
{ 
	m_name = weaponTypes[randName]; 
	index = randName;

	switch (index)
	{
	case 0:
		damageAmount = 2;
		dexterityBonus = 0;
		break;
	case 1:
		damageAmount = 2;
		dexterityBonus = 0;
		break;
	case 2:
		damageAmount = 4;
		dexterityBonus = 2;
		break;
	case 3:
		damageAmount = 2;
		dexterityBonus = 3;
		break;
	case 4:
		damageAmount = 5;
		dexterityBonus = 5;
		break;
	}
}

void Weapon::text()
{ 
	
	cout << wielder;

	switch (index)
	{
	case 0:
		cout << " swings mace at ";
		break;
	case 1:
		cout << " slashes short sword at ";
		break;
	case 2:
		cout << " swings long sword at ";
		break;
	case 3:
		cout << " strikes magic fangs at ";
		break;
	case 4:
		cout << " chops magic axe at ";
		break;
	}

	//cout << enemy << endl;
}

Scroll::Scroll()
{
	scrollTypes[0] = "scroll of teleportation";
	scrollTypes[1] = "scroll of enhance armor";
	scrollTypes[2] = "scroll of strength";
	scrollTypes[3] = "scroll of enhance health";
	scrollTypes[4] = "scroll of enhance dexterity";

	index = randInt(4) + 1;
	m_name = scrollTypes[index];
}

void Scroll::setScrollType(int name)
{
	m_name = scrollTypes[name];
}

void Scroll::text(int type)
{
	wielder = "Player";

	switch (index)
	{
	case 0:
		cout << "You feel your body wrenched in space and time.\n";
		break;
	case 1:
		cout << "Your armor glows blue.\n";
		break;
	case 2:
		cout << "Your muscles bulge.\n";
		break;
	case 3:
		cout << "You feel your heart beating stronger.\n";
		break;
	case 4:
		cout << "You feel like less of a klutz.\n";
		break;
	}
}