#include "SFML/Graphics.hpp"

#include "Game_State.h"
#include "Menu.h"

#define HEIGTH 800
#define LENGTH 600

//сымопальный способ контроля состояния программы
/*
void gameStatusChange(sf::CircleShape& shape, int state) 
{
	sf::Color cls;

	switch (state)
	{
		case 1:
			cls =  sf::Color::Red;
			break;
		case 2:
			cls = sf::Color::Green;
			break;
		case 3:
			cls = sf::Color::Blue;
			break;
	}

	shape.setFillColor(cls);
}
*/


//init
sf::CircleShape shape(100.f, 4);
GameState		state;					//state = 1




int main() 
{
	sf::RenderWindow window(sf::VideoMode(HEIGTH, LENGTH), "non-window");

	shape.setOrigin(100.f, 100.f);
	shape.setPosition(HEIGTH / 2, LENGTH / 2);

	int count = 1;



	while (window.isOpen()) 
	{
		//Event
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) { window.close(); }
		}

		

		//выполнение стадий
		if ((state.getState() == 1) && (count < 10000))
		{
			//предположим тут стадия загрузки 
			shape.setFillColor(sf::Color::Red);
			shape.rotate(0.1f);
			count++;
		}

		if (state.getState() == 2) 
		{
			//а тут стадия главного меню
			menuMain(&state, shape);

			//пс, пока возврат не нужен

			count = 0;
		}


		//Render
		window.clear(sf::Color::White);

		window.draw(shape);

		window.display();
	}
}