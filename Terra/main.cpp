#include "SFML/Graphics.hpp"

#include "Game_State.h"
#include "Menu.h"

#define HEIGTH 800
#define LENGTH 600


int main() 
{
	//init
	GameState		state;					//state = 1

	sf::RenderWindow window(sf::VideoMode(HEIGTH, LENGTH), "non-window");
	
	//что-то делаем для стадии 1

	state.setState(2); //перехлдим на стадию меню

	do
	{

		state.setState( menuMain(&window, state));

	} while (state.getState() == 2);

	return 0;
}