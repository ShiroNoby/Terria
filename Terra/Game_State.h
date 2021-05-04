#ifndef _GAME_STATE_
#define _GAME_STATE_

enum class Menu_State
{
	INIT							= 0,
	Main_Menu						= 1,
	New_Game						= 2,
	Load_Game						= 3,
	Choise_Load_File				= 4,
	Exit_Y_N						= 5,
};


class GameState 
{
	int				m_state;
	Menu_State		m_state_menu;
	
public:

	GameState();
	~GameState() {}

	void setState(int state);
	int getState() const;

	Menu_State& getStateMenu();
	void setStateMenu(const Menu_State& state);

	void operator++();
};

#endif _GAME_STATE_s