#ifndef _GAME_STATE_
#define _GAME_STATE_

class GameState 
{
	int m_state;
	
public:

	GameState();
	~GameState() {}

	void setState(int state);
	int getState() const;

	void operator++();
};

#endif _GAME_STATE_s