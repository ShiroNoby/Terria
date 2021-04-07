#include "Units.h"

Unit::Unit()
	:m_type(Units_Type::NON_UNIT) {}

Unit::Unit(const Units_Type& type) 
{
	m_type = type;
	//init согласно полученному типу
}

void Unit::setPosition(const int& x, const int& y) 
{
	m_Unit_Position.setPosition(x, y);
}

Unit::~Unit() 
{
	m_Unit_Inventory.~inventory();
}