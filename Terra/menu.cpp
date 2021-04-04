#include "Menu.h"

int menuMain(sf::RenderWindow* window, GameState& state)
{
	//���-�� ������ � ����
	window->setActive();
	sf::CircleShape rectangle(50.f, 4);
	
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
		}

		//������������ ������ � ����

		//Render
		window->clear(sf::Color::Green);
		window->draw(rectangle);
		window->display();

		
		
		//*****************�������*********************************

		//��������� � ������ 3(������� �������)
		if (state.getState() == 3) 
		{
			state.setState(gameMain(window, state));
		} //��������� ������� �������, ������� 4 ��� 2 �� ��������

	} while (state.getState() == 2);

	return 4;
}