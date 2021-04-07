#ifndef _GAME_OBJECTS_
#define _GAME_OBJECTS_

#include "CommonTools.h"

enum class Object_type 
{
	NON_OBJECT		= 0,
	OBJECT_Stone	= 1,
	OBJECT_Dirt		= 2,
	OBJECT_Wood		= 3,
};

class Object 
{
	//x_pos, y_pos;
	Position		m_pos;

	Object_type		m_type;
	
	//Resourse*		Resourse_m_data;
	//int			m_length;
	//int			m_size;
	inventory		m_inventory;

	//Texture
	sf::Sprite		m_Object_Sprite;

public:
	//default constructor
	Object();

	//coppyng constructor 
	/*
	Object(const Object& object);
	/**/

	//custom constructor
	Object(const Object_type& type);

	//set object posotion
	void setPosition(int& x, int& y);

	//доступ к инвентарю
	inventory& getInventory();

	//выпадение предмета из инвентаря
	/*
	Resourse drop();
	*/

	~Object();
};

#endif _GAME_OBJECTS_