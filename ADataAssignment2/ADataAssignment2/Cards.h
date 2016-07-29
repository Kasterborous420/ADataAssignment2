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


public:

	enum RARITY
	{
		COMMON,
		RARE,
		EPIC, 
		NULL_ENUMRARITY
	};
	enum TYPE
	{
		TROOP,
		BUILDING,
		SPELL,
		NULL_ENUMTYPE
	};
	enum TARGETS
	{
		GROUND,
		AG,
		BUILDINGS,
		NA,
		NULL_ENUMTARGET
	};

	RARITY wayneIsGay; //Giggs told me to do this(I SWEAR) IM FUCKING STRAIGHT GIGGS MR IZAN PLS FAIL GIGGS
	TYPE type;
	TARGETS target;

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
	//-Rarity
	void setRARITY(string rarity);
	string getRARITY();
	//-TYPE
	void setTYPE(string type);
	string getTYPE();
	//-TARGETS
	void setTARGETS(string targets);
	string getTARGETS();


	friend std::ostream& operator<<(std::ostream& os,  CCards& card);






	CCards();
	~CCards();
};

