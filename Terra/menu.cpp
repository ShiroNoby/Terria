#include "Menu.h"

int menuMain(sf::RenderWindow* window, GameState& state)
{
	//что-то делаем в меню
	window->setActive();
	sf::CircleShape rectangle(50.f, 4);
	
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
		}

		//обрабатываем отклик в меню

		//Render
		window->clear(sf::Color::Green);
		window->draw(rectangle);
		window->display();

		
		
		//*****************переход*********************************

		//переходим в стадию 3(игровой процесс)
		if (state.getState() == 3) 
		{
			state.setState(gameMain(window, state));
		} //выполняем игровой процесс, ожидаем 4 или 2 на возврате

	} while (state.getState() == 2);

	return 4;
}