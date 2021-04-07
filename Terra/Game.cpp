#include "Game.h"

int gameMain(sf::RenderWindow* window, GameState& state) 
{
	window->setActive(true);

	//генерация мира
	

	do
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				state.setState(4);
			}

			//проверка навигации
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				state.setState(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				state.setState(4);
			}
		}

		window->clear(sf::Color::Black);

		window->display();

		/*
		//возврат в гл. Меню
		//state.setstate(2);
		*/

	} while (state.getState() == 3);

	return state.getState();
}