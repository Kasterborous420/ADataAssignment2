#include "Cards.h"
#include <ctype.h>


CCards::CCards()
{
	this->m_Cost = 0;
	this->m_HP = 0;
	this->m_Dmg = 0;
	this->wayneIsGay = NULL_ENUMRARITY;
	this->type = NULL_ENUMTYPE;
	this->target = NULL_ENUMTARGET;
}


CCards::~CCards()
{
}



//===Getters and Setters===//

//-Name
void CCards::setName(string name)
{
	this->m_Name = name;
}
string CCards::getName()
{
	return m_Name;
}

//-Cost
void CCards::setCost(int cost)
{
	this->m_Cost = cost;
}
int CCards::getCost()
{
	return m_Cost;
}

//-Health
void CCards::setHealth(int hp)
{
	this->m_HP = hp;
}
int CCards::getHealth()
{
	return m_HP;
}

//-Damage
void CCards::setDamage(int dmg)
{
	this->m_Dmg = dmg;
}
int CCards::getDamage()
{
	return m_Dmg;
}

//-Rarity
void CCards::setRARITY(string _rarity)
{
	if (_rarity == "Common")
	{
		wayneIsGay = COMMON;
	}
	else if (_rarity == "Rare")
	{
		wayneIsGay = RARE;
	}
	else if (_rarity == "Epic")
	{
		wayneIsGay = EPIC;
	}
}
string CCards::getRARITY()
{
	switch (wayneIsGay)
	{
		case COMMON:
			return "Common";

		case RARE:
			return "Rare";

		case EPIC:
			return "Epic";

		case NULL_ENUMRARITY:
			return "";

	}
}

//-TYPE
void CCards::setTYPE(string _type)
{
	if (_type == "Troop")
	{
		type = TROOP;
	}
	else if (_type == "Building")
	{
		type = BUILDING;
	}
	else if (_type == "Spell")
	{
		type = SPELL;
	}
}
string CCards::getTYPE()
{
	switch (type)
	{
	case TROOP:
		return "Troop";

	case BUILDING:
		return "Buildings";

	case SPELL:
		return "Spell";

	case NULL_ENUMTYPE:
		return "";

	}
}

//-TARGETS
void CCards::setTARGETS(string _targets)
{

	if (_targets == "Ground")
	{
		target = GROUND;
	}
	else if (_targets == "AG")
	{
		target = AG;
	}
	else if (_targets == "Buildings")
	{
		target = BUILDINGS;
	}
	else if (_targets == "NA")
	{
		target = NA;
	}
}
string CCards::getTARGETS()
{
	switch (target)
	{
	case GROUND:
		return "Ground";

	case AG:
		return "AG";

	case BUILDINGS:
		return "Buildings";

	case NA:
		return "NA";

	case NULL_ENUMTARGET:
		return "";

	}
}


//Operator Overloading
std::ostream& operator<<(std::ostream& os,  CCards& card)
{
	os << card.getName() << ", " << card.getCost() << ", " << card.getRARITY() << ", " << card.getTYPE() << ", " << card.getTARGETS() << ", " << card.getHealth() << ", " << card.getDamage();
	return os;
}