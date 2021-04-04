#include "Game.h"

int gameMain(sf::RenderWindow* window, GameState& state) 
{
	window->setActive();

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
		}

		window->clear(sf::Color::Black);

		window->display();

	} while (state.getState() == 3);

	return 4;
}