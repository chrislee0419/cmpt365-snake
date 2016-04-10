/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include "GameManager.h"

// Constructor
GameManager::GameManager()
{
	_top_menu = new Menu();
	_game = new Game();
	_game_state = INSTRUCTIONS;
}

// Destructor
GameManager::GameManager()
{
	delete _top_menu;
	delete _game;
}

// Rendering method
void GameManager::Draw()
{
	_top_menu->Draw();
	_game->Draw();
}