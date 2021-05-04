#include "Game_Objects.h"

//default constructor
Object::Object() 
{
	m_type						= Object_type::NON_OBJECT;
}

//coppyng constructor 
/*
* нецелесообразно
Object::Object(const Object& object) 
	:	m_pos(object.m_pos),
		m_type(object.m_type),
		m_inventory(object.m_inventory) {}
*/

//custom constructor
Object::Object(const Object_type& type) 
{
	m_type						= type;
	//на основе типа, инициализируем все остальное
}

//set object posotion
void Object::setPosition(float& x, float& y) 
{
	m_pos.x_pos					= x;
	m_pos.y_pos					= y;

	m_Object_Sprite.setPosition(x, y);
}

Position& Object::getPosition()
{
	return m_pos;
}

//доступ к инвентарю
inventory& Object::getInventory() 
{
	return m_inventory;
}

Object& Object::operator=(const Object& Object)
{
	this->m_type					= Object.m_type;
	this->m_pos.x_pos				= Object.m_pos.x_pos;
	this->m_pos.y_pos				= Object.m_pos.y_pos;

	this->m_Texture					= Object.m_Texture;

	this->m_inventory				= Object.m_inventory;

	this->m_Object_Sprite.setColor(Object.m_Object_Sprite.getColor());
	this->m_Object_Sprite.setPosition(Object.m_Object_Sprite.getPosition());
	this->m_Object_Sprite.setTexture(Object.m_Texture);
	
	
	return *this;
}


Object& Object::operator=(Object&& Res) 
{
	*this = Res;
	
	Res.m_inventory.null();
	return *this;
}

bool Object::contains(const float& x, const float& y)
{
	return m_Object_Sprite.getGlobalBounds().contains(x, y);
}

void Object::setTexture(sf::Texture& texture, int x, int y, int Width, int Heigth)
{
	m_Texture = texture;
	m_Object_Sprite.setTexture(texture);
	m_Object_Sprite.setTextureRect(sf::IntRect(x, y, Width, Heigth));
}

void Object::setColor(sf::Shape& shape)
{
	this->m_Object_Sprite.setColor(shape.getFillColor());
}


void Object::setScale(const float& x, const float& y)
{
	m_Object_Sprite.setScale(x, y);
	m_Texture.update(this->m_Texture, x, y);
}

const sf::Sprite& Object::getSprite() const 
{
	return m_Object_Sprite;
}

//выпадение предмета из инвентаря
/*
Resourse drop();
*/

Object::~Object() 
{
	m_inventory.~inventory();
}