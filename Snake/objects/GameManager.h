/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "game\Menu.h"
#include "game\Game.h"
#include "game\AudioManager.h"
#include "game\InstructionsMenu.h"

class GameManager
{
private:
	int _game_state;
	int _prev_game_state;
	int _game_speed;
	Menu *_top_menu;
	Game *_game;
	AudioManager *_audio;
	InstructionsMenu *_instruct;

	void _RestartGame();

public:
	GameManager();
	~GameManager();

	int Instructions();
	int Pause();
	int Reset();
	void PlayerDirection(int action);

	int GetState();
	int Timer();

	void Draw();
};