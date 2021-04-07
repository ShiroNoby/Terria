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
void Object::setPosition(int& x, int& y) 
{
	m_pos.x_pos					= x;
	m_pos.y_pos					= y;
}

//доступ к инвентарю
inventory& Object::getInventory() 
{
	return m_inventory;
}

//выпадение предмета из инвентаря
/*
Resourse drop();
*/

Object::~Object() 
{
	m_inventory.~inventory();
}