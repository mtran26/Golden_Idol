// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "utilities.h"
#include "Actors.h"
#include "GameDisplay.h"
#include "GameObjects.h"
#include<map>
// You may add data members and other member functions to this class.

struct Menus{
	//map<int, string> inventory;
	map<int, GameObject> itemsMenu;
};

enum Direction{ EMPTY = -1, LEFT = 0, RIGHT = 1, DOWN = 3, UP = 4 };

const int MAX_ITEMS = 25;

class Game
{
public:
	Game(int goblinSmellDistance);
	void play();
	void inventoryMenu();
	void increaseInventory(int itemType, int item);
	void hasMonster(); //Returns the direction that the monster is at
	void updateDisplay();
	void pathExists(int& sr, int& sc, int& playerR, int& playerC);
private:
	Player m_player;
	Coord position;
	map<int, string> inventory;
	map<int, GameObject*> itemsList;
	Weapon* first;
	int numItems = 1; //By index of inventory
	bool onInvenMenu = false;
	bool gameOver = false;
	Display gameMap;
	Monster m_enemy;
	Direction monstLoc = EMPTY; //Holds which side the monster is on in terms of the player
	int itemFromMonster = -1;
	string chosenItem;
	string useScroll;
	char pressedKey;
	int smellDistance;
};

#endif // GAME_INCLUDED
