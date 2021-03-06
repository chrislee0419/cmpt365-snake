/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "..\basic\Box.h"
#include "..\basic\Text.h"

class Menu
{
private:
	int _score;
	int _highscore;

	Box *_background;

	Box *_scorebox;
	Text *_scoretext;
	Text *_scorenumber;

	Box *_highscorebox;
	Text *_highscoretext;
	Text *_highscorenumber;

	Box *_snakebox;

	void _SetScoreNumber();
	void _SetHighScoreNumber();
	void _SetHighScore();

public:
	Menu();
	~Menu();

	void ResetScore();
	void ResetHighScore();
	void IncrementScore();

	void Draw();

};
