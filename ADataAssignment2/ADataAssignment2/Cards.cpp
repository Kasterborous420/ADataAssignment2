#include "Cards.h"
#include <ctype.h>


CCards::CCards()
{
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
	return this->m_Name;
}

//-Cost
void CCards::setCost(int cost)
{
	this->m_Cost = cost;
}
int CCards::getCost()
{
	return this->m_Cost;
}

//-Health
void CCards::setHealth(int hp)
{
	this->m_HP = hp;
}
int CCards::getHealth()
{
	return this->m_HP;
}

//-Damage
void CCards::setDamage(int dmg)
{
	this->m_Dmg = dmg;
}
int CCards::getDamage()
{
	return this->m_Dmg;
}

//-Rarity
void CCards::setRARITY(string rarity)
{
	for (int i = 0; i < rarity.size(); i++)
	{
		char c = rarity[i];
		putchar(tolower(c));
	}
	RARITY Rarity;
	Rarity = COMMON;
}
CCards::RARITY CCards::getRARITY()
{

}

//-TYPE
void CCards::setTYPE(string type)
{

}
CCards::TYPE CCards::getTYPE()
{

}

//-TARGETS
void CCards::setTARGETS(string targets)
{

}
CCards::TARGETS CCards::getTARGETS()
{

}
