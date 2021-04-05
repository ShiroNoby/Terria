#include "SFML/Graphics.hpp"

#include "Game_State.h"
#include "Menu.h"
#include "Game.h"

#define HEIGTH 800
#define LENGTH 600


int main() 
{
	//init
	GameState		state;					//state = 1

	sf::RenderWindow window(sf::VideoMode(HEIGTH, LENGTH), "non-window");
	
	//���-�� ������ ��� ������ 1

	state.setState(2); //��������� �� ������ ����

	/*
	do
	{

		state.setState( menuMain(&window, state));

	} while (state.getState() == 2);
	*/

	/*
		� ������� ����� � ��������� menu � game ������ ������
		state, � ���������� ��� ������ ��� success
	*/

	do
	{
		window.clear();
		window.display();

		if (state.getState() == 2) { state.setState(menuMain(&window, state)); }
		if (state.getState() == 3) { state.setState(gameMain(&window, state)); }


	} while (state.getState() != 4);

	if (window.isOpen()) { window.close(); }
	return 0;
}