#pragma once

#include <string>

using std::string;


class CCards
{
private:
	string m_name;
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
	CCards();
	~CCards();
};

