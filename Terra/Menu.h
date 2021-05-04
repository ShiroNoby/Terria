#ifndef		_MENU_
#define		_MENU_

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Game_State.h"

#include "Game_Objects.h"

#define H 1920
#define L 1080

class Object_menu;

//постройка сцены на текстуре
//для дальнейшей обработки или вывода на экран
void build_scene(sf::RenderTexture& MENU, Object_menu& array, GameState& state);

//заполнение массива объектов
//Object_menu init();
void init(Object_menu& MENU);

//главное меню
void main_menu(sf::RenderWindow* window, GameState& state);

//массив объектов
class Object_menu 
{
	Object*				Object_m_data;
	int					m_length;
	int					m_size;

public:

	Object_menu();

	Object_menu(int length);

	void upSize();

	void push(const Object& Object);

	void Move_Push(Object&& Object);

	Object& operator[](const int& index);

	//coppy
	Object_menu& operator=(Object_menu& MENU);

	//move
	Object_menu& operator=(Object_menu&& MENU);

	const int& getSize();

	~Object_menu();
};
#endif		_MENU_