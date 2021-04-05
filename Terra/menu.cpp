#include "Menu.h"

int menuMain(sf::RenderWindow* window, GameState& state)
{
	//что-то делаем в меню
	window->setActive();

	
	do
	{
		//ловим отклик в меню
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window->close();
				state.setState(4);
			}

			//проверка навигации
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				 state.setState(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				state.setState(4);
			}
			
		}

		//обрабатываем отклик в меню

		//Render
		window->clear(sf::Color::Green);
		
		window->display();

		
		
		//*****************переход*********************************

		//переходим в стадию 3(игровой процесс)
		/*
		if (state.getState() == 3) 
		{
			state.setState(gameMain(window, state));
		} //выполняем игровой процесс, ожидаем 4 или 2 на возврате
		*/

		if (state.getState() == 3) { return 3; }

	} while (state.getState() != 4);

	return 4;
}