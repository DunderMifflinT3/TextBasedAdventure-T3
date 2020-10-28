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

public:
	vector<string> inventory;

	//Constructor
	Player()
	{
	}

	Player(string name, int hp)
	{
		setPlayerName(name);
		setMaxHP(hp);
		currentHP = maxHP;	//Start at Max HP
		inventory = {};		//Resets Inventory
	}

	int getCurrentHP()
	{
		return currentHP;
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
		if (amount >= currentHP)
		{
			playerDeath();
		}
		else
		{
			currentHP -= amount;
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
		}
	}

	void playerDeath()	//Plays a death message
	{
		cout << playerName << " has died!" << endl;	//Make more descriptive later
		cout << "Play again?" << endl;
		//Add input for yes or no
	}
};

#endif
