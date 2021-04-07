#include "CommonTools.h"

//class Resourse
//**********************************************************************************


Resourse::Resourse()
	:m_type(Resourse_Type::NON_RES) {}

explicit Resourse::Resourse(const Resourse& Res)
	: m_type(Res.m_type), m_Resourse_Sprite(Res.m_Resourse_Sprite)
{
	//оставлю комбинацию предметов до лучших дней
	/*
	if (Res.m_stack < 64) 
	{
		if ((Res.m_stack + m_stack) <= 64) 
		{
			m_stack += Res.m_stack;
		}
		
		if ((Res.m_stack + m_stack) > 64) {}
	}*/
}

Resourse::Resourse(Resourse_Type& type)
	: m_type(type) {}

Resourse_Type& Resourse::getType()
{
	return m_type;
}

void Resourse::setType(const Resourse_Type& type) 
{
	m_type					= type;
}

void Resourse::setPosition(int& x, int& y)
{
	m_pos.x_pos = x;
	m_pos.y_pos = y;
}

Resourse& Resourse::operator=(const Resourse& Res)
{
	m_pos.x_pos				= Res.m_pos.x_pos;
	m_pos.y_pos				= Res.m_pos.y_pos;
	m_type					= Res.m_type;
	m_Resourse_Sprite		= Res.m_Resourse_Sprite;

	return *this;
}


//class inventory
//**********************************************************************************


inventory::inventory()
	: Resourse_m_data(nullptr), m_length(0), m_size(0) {}

//допустим мы меняем рюкзак
/*
* для этого лучше исползовать что-то другое
explicit inventory::inventory(const inventory& Inv) {}
*/

inventory::inventory(int length) 
{
	if (length) 
	{ 
		m_length			= length; 
		Resourse_m_data		= new Resourse[m_length];
	}

	m_size					= 0;
}

void inventory::push(const Resourse& Res) 
{
	for (int index = 0; index < m_size; index++) 
	{
		if (Resourse_m_data[index].getType() == Resourse_Type::NON_RES)
		{
			Resourse_m_data[index] = Res;
			m_size++;
			return;
		}
	}
}

Resourse& inventory::operator[](int index) 
{
	if (index < m_size) { return Resourse_m_data[index]; }
}

void swap(Resourse& Res1, Resourse& Res2) 
{
	Resourse tmp;
	tmp						= Res1;
	Res1					= Res2;
	Res2					= tmp;
}

void inventory::erase(int index) 
{
	Resourse_m_data[index].setType(Resourse_Type::NON_RES);
}

void inventory::setPosition(int index, int& x, int& y)
{
	Resourse_m_data[index].setPosition(x, y);
}

inventory::~inventory() 
{
	delete[] Resourse_m_data;
	Resourse_m_data			= nullptr;
}
