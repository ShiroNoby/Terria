#ifndef _COMMON_TOOLS_
#define _COMMON_TOOLS_

#include "SFML/Graphics.hpp"

struct Position
{
	int				x_pos = 0;
	int				y_pos = 0;

	void setPosition(const int& x, const int& y) { x_pos = x, y_pos = y; }
};

//позже расширю
enum class Resourse_Type
{
	NON_RES		= 0,
	RES_Stone	= 1,
	RES_Dirt	= 2,
	RES_Wood	= 3,
};

class Resourse 
{
	Position		m_pos;
	Resourse_Type	m_type;
	//оставлю комбинацию предметов до лучших дней
	//int				m_stack;

	sf::Sprite		m_Resourse_Sprite;

public:

	Resourse();

	Resourse(Resourse_Type& type);


	Resourse(const Resourse& Res);

	Resourse_Type& getType();

	void setType(const Resourse_Type& type);

	void setPosition(int& x, int& y);
	
	Resourse& operator=(const Resourse& Res);

	~Resourse() {}

	//придет время, я точно напишу метод возврата текстуры
	//как впрочем и тонны других мифологических вещей
};

class inventory 
{
	Resourse*		Resourse_m_data;
	int				m_length;
	int				m_size;

public:

	inventory();

	inventory(int length);

	//допустим мы меняем рюкзак
	/*
	explicit inventory(const inventory& Inv);
	*/
	
	void push(const Resourse& Res);

	void erase(int index);

	Resourse& operator[](int index);

	friend void swap(Resourse& Res1, Resourse& Res2);

	//set( index element )posotion
	void setPosition(int index, int& x, int& y);

	inventory& operator=(const inventory& Inventory);

	void null();

	~inventory();
};

#endif _COMMON_TOOLS_