/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "game\Menu.h"
#include "game\Game.h"

#define INSTRUCTIONS 1
#define PAUSED 2
#define GAMEOVER 3
#define PLAY 10

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
	void PlayerAction(unsigned char c);

	void Draw();
};