#include "Game_State.h"

GameState::GameState() : m_state(1)
{
	m_state_menu = Menu_State::Main_Menu;
}

int GameState::getState() const { return m_state; }

void GameState::setState(int state) { m_state = state; }

Menu_State& GameState::getStateMenu()
{
	return m_state_menu;
}

void GameState::setStateMenu(const Menu_State& state_menu)
{
	m_state_menu = state_menu;
}

void GameState::operator++() { m_state++; }