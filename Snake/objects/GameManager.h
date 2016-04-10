/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "game\Menu.h"
#include "game\Game.h"

class GameManager
{
private:
	int _game_state;
	Menu *_top_menu;
	Game *_game;

public:
	GameManager();
	~GameManager();

	void Instructions();
	void Reset();
	void PlayerDirection(int action);

	int Timer();

	void Draw();
};