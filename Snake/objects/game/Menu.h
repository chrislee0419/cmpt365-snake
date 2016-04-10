/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#pragma once

#include "..\menu\Box.h"
#include "..\menu\Text.h"

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

public:
	Menu();
	~Menu();

	int GetScore();

	void SetScore(int score);
	void SetHighScore();
	void IncrementScore();

	void Draw();

};
