

#include "GameDisplay.h"
#include <string>
#include <iostream>
using namespace std;

Display::Display()
{
	for (int i = 0; i < MAX_WIDTH; i++)	
	//The top and bottom walls. 
	{
		map[i][0] = '#';
		map[i][MAX_HEIGHT-1] = '#';
	}

	for (int k = 1; k < MAX_HEIGHT - 1; k++)
		for (int i = 1; i < MAX_WIDTH - 1; i++)
		//Side walls and the area within.
		{
			//map[i][k] = ' ';
			map[0][k] = '#';
			map[MAX_WIDTH-1][k] = '#';
		}
}

void Display::nextLevel()
{
	if (currentLevel < 4)
	{
		currentLevel++;
		sameLevel = false;
	}
}

char Display::checkString(const int& r, const int& c)
{
	return map[r][c];
}

void Display::hasItem(const int& r, const int& c)
//If the certain position has an item, then return true. Mark down the item type (Scroll or weapon)
{
	item = map[r][c];
	hasItembool = true;
}

int Display::checkForItem(const int&r, const int& c)
//Checks which item is being picked up and then changes its position to empty.
{
	int toReturn = -1; 

	switch (item)
	{
	case ')':
		toReturn = 0; 
		break;
	case '?':
		toReturn = 1;
		break; 
	}

	item = ' ';
	return toReturn;
}

void Display::pickedUpItem()
{
	hasItembool = false;
}

void Display::setCoord(char type, int& r, int& c)
{
	switch (type)
	{
	case '@':
		map[r][c] = '@';
		m_x = r;
		m_y = c;
		break;
	}
}

int Display::deadMonster(const int& r, const int& c)
//When a monster dies, this function is called and sets the location to an empty space or a dropped item
//Returns the type of monster (by int) to determine what item to create during game play. 
{
	int monsterType = -1;
	char monster = map[r][c];
	bool dropItem = true;
	switch (monster)
	{
	case 'B':
		monsterType = 0;
		dropItem = trueWithProbability(10);
		break;
	case 'S':
		monsterType = 1;
		dropItem = trueWithProbability(3);
		break;
	case 'D':
		{		
		monsterType = 2;
		//if(trueWithProbability(10));
		//	hp += 1; setHP(hp);
		map[r][c] = '?';
		return monsterType;
		}
		break;
	case 'G':
		monsterType = 3;
		dropItem = trueWithProbability(3);
		break;
	}

	if (dropItem == true)
		map[r][c] = ')';
	else
		map[r][c] = ' ';

	return monsterType;
}

void Display::setCoord(char type, int& r, int& c, int& prevR, int& prevC)
{

	if ((r < 1) || (c > 16) || (c < 1) || (r > 68)) 
	//Do nothing if it wants to go outside the walls. 
		return;

	if (hasItembool == true)
	//If the previous spot has an item, it should remain there until picked up. 
	{
		map[prevR][prevC] = item;
		hasItembool = false;

		setCoord(type, r, c);
		return;
	}	

	if (((r >= 1) || (c < 15)))
		//So long as it's still within bounds and there was no item, change the previous coord back to nothing. 
		map[prevR][prevC] = ' ';

	if (map[r][c] != ' ')
	//If the current spot has an item, mark it down.
		hasItem(r, c);
	
	//Set the current spot to where the player is. 
	setCoord(type, r, c);
}

void Display::print()
{
	if (!sameLevel)
	//If '>' is pressed, then the game map is randomized again, with the appropriate monster types. 
	{
		Coord newMonst;

		for (int k = 1; k < MAX_HEIGHT - 1; k++)
			for (int i = 1; i < MAX_WIDTH - 1; i++)
				//Refresh the map to empty spaces and repopulate them.
			{
				if (map[i][k] != '@')
					map[i][k] = ' ';
			}

		int ranX = randInt(65) + 1;
		int ranY = randInt(14) + 1;
	
		if (currentLevel < 4)
			map[ranX][ranY] = '>';

		//Number of monsters that should appear
		int n = 2 + randInt(5 * (currentLevel + 1));
		for (int i = 0; i < n; i++)
		{
			ranX = randInt(65) + 1;
			ranY = randInt(14) + 1;

			//Random coordinate (x,y) position for the element between 0 < x < 60 and 0 < y < 16.
			
			int ran = randInt(4);
			//Randomizes what will be printed. 

			switch (ran)
			{
			case 0:
				if (currentLevel >= 2)
					map[ranX][ranY] = 'B';
				break;
			case 1:
				map[ranX][ranY] = 'S';
				break;
			case 2:
				if (currentLevel >= 3)
					map[ranX][ranY] = 'D';
				break;
			case 3:
				map[ranX][ranY] = 'G';
				break;
			}
		}


		//Number of items to appear initially
		int m = 2 + randInt(2);
		for (int i = 0; i < m; i++)
		{
			int tmp = randInt(2);
			switch (tmp)
			{
			case 0:
				map[ranX][ranY] = ')';
				break;
			case 1:
				map[ranX][ranY] = '?';
				break;
			}
		}

		sameLevel = true;
	}

//Prints out the map with each call. 
	for (int i = 0; i < MAX_WIDTH; i++)
		cout << map[i][0];

	cout << endl;

	for (int k = 1; k < MAX_HEIGHT-1; k++)
	{
		for (int i = 0; i < MAX_WIDTH; i++)
			cout << map[i][k];

		cout << endl;
	}

	for (int i = 0; i < MAX_WIDTH; i++)
		cout << map[i][MAX_HEIGHT-1]; 

	cout << endl;

	cout << "Dungeon Level: " << currentLevel;
}