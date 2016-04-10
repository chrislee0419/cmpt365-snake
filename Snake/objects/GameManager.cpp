/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include "GameManager.h"
#include "_macro.h"

using glm::ivec2;

// Constructor
GameManager::GameManager()
{
	_top_menu = new Menu();
	_game = new Game();
	_game_state = STATE_INSTRUCT;
}

// Destructor
GameManager::~GameManager()
{
	delete _top_menu;
	delete _game;
}

// Input methods
void GameManager::Instructions()
{
	_game_state = STATE_INSTRUCT;
}

void GameManager::PlayerDirection(int direction)
{
	if (_game_state != STATE_PLAY)
		return;

	switch (direction)
	{
	case MOVE_UP:
		_game->UpdateDirection(ivec2(0, 1));
		break;
	case MOVE_DOWN:
		_game->UpdateDirection(ivec2(0, -1));
		break;
	case MOVE_LEFT:
		_game->UpdateDirection(ivec2(-1, 0));
		break;
	case MOVE_RIGHT:
		_game->UpdateDirection(ivec2(1, 0));
	}
}

// Timer method
int GameManager::Timer()
{
	if (_game_state != STATE_PLAY)
		;
	return 0;
}

// Rendering method
void GameManager::Draw()
{
	_top_menu->Draw();
	//_game->Draw();
}