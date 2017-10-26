//Actors.h

#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "utilities.h"
#include "GameObjects.h"

const int MAX_PHP = 50;

struct Coord
{
	int m_r = randInt(58) + 1;
	int m_c = randInt(14) + 1;
};

class Actor	 //Base, base class
{
public:
	Actor(){};
	virtual ~Actor(){};
	void attack(Actor& enemy);
	int decreaseHP(Actor& enemy); //Decreases HP and returns lowered HP amount of Actor
	void setAP(int n);
	void setSP(int n);
	void setDP(int n);
	void deadActor(string name);
	int getHP();
	int getDP();
	Coord getPosition();
	void setPosition(int& r, int& c);
protected:
	Coord m_pos; //Current position in level
	int hp; //Hit points
	int ap; //Armor points
	int sp; //Strength points
	int dp; //Dexterity points
	int sleep = 0; //Sleep time
	int item = randInt(5);
	string m_name;
	Weapon wielding;
	Scroll chosenScroll;
	int damagePoints = -1;
};

class Player : public Actor
{
public:
	Player();
	~Player(){};
	void changeHP(int n);
	void changeWeapon(string& weaponName);
	void displayStats();
	string readScroll(string& scrollType);
};

class Monster : public Actor //Base class
{
public:
	Monster(){};
	virtual ~Monster(){};
};

class Bogeyman : public Monster
{
public:
	Bogeyman();
	~Bogeyman(){};
};

class Snakewoman : public Monster
{
public:
	Snakewoman();
	~Snakewoman(){};
};

class Dragon : public Monster
{
public: 
	Dragon();
	~Dragon(){};
};

class Goblin : public Monster
{
public: 
	Goblin();
	~Goblin(){};
};

#endif // ACTORS_INCLUDED
