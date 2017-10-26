//Creating the game display

#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include "utilities.h"
#include "Actors.h"

const int MAX_HEIGHT = 18; 
const int MAX_WIDTH = 70;

class Display
{
public:
	Display();
	~Display(){};
	void print();
	void nextLevel();
	void setCoord(char type, int& r, int& c);
	void setCoord(char type, int& r, int& c, int& prevR, int& prevC);
	int deadMonster(const int& r, const int& c);
	void hasItem(const int& r, const int& c);
	int checkForItem(const int&r, const int& c);
	char checkString(const int&r, const int& c);
	void pickedUpItem();
	void beginAttack(){};

protected:
	int m_x; 
	int m_y;
	Coord monstCoords[15];
	int monstCount = 0;
	char map[MAX_WIDTH][MAX_HEIGHT];
	char item;
	bool hasItembool = false;
	int currentLevel = 0;
	bool sameLevel = false;
};

#endif // DISPLAY_INCLUDED