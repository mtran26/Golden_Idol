// Game.cpp

#include "Game.h"
#include "GameObjects.h"
#include <string>
#include <iostream>
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance)
{
	smellDistance = goblinSmellDistance;
	int k = 0;
	for (int i = 0; i < 26; i++)
	{
		inventory[i] = (char)(97 + (k++));
		inventory[i] += ". ";
	}

	Coord position = m_player.getPosition();

	first = new Weapon();
	first->setWeapon(1);

	itemsList[0] = first;

}

/*void Game::pathExists(int& sr, int& sc, int& playerR, int& playerC)
{
	Coord monstPos; monstPos.m_r = sr; monstPos.m_c = sc;
	char monst = gameMap.checkString(sr, sc);

	if (monstPos.m_r == playerR && monstPos.m_c == playerC)
	{
		//cout << "Start: " << sr << ", " << sc << " End: " << er << ", " << ec << endl;
		return;
	}

	int r;
	int c;
	//==========================================================================================
	//er, ec should be the player's position
	//sr, sc should be the monster's assigned position
	//Instead of bool, perhaps just set the coordinate to the next one --> it will move if there is an opening to get closer to the player
	//However, for B and S, if they're blocked, then they'll move. But don't move away to get to a path. 

	if (gameMap.checkString(sr-1,sc) == ' ') //If you can move NORTH
	{
		r = sr - 1;
		gameMap.setCoord(monst, r, sc);
		pathExists(r, sc, position.m_r, position.m_c);
	}

/*	if (maze[sr][sc + 1] == '.') //If you can move EAST
	{
		if (pathExists(sr, sc + 1, er, ec))
			return true;
	}

	if (maze[sr + 1][sc] == '.') //If you can move SOUTH
	{
		if (pathExists(sr + 1, sc, er, ec))
			return true;
	}

	if (maze[sr][sc - 1] == '.') //If you can move WEST
	{
		//cout << "Moved west.\nPosition now: " << sr << ", " << sc-1 << endl;
		if (pathExists(sr, sc - 1, er, ec))
			return true;
	}

	return false;*/

void Game::hasMonster()
//If there is a monster right next to the player, have them fight by calling their respective Actor::attack() and Actor::decreaseHP() functions.
{
	int leftX = position.m_r - 1;
	int rightX = position.m_r + 1;
	int btmY = position.m_c + 1;
	int topY = position.m_c - 1;
	char left = gameMap.checkString(leftX, position.m_c);
	char right = gameMap.checkString(rightX, position.m_c);
	char btm = gameMap.checkString(position.m_r, btmY);
	char top = gameMap.checkString(position.m_r, topY);

	if ((left == ' ' || left == '#') && (right == ' ' || right == '#') && (btm == ' ' || btm == '#') && (top == ' ' || top == '#'))
		//If there are no monsters beside the player, return.
		return;

	if (monstLoc == EMPTY)
	{
		switch (left)
		{
		case 'B':
		{
			Bogeyman *monst = new Bogeyman();
			monst->setPosition(leftX, position.m_c);
			m_enemy = *monst;
			monstLoc = LEFT;
			delete monst;
		}
		break;
		case 'S':
		{
			Snakewoman *monst = new Snakewoman();
			monst->setPosition(leftX, position.m_c);
			m_enemy = *monst;
			monstLoc = LEFT;
			delete monst;
		}
		break;
		case 'D':
		{
			Dragon *monst = new Dragon();
			monst->setPosition(leftX, position.m_c);
			m_enemy = *monst;
			monstLoc = LEFT;
			delete monst;
		}
		break;
		case 'G':
		{
			Goblin *monst = new Goblin();
			monst->setPosition(leftX, position.m_c);
			m_enemy = *monst;
			monstLoc = LEFT;
			delete monst;
		}
		break;
		}

		switch (right)
		{
		case 'B':
		{
			Bogeyman *monst = new Bogeyman();
			monst->setPosition(rightX, position.m_c);
			m_enemy = *monst;
			monstLoc = RIGHT;
			delete monst;
		}
		break;
		case 'S':
		{
			Snakewoman *monst = new Snakewoman();
			monst->setPosition(rightX, position.m_c);
			m_enemy = *monst;
			monstLoc = RIGHT;
			delete monst;
		}
		break;
		case 'D':
		{
			Dragon *monst = new Dragon();
			monst->setPosition(rightX, position.m_c);
			m_enemy = *monst;
			monstLoc = RIGHT;
			delete monst;
		}
		break;
		case 'G':
		{
			Goblin *monst = new Goblin();
			monst->setPosition(rightX, position.m_c);
			m_enemy = *monst;
			monstLoc = RIGHT;
			delete monst;
		}
		break;
		}

		switch (btm)
		{
		case 'B':
		{
			Bogeyman *monst = new Bogeyman();
			monst->setPosition(position.m_r, btmY);
			m_enemy = *monst;
			monstLoc = DOWN;
			delete monst;
		}
		break;
		case 'S':
		{
			Snakewoman *monst = new Snakewoman();
			monst->setPosition(position.m_r, btmY);
			m_enemy = *monst;
			monstLoc = DOWN;
			delete monst;
		}
		break;
		case 'D':
		{
			Dragon *monst = new Dragon();
			monst->setPosition(position.m_r, btmY);
			m_enemy = *monst;
			monstLoc = DOWN;
			delete monst;
		}
		break;
		case 'G':
		{
			Goblin *monst = new Goblin();
			monst->setPosition(position.m_r, btmY);
			m_enemy = *monst;
			monstLoc = DOWN;
			delete monst;
		}
		break;
		}

		switch (top)
		{
		case 'B':
		{
			Bogeyman *monst = new Bogeyman();
			monst->setPosition(position.m_r, topY);
			m_enemy = *monst;
			monstLoc = UP;
			delete monst;
		}
		break;
		case 'S':
		{
			Snakewoman *monst = new Snakewoman();
			monst->setPosition(position.m_r, topY);
			m_enemy = *monst;
			monstLoc = UP;
			delete monst;
		}
		break;
		case 'D':
		{
			Dragon *monst = new Dragon();
			monst->setPosition(position.m_r, topY);
			m_enemy = *monst;
			monstLoc = UP;
			delete monst;
		}
		break;
		case 'G':
		{
			Goblin *monst = new Goblin();
			monst->setPosition(position.m_r, topY);
			m_enemy = *monst;
			monstLoc = UP;
			delete monst;
		}
		break;
		}
	}

	if (monstLoc != EMPTY)
	{
		if (m_player.getHP() > 0)
			m_player.attack(m_enemy);

		if (m_enemy.getHP() > 0)
			m_enemy.attack(m_player);
		else
		{
			monstLoc = EMPTY;
			Coord pos = m_enemy.getPosition();
			itemFromMonster = gameMap.deadMonster(pos.m_r, pos.m_c);
		}
	}
}

void Game::inventoryMenu()
//Returns true if a selection has been made. False otherwise.
//If 'i' was pressed, no item can be selected.
//If 'r' was pressed, no weapon can be selected.
//If 'w' was pressed, no scroll can be read.
{
	clearScreen();
	bool itemExists = false;
	cout << "Inventory:\n";

	//Print out all the items inside of player's inventory
	for (int i = 0; i < numItems; i++)
		cout << inventory[i] << itemsList[i]->getName() << endl;
	onInvenMenu = true;

	char tmp = getCharacter();

	if (pressedKey == 'i')
		return;

	string switchedWeapon;
	Weapon* weap;
	int itemIndex;
	switch (tmp)
	{
	case 'a':
		switchedWeapon = itemsList[0]->getName();
		itemExists = true;
		break;
	case 'b':
		if (numItems > 1)
		//If isWeapon returns true, then set weapon. 
		{
			switchedWeapon = itemsList[1]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[1]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[1]->getName();
			itemIndex = 1;
			itemExists = true;
		}
		break;
	case 'c':
		if (numItems > 2)
		{
			switchedWeapon = itemsList[2]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[2]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[2]->getName();
			itemIndex = 2;
			itemExists = true;
		}
		break;
	case 'd':
		if (numItems > 3)
		{
			switchedWeapon = itemsList[3]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[3]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[3]->getName();
			itemIndex = 3;
			itemExists = true;
		}
		break;
	case 'e':
		if (numItems > 4)
		{
			switchedWeapon = itemsList[4]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[4]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[4]->getName();
			itemIndex = 4;
			itemExists = true;
		}
		break;
	case 'f':
		if (numItems > 5)
		{
			switchedWeapon = itemsList[5]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[5]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[5]->getName();
			itemIndex = 5;
			itemExists = true;
		}
		break;
	case 'g':
		if (numItems > 6)
		{
			switchedWeapon = itemsList[6]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[6]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[6]->getName();
			itemIndex = 6;
			itemExists = true;
		}
		break;
	case 'h':
		if (numItems > 7)
		{
			switchedWeapon = itemsList[7]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[7]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[7]->getName();
			itemIndex = 7;
			itemExists = true;
		}
		break;
	case 'i':
		if (numItems > 8)
		{
			switchedWeapon = itemsList[8]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[8]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[8]->getName();
			itemIndex = 8;
			itemExists = true;
		}
		break;
	case 'j':
		if (numItems > 9)
		{
			switchedWeapon = itemsList[9]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[9]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[9]->getName();
			itemIndex = 9;
			itemExists = true;
		}
		break;
	case 'k':
		if (numItems > 10)
		{
			switchedWeapon = itemsList[10]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[10]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[10]->getName();
			itemIndex = 10;
			itemExists = true;
		}
		break;
	case 'l':
		if (numItems > 11)
		{
			switchedWeapon = itemsList[11]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[11]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[11]->getName();
			itemIndex = 11;
			itemExists = true;
		}
		break;
	case 'm':
		if (numItems > 12)
		{
			switchedWeapon = itemsList[12]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[12]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[12]->getName();
			itemIndex = 12;
			itemExists = true;
		}
		break;
	case 'n':
		if (numItems > 13)
		{
			switchedWeapon = itemsList[13]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[13]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[13]->getName();
			itemIndex = 13;
			itemExists = true;
		}
		break;
	case 'o':
		if (numItems > 14)
		{
			switchedWeapon = itemsList[14]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[14]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[14]->getName();
			itemIndex = 14;
			itemExists = true;
		}
		break;
	case 'p':
		if (numItems > 15)
		{
			switchedWeapon = itemsList[15]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[15]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[15]->getName();
			itemIndex = 15;
			itemExists = true;
		}
		break;
	case 'q':
		if (numItems > 16)
		{
			switchedWeapon = itemsList[16]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[16]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[16]->getName();
			itemIndex = 16;
			itemExists = true;
		}
		break;
	case 'r':
		if (numItems > 17)
		{
			switchedWeapon = itemsList[17]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[17]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[17]->getName();
			itemIndex = 17;
			itemExists = true;
		}
		break;
	case 's':
		if (numItems > 18)
		{
			switchedWeapon = itemsList[18]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[18]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[18]->getName();
			itemIndex = 18;
			itemExists = true;
		}
		break;
	case 't':
		if (numItems > 19)
		{
			switchedWeapon = itemsList[19]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[19]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[19]->getName();
			itemIndex = 19;
			itemExists = true;
		}
		break;
	case 'u':
		if (numItems > 20)
		{
			switchedWeapon = itemsList[20]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[20]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[20]->getName();
			itemIndex = 20;
			itemExists = true;
		}
		break;
	case 'v':
		if (numItems > 21)
		{
			switchedWeapon = itemsList[21]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[21]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[21]->getName();
			itemIndex = 21;
			itemExists = true;
		}
		break;
	case 'w':
		if (numItems > 22)
		{
			switchedWeapon = itemsList[22]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[22]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[22]->getName();
			itemIndex = 22;
			itemExists = true;
		}
		break;
	case 'x':
		if (numItems > 23)
		{
			switchedWeapon = itemsList[23]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[23]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[23]->getName();
			itemIndex = 23;
			itemExists = true;
		}
		break;
	case 'y':
		if (numItems > 24)
		{
			switchedWeapon = itemsList[24]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[24]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[24]->getName();
			itemIndex = 24;
			itemExists = true;
		}
		break;
	case 'z':
		if (numItems > 25)
		{
			switchedWeapon = itemsList[25]->getName();
			weap = dynamic_cast<Weapon*>(itemsList[25]);
			if (weap != nullptr)
				switchedWeapon = weap->getName();
			else
				useScroll = itemsList[25]->getName();
			itemIndex = 25;
			itemExists = true;
		}
		break;
	default:
		return;
	}

	if (pressedKey == 'w')
	{
		if (switchedWeapon != "")
		{
			chosenItem = "You are wielding " + switchedWeapon + "\n";
			m_player.changeWeapon(switchedWeapon);
			switchedWeapon = "";
		}
		else
			chosenItem = "You cannot wield a scroll.\n";
	}
	
	if (pressedKey == 'r')
	{
		if (!itemExists)
		{
			chosenItem = "";
			itemExists = false;
			return;
		}

		if (useScroll != "")
		{
			chosenItem = m_player.readScroll(useScroll);

			//After scroll self-destructs, the inventory index updates itself. 
			itemsList.erase(itemIndex);
			numItems--;
			useScroll = "";
		}
		else
			chosenItem = "You cannot read a weapon.\n";

		itemExists = false;
	}
}

void Game::increaseInventory(int itemType, int itemFromMonster)
//Weapon = 0, Scroll = 1
//Adds the item to the list on the inventory menu. 
{
	if (itemType == 0)
	{
		Weapon *object = new Weapon();

		switch (itemFromMonster)
		//Sets the proper item to be dropped by the corresponding monster. 
		//Bogeyman = 0, Snakewoman = 1, Dragon = 2, Goblin = 3
		{
		case 0: 
			object->setWeapon(0); //Drops mace
			break;
		case 1:
			object->setWeapon(3); //Drops magic fangs of sleep
			break;
		case 3:
			object->setWeapon(randInt(2) + 3); //Drops magic fangs of sleep or magic axe
			break;
		}

		cout << "You picked up " << object->getName() << endl;
		itemsList[numItems] = object;
	}
	else
	{
		Scroll *object = new Scroll();

		if (itemFromMonster == 2)
			object->setScrollType(randInt(5));

		cout << "You picked up " << object->getName() << endl;
		itemsList[numItems] = object;
	}

	if (numItems <= MAX_ITEMS)
		numItems++;
	else
		cout << "Your knapsack is full; you can't pick that up.\n";
}

void Game::updateDisplay()
//Refreshes the screen with each turn to update the fight or the player's movement. 
{
	clearScreen();
	position = m_player.getPosition();
	gameMap.setCoord('@', position.m_r, position.m_c);
	gameMap.print();
	m_player.displayStats();
}

void Game::play()
{
	updateDisplay();
	int prevR = 0;
	int prevC = 0;
	int nextR;
	int nextC;
	int item;

	int current;

	pressedKey = getCharacter();
	while (pressedKey != 'q')
	{
		if (gameOver == true)
		{
			pressedKey = getCharacter();
			continue;
		}

		//initial = false;
		switch (pressedKey)
		{
		case 'c':
			if (onInvenMenu == true)
				onInvenMenu = false;
			m_player.changeHP(30);
			m_player.setSP(9);
			clearScreen();
			break;
		case '>':
			gameMap.nextLevel();

			nextR = randInt(58)+1;
			nextC = randInt(15)+1;
			gameMap.setCoord('@', nextR, nextC, position.m_r, position.m_c);
			m_player.setPosition(nextR, nextC);
			break;
		case 'i':
			if (onInvenMenu == false)
				inventoryMenu();
			else
				onInvenMenu = false;
			break;
		case 'r':
			if (onInvenMenu == false)
				inventoryMenu();
			else
				onInvenMenu = false;
			break;
		case 'w':
			if (onInvenMenu == false)
				inventoryMenu();
			else
				onInvenMenu = false;
			break;
		case 'g':
			if (onInvenMenu == true)
				break;
			current = gameMap.checkForItem(position.m_r, position.m_c);
			if (current == 0)
			{
				increaseInventory(0, itemFromMonster);
				gameMap.pickedUpItem();
			}
			else if (current == 1)
			{
				increaseInventory(1, itemFromMonster);
				gameMap.pickedUpItem();
			}
			else if (onInvenMenu == true)
				break;
			else{}

			pressedKey = getCharacter();
			continue;
		case ARROW_LEFT:
			if (monstLoc == LEFT)
				break;

			nextR = position.m_r - 1;
			prevR = position.m_r;
			gameMap.setCoord('@', nextR, position.m_c, position.m_r, position.m_c);
			m_player.setPosition(nextR, position.m_c);
			break;
		case ARROW_RIGHT:
			if (monstLoc == RIGHT)
				break;
			nextR = position.m_r + 1;
			prevR = position.m_r;
			gameMap.setCoord('@', nextR, position.m_c, position.m_r, position.m_c);
			m_player.setPosition(nextR, position.m_c);
			break;
		case ARROW_DOWN:
			if (monstLoc == DOWN)
				break;
			nextC = position.m_c + 1;
			prevC = position.m_c;
			m_player.setPosition(position.m_r, nextC);
			gameMap.setCoord('@', position.m_r, nextC, position.m_r, position.m_c);
			break;
		case ARROW_UP:
			if (monstLoc == UP)
				break;

			nextC = position.m_c - 1;
			prevC = position.m_c;
			gameMap.setCoord('@', position.m_r, nextC, position.m_r, position.m_c);
			m_player.setPosition(position.m_r, nextC);
			break;
		}

		if (onInvenMenu == false)
		{
			if (m_player.getHP() <= 0)
				gameOver = true;


			updateDisplay(); 
			hasMonster();

			//Checks if the Player is already dead; if yes, then don't ask for another turn. 
			if (m_player.getHP() <= 0)
				continue;
		}
		else
		{
			if (chosenItem != "")
			{
				if (useScroll == "scroll of teleportation")
				//Set the player to a new, random position.
				{
					int x = randInt(58)+1;
					int y = randInt(15)+1;

					m_player.setPosition(x, y);
					gameMap.setCoord('@', x, y, position.m_r, position.m_c);
				}
				updateDisplay();
				cout << chosenItem;
				onInvenMenu = false;
				chosenItem = "";
				pressedKey = getCharacter();
			}

			continue;
		}

		pressedKey = getCharacter();
	}
	itemsList.clear();
}

// You will presumably add to this project other .h/.cpp files for the
// various classes of objects you need to play the game:  player, monsters,
// weapons, etc.  You might have a separate .h/.cpp pair for each class
// (e.g., Player.h, Boegeyman.h, etc.), or you might put the class
// declarations for all actors in Actor.h, all game objects in GameObject.h,
// etc.
