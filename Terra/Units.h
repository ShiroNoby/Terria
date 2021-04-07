#ifndef _Units_
#define _Units_

#include "SFML/Graphics.hpp"
#include "CommonTools.h"

enum class Units_Type 
{
	NON_UNIT		= 0,
	UNIT_Human		= 1,
	UNIT_Wolf		= 2,
	UNIT_Raven		= 3,
};

class Unit 
{
	//heal Point(HP)
	struct heal_Bar 
	{
		int health	= 0;;
	}					indicator;

	Units_Type			m_type;
	
	Position			m_Unit_Position;
	inventory			m_Unit_Inventory;
	sf::Sprite			m_Unit_Sprite;
	
public:

	Unit();

	Unit(const Units_Type& type);

	void setPosition(const int& x, const int& y);

	~Unit();
};
#endif _Units_