#include "Game_State.h"

GameState::GameState() : m_state(1) {}

int GameState::getState() const { return m_state; }

void GameState::setState(int state) { m_state = state; }

void GameState::operator++() { m_state++; }