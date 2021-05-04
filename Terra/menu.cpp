#include "Menu.h"

//class Object_menu
//*********************************************************************************

Object_menu::Object_menu() 
	:Object_m_data(nullptr), m_length(0), m_size(0) {}

Object_menu::Object_menu(int length) 
{
	if (length) 
	{ 
		m_length							= length;
		Object_m_data						= new Object[m_length];
	}
	m_size = 0;
}

void Object_menu::upSize()
{
	this->m_size++;
}

void Object_menu::push(const Object& Object) 
{
	if (m_size != m_length) 
	{
		this->Object_m_data[m_size]			= Object;
		++m_size;
	}
}

void Object_menu::Move_Push(Object&& Object)
{
	this->push(Object);

	Object.getInventory().null();
}

Object& Object_menu::operator[](const int& index) 
{
	return this->Object_m_data[index];
}

Object_menu& Object_menu::operator=(Object_menu& MENU)
{	
	this->m_length = MENU.m_length;

	Object_m_data = new Object[this->m_length];


	for (int index = 0; index < MENU.m_size; index++) 
	{
		this->push(MENU.Object_m_data[index]);
	}
	return *this;
}

Object_menu& Object_menu::operator=(Object_menu&& MENU)
{
	this->m_length	= MENU.m_length;
	this->m_size	= MENU.m_size;

	Object_m_data = new Object[this->m_length];

	for (int index = 0; index < MENU.m_size; index++)
	{
		this->push(MENU.Object_m_data[index]);
	}

	MENU.Object_m_data = nullptr;
	return *this;
}

const int& Object_menu::getSize()
{
	return m_size;
}

Object_menu::~Object_menu() 
{
	for (int index = 0; index < m_size;index++) 
	{
		this->Object_m_data[index].~Object();
	}

	delete[] Object_m_data;
	Object_m_data							= nullptr;
}

//Menu Logic
//*********************************************************************************

//Object_menu init()
//{
//	//инизиализация объектов
//	Object_menu MENU(20);
//
//	sf::RectangleShape		Rectbottom;
//	sf::RenderTexture		Rendertexture;
//	sf::Texture				texture;
//	Object					bottom(Object_type::NON_OBJECT);
//
//	//примерные размеры кнопки
//	Rectbottom.setSize(sf::Vector2f((float)(HEIGTH * 3 / 8), (float)(LENGTH / 8)));
//	Rectbottom.setFillColor(sf::Color::Red);
//
//	Rendertexture.create(Rectbottom.getSize().x, Rectbottom.getSize().y);
//
//	Rendertexture.clear();
//	Rendertexture.draw(Rectbottom);
//	Rendertexture.display();
//
//	texture = Rendertexture.getTexture();
//
//	bottom.setTexture(texture, 0, 0, 300, 75);
//	bottom.setPosition((float)(HEIGTH*9/16), (float)(LENGTH/8));
//
//	MENU.push(bottom);
//
//	return MENU;
//}


void init(Object_menu& MENU)
{

	//позже дабавлю текстуру
	sf::RectangleShape		Rectbottom;
	sf::RenderTexture		Rendertexture;
	sf::Texture				texture;


	/*
	OBJECT_New_Game		= 1,
	OBJECT_Load_Game	= 2,
	OBJECT_Exit			= 3,
	OBJECT_Yes			= 4,

	OBJECT_No			= 5,
	OBJECT_Genered_Seed = 6,
	OBJECT_Seed			= 7,
	OBJECT_Ok			= 8,

	OBJECT_Cancel		= 9,
	OBJECT_Screan_Shot	= 10,
	OBJECT_Load			= 11,
	*/

	//множетели от размера экрана
	//размеры кнопок
	float f_rect_Heigth[(int)Object_type::MAX_OBJECT_MENU]			= { H / 3.F,	H / 3.F,		H / 3.F ,		H / 7.F,
																		H / 7.F,	H * 3.F / 8,	H * 3.F / 8,	H / 7.F,
																		H / 7.F,	H * 1.F / 3,	H / 3.F };
	//размеры кнопок
	float f_rect_Length[(int)Object_type::MAX_OBJECT_MENU]			= { L / 9.F,	L / 9.F,		L / 9.F,		L / 9.F,
																		L / 9.F,	L / 9.F,		L / 9.F,		L / 9.F,
																		L / 9.F,	L / 2.F,		L / 11.F };

	//координаты кнопок
	float f_x[(int)Object_type::MAX_OBJECT_MENU]						= { H * 5.F / 8,			H * 5.F / 8,				H * 5.F / 8,				H * 1.F / 3,
																		H * 2.F / 3,				H * 3.F / 8,				H * 3.F / 8,				H * 5.F / 16,
																		H * 9.F / 16,				H / 2.F,					H * 1.F / 16 };
	//координаты кнопок
	float f_y[(int)Object_type::MAX_OBJECT_MENU]						= { L / 4.F,				L / 4.F + (L / 9 + 50),		f_y[1] + (L / 9 + 50),		L * 3.F / 4,
																		f_y[3],						(L / 2.F) - (L / 9),		(L / 4.F) - (L / 9),		(L * 3.F / 4) - (L / 9) ,
																		(L * 3.F / 4) - (L / 9),	(L / 4.F) - (L / 9),		(L / 4.F) - (L / 9) };


	Rendertexture.create(H, L);
	
	for (int index = 0; index < (int)Object_type::MAX_OBJECT_MENU - 1; index++)
	{

		Rectbottom.setSize(sf::Vector2f(f_rect_Heigth[index], f_rect_Length[index]));
		Rectbottom.setFillColor(sf::Color::Red);

		

		Rendertexture.clear();
		Rendertexture.draw(Rectbottom);
		Rendertexture.display();

		texture = Rendertexture.getTexture();

		MENU[index].setTexture(texture, 0, 0, f_rect_Heigth[index], f_rect_Length[index]);
		MENU[index].setColor(Rectbottom);
		MENU[index].setPosition(f_x[index], f_y[index]);

		MENU.upSize();
	}
}
	

void build_scene(sf::RenderTexture& MENU,  Object_menu& array, GameState& state)
{
	//построение сцены в зависимости от стадии

	MENU.clear(sf::Color::White);

	
	switch (state.getStateMenu())
	{
		case Menu_State::Main_Menu: 
			
				MENU.draw(array[0].getSprite());
				MENU.draw(array[1].getSprite());
				MENU.draw(array[2].getSprite());
				
			MENU.display();
			break;
		case Menu_State::New_Game:
			
			MENU.draw(array[5].getSprite());
			MENU.draw(array[6].getSprite());
			MENU.draw(array[7].getSprite());
			MENU.draw(array[8].getSprite());

			MENU.display();
			break;
		case Menu_State::Load_Game:
			
			MENU.draw(array[9].getSprite());
			MENU.draw(array[11].getSprite());
			
			MENU.display();
			break;
		case Menu_State::Choise_Load_File:
			


			break;
		case Menu_State::Exit_Y_N:
			
			MENU.draw(array[3].getSprite());
			MENU.draw(array[4].getSprite());

			MENU.display();
			break;
	}
}





//main_menu
//*********************************************************************************

void main_menu(sf::RenderWindow* window, GameState& state)
{
	//работа с окном
	window->setActive();
	window->clear(sf::Color::Black);

	//работа с тектурами
	//потом с настройками разберусь
	sf::RenderTexture MENU;
	MENU.create(window->getSize().x, window->getSize().x);

	//мы будем рисовать с нуля объекты
	//sf::Texture Buffer_menu;


	//работа с объектами меню
	Object_menu Array_Object_menu((int)Object_type::MAX_OBJECT_MENU);

	init(Array_Object_menu);

	//init
	//*******************************************************************************

	//работа с текстурами
	sf::Sprite		sprite;
	sf::Texture		texture;

	//*******************************************************************************

	sf::Event event_menu;
	do
	{
		
		//Event-system
		while (window->pollEvent(event_menu)) 
		{
			//обработка клика
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			{
				switch (state.getStateMenu())
				{
					case Menu_State::Main_Menu:

						if (Array_Object_menu[0].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) 
						{
							state.setStateMenu(Menu_State::New_Game);
						}

						//Load game
						//if (Array_Object_menu[1].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) {}

						if (Array_Object_menu[2].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) 
						{
							state.setStateMenu(Menu_State::Exit_Y_N);
						}

						continue;
					case Menu_State::New_Game:

						if (Array_Object_menu[8].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) 
						{
							state.setStateMenu(Menu_State::Main_Menu);
						}
						/*
						if () {}
						if () {}
						if () {}
						/**/

						continue;
					case Menu_State::Load_Game:

						//if () {}
						//if () {}

						continue;
					case Menu_State::Exit_Y_N:

						if (Array_Object_menu[3].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) 
						{
							window->clear(sf::Color::Black);
							state.setState(4);

							Array_Object_menu.~Object_menu();
							MENU.~RenderTexture();
							window->setActive(false);

							return;
						}
						if (Array_Object_menu[4].contains(event_menu.mouseButton.x, event_menu.mouseButton.y)) 
						{
							state.setStateMenu(Menu_State::Main_Menu);
						}

						continue;
					case Menu_State::Choise_Load_File:

						continue;
				}
			}

			
			if (event_menu.type == sf::Event::Resized)
			{
				std::cout << "babah" << std::endl;
				
				float x, y;

				std::cout << "size " << Array_Object_menu.getSize() << std::endl;
				
				//потом разберусь
				/*for (int index = 0; index < Array_Object_menu.getSize(); index++) 
				{
					std::cout << "Index: " << index << std::endl;
					
					std::cout << "x " << Array_Object_menu[index].getPosition().x_pos << std::endl;
					std::cout << "y " << Array_Object_menu[index].getPosition().y_pos << std::endl;
									
					x = (float)Array_Object_menu[index].getPosition().x_pos;
					y = (float)Array_Object_menu[index].getPosition().y_pos;

					std::cout << "getPos	";
					std::cout << "x " << x;
					std::cout << "	y " << y << std::endl;

					if (event_menu.size.width > H) 
					{ 
						x = (x * event_menu.size.width) / H; 
					}
					else { x = (x * H / event_menu.size.width); }

					if (event_menu.size.height > L)
					{
						y = (y * event_menu.size.height) / L;
					}
					else { y = (y * L / event_menu.size.height) ; }
					
					std::cout << "setPos	";
					std::cout << "x " << x;
					std::cout << "	y " << y << std::endl;

					Array_Object_menu[index].setPosition(x, y);
				}*/

				window->clear();
			}
			
			

			if (sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
				{
					window->close();

					state.setState(4);
					
					Array_Object_menu.~Object_menu();
					MENU.~RenderTexture();
					window->setActive(false);

					
					return;
				}
			}
		}

		build_scene(MENU, Array_Object_menu, state);


		texture = MENU.getTexture();
		sprite.setTexture(texture);
	


		window->draw(sprite);


		window->display();


	} while (state.getState() == 2);

	Array_Object_menu.~Object_menu();
	MENU.~RenderTexture();
	window->setActive(false);
}

/*

//что-то делаем в меню
	window->setActive(true);

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
		*//*

if (state.getState() == 3) { return 3; }

	} while (state.getState() != 4);

	return 4;
*/