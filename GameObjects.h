//GameObjects.h

#ifndef OBJECTS_INCLUDED
#define OBJECTS_INCLUDED

#include "utilities.h"
#include <string>
#include <iostream>
using namespace std;

class GameObject
{
public:
	GameObject(){};
	virtual ~GameObject(){};
	string getName(){ return m_name; };
	string getWielder(){ return wielder; };
	virtual void text(){};
protected:
	int index;
	string m_name;
	string wielder;
};

class Weapon : public GameObject
{
public:
	Weapon();
	~Weapon(){};
	int getDmgAmount();
	int dexBonus();
	void setWeapon(int randName);
	//Sets the weapon type for the new Weapon object
	void setWielder(string wielderName);
	virtual void text();
protected:
	string weaponTypes[5];
	string enemy;
	int damageAmount;
	int dexterityBonus = 0;
};

class Scroll : public GameObject
{
public:
	Scroll();
	~Scroll(){};
	void setScrollType(int name);
	virtual void text(int type);
protected:
	string scrollTypes[5];

};

#endif // OBJECTS_INCLUDED