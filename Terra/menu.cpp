#include "Menu.h"

int menuMain(sf::RenderWindow* window, GameState& state)
{
	//���-�� ������ � ����
	window->setActive();

	
	do
	{
		//����� ������ � ����
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window->close();
				state.setState(4);
			}

			//�������� ���������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				 state.setState(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				state.setState(4);
			}
			
		}

		//������������ ������ � ����

		//Render
		window->clear(sf::Color::Green);
		
		window->display();

		
		
		//*****************�������*********************************

		//��������� � ������ 3(������� �������)
		/*
		if (state.getState() == 3) 
		{
			state.setState(gameMain(window, state));
		} //��������� ������� �������, ������� 4 ��� 2 �� ��������
		*/

		if (state.getState() == 3) { return 3; }

	} while (state.getState() != 4);

	return 4;
}