#pragma once

#include <iostream>
#include <vector>
using namespace std;

#ifndef Player_H
#define Player_H

class Player
{
private:
	string playerName;
	int maxHP;
	int currentHP;
	bool collectedOxygenTanks[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int currentRoomID;
	bool isAlive = true;

public:
	vector<string> inventory;

	//Constructor
	Player()
	{
	}

	Player(string name, int hp, int startingRoom)
	{
		setPlayerName(name);
		setMaxHP(hp);
		currentHP = maxHP;	//Start at Max HP
		inventory = {};		//Resets Inventory
		currentRoomID = startingRoom;
	}
	int getcurrentRoom()
	{
		return currentRoomID;
	}

	bool getIsAlive()
	{
		return isAlive;
	}

	int getCurrentHP()
	{
		return currentHP;
	}

	int getMaxHP()
	{
		return maxHP;
	}

	void setCurrentRoom(int ID)
	{
		currentRoomID = ID;
	}
	void setPlayerName(string name)
	{
		playerName = name;
	}

	void setMaxHP(int hp)
	{
		maxHP = hp;
	}

	void increaseMaxHP(int amount)
	{
		maxHP += amount;
		cout << "Your Maximum Oxygen increased to " << maxHP << "!" << endl << endl;
	}

	void addToInventory(string item)	//Adds new item into next spot in array
	{
		inventory.push_back(item);
	}

	bool searchInventory(string item)	//Goes through inventory to find an item. Called when needing an item to do something
	{
		
		
		if (std::find(inventory.begin(),inventory.end(), item) != inventory.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void showInventory()
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i + 1 << ". " << inventory[i] << endl;
		}
	}

	void takeDamage(int amount)	//Lowers current HP
	{		
		currentHP -= amount;
		cout << "You took " << amount << " damage!" << endl;	

		if (currentHP <= 0)
		{
			isAlive = false;
		}
	}

	void healDamage(int amount)	//Increases current HP
	{
		if (currentHP + amount > maxHP)	//Prevents healing over the maximum HP
		{
			currentHP = maxHP;
		}
		else
		{
			currentHP += amount;
			cout << "You healed " << amount << " damage!" << endl;
		}
	}

	void setCollectedOxygenTanks(int room)	//Sets that the player obtained the oxygen tank if it is in the room
	{
		collectedOxygenTanks[room] = true;
	}

	bool getCollectedOxygenTank(int room)	//Checks if player already obtained oxygen tank in this room
	{
		return collectedOxygenTanks[room];
	}

	void resetPlayer(int hp, int startRoom)
	{
		maxHP = hp;
		currentHP = maxHP;
		inventory.clear();
		currentRoomID = startRoom;
		
		for (int n = 0; n < 14; n++)
		{
			collectedOxygenTanks[n] = false;
		}
	}
};

#endif
