#pragma once

#include <string>

using std::string;


class CCards
{
private:
	string m_Name;
	int m_Cost;
	int m_HP;
	int m_Dmg;

	enum RARITY
	{
		COMMON,
		RARE,
		EPIC
	};
	enum TYPE
	{
		TROOP,
		BUILDING,
		SPELL
	};
	enum TARGETS
	{
		GROUND,
		AG,
		BULIDINGS,
		NA
	};

public:

	//===Getters and Setters===//
	//-Name
	void setName(string name);
	string getName();
	//-Cost
	void setCost(int cost);
	int getCost();
	//-Health
	void setHealth(int hp);
	int getHealth();
	//-Damage
	void setDamage(int dmg);
	int getDamage();






	CCards();
	~CCards();
};

