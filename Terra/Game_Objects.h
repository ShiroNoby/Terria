#ifndef _GAME_OBJECTS_
#define _GAME_OBJECTS_

#include "CommonTools.h"

//типы объектов в программе
//NON_OBJECT		0		
//Object_Menu		1-20
enum class Object_type 
{
	NON_OBJECT			= 0,
	
	//Object_Menu
	//*****************************
	OBJECT_New_Game		= 1,
	OBJECT_Load_Game	= 2,
	OBJECT_Exit			= 3,
	OBJECT_Yes			= 4,
	OBJECT_No			= 5,
	OBJECT_Genered_Seed = 6,
	OBJECT_Seed			= 7,
	OBJECT_Ok			= 8,
	OBJECT_Cancel		= 9,
	OBJECT_Screan_Shot	= 10,
	OBJECT_Load			= 11,

	MAX_OBJECT_MENU,
	
	//Object_Game
	//*****************************
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
	sf::Texture		m_Texture;

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
	void setPosition(float& x, float& y);

	Position& getPosition();

	//доступ к инвентарю
	inventory& getInventory();

	Object& operator=(const Object& Res);

	Object& operator=(Object&& Res);

	//коллизия
	bool contains(const float& x, const float& y);

	void setTexture(sf::Texture& texture, int x, int y, int Width, int Heigth);

	void setColor(sf::Shape& shape);

	void setScale(const float& x, const float& y);


	const sf::Sprite& getSprite() const;

	//выпадение предмета из инвентаря
	/*
	Resourse drop();
	*/

	~Object();
};

#endif _GAME_OBJECTS_