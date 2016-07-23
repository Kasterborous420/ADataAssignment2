#include "Cards.h"


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
