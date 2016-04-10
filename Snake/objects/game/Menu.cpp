/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include <stdio.h>
#include "..\_colours.h"
#include "Menu.h"

using std::string;

// Constructor
Menu::Menu()
{
	_score = 0;
	_highscore = 0;

	// memory allocation
	_background = (Box*)malloc(sizeof(Box));
	_scorebox = (Box*)malloc(sizeof(Box));
	_highscorebox = (Box*)malloc(sizeof(Box));
	_scoretext = (Text*)malloc(sizeof(Text));
	_scorenumber = (Text*)malloc(sizeof(Text));
	_highscoretext = (Text*)malloc(sizeof(Text));
	_highscorenumber = (Text*)malloc(sizeof(Text));
	_snakebox = (Box*)malloc(sizeof(Box)* 72);

	// initialization
	*_background = Box(800, 200, 0, 0, 10, DARKGREY, BLACK);
	*_scorebox = Box(300, 105, 0, 95, 10, DARKGREY, BLACK);
	*_highscorebox = Box(300, 105, 0, 0, 10, DARKGREY, BLACK);
	*_scoretext = Text(0, 1.0f, "Score:", 20, 175, RED);
	*_scorenumber = Text(0, 1.0f, "000000", 150, 115, WHITE);
	*_highscoretext = Text(0, 1.0f, "High Score:", 20, 75, RED);
	*_highscorenumber = Text(0, 1.0f, "000000", 150, 20, WHITE);

	// initialize snake box
	// S
	_snakebox[0] = Box(16, 16, 325, 60, 2, GOLD, YELLOW);
	_snakebox[1] = Box(16, 16, 341, 60, 2, GOLD, YELLOW);
	_snakebox[2] = Box(16, 16, 357, 60, 2, GOLD, YELLOW);
	_snakebox[3] = Box(16, 16, 373, 60, 2, GOLD, YELLOW);
	_snakebox[4] = Box(16, 16, 389, 60, 2, GOLD, YELLOW);
	_snakebox[5] = Box(16, 16, 389, 76, 2, GOLD, YELLOW);
	_snakebox[6] = Box(16, 16, 325, 92, 2, GOLD, YELLOW);
	_snakebox[7] = Box(16, 16, 341, 92, 2, GOLD, YELLOW);
	_snakebox[8] = Box(16, 16, 357, 92, 2, GOLD, YELLOW);
	_snakebox[9] = Box(16, 16, 373, 92, 2, GOLD, YELLOW);
	_snakebox[10] = Box(16, 16, 389, 92, 2, GOLD, YELLOW);
	_snakebox[11] = Box(16, 16, 325, 108, 2, GOLD, YELLOW);
	_snakebox[12] = Box(16, 16, 325, 124, 2, GOLD, YELLOW);
	_snakebox[13] = Box(16, 16, 341, 124, 2, GOLD, YELLOW);
	_snakebox[14] = Box(16, 16, 357, 124, 2, GOLD, YELLOW);
	_snakebox[15] = Box(16, 16, 373, 124, 2, GOLD, YELLOW);
	_snakebox[16] = Box(16, 16, 389, 124, 2, RED, PINK);
	// N
	_snakebox[17] = Box(16, 16, 415, 60, 2, GOLD, YELLOW);
	_snakebox[18] = Box(16, 16, 415, 76, 2, GOLD, YELLOW);
	_snakebox[19] = Box(16, 16, 415, 92, 2, GOLD, YELLOW);
	_snakebox[20] = Box(16, 16, 415, 108, 2, GOLD, YELLOW);
	_snakebox[21] = Box(16, 16, 415, 124, 2, GOLD, YELLOW);
	_snakebox[22] = Box(16, 16, 431, 108, 2, GOLD, YELLOW);
	_snakebox[23] = Box(16, 16, 447, 92, 2, GOLD, YELLOW);
	_snakebox[24] = Box(16, 16, 463, 76, 2, GOLD, YELLOW);
	_snakebox[25] = Box(16, 16, 479, 60, 2, GOLD, YELLOW);
	_snakebox[26] = Box(16, 16, 479, 76, 2, GOLD, YELLOW);
	_snakebox[27] = Box(16, 16, 479, 92, 2, GOLD, YELLOW);
	_snakebox[28] = Box(16, 16, 479, 108, 2, GOLD, YELLOW);
	_snakebox[29] = Box(16, 16, 479, 124, 2, RED, PINK);
	// A
	_snakebox[30] = Box(16, 16, 505, 60, 2, GOLD, YELLOW);
	_snakebox[31] = Box(16, 16, 505, 76, 2, GOLD, YELLOW);
	_snakebox[32] = Box(16, 16, 505, 92, 2, GOLD, YELLOW);
	_snakebox[33] = Box(16, 16, 505, 108, 2, GOLD, YELLOW);
	_snakebox[34] = Box(16, 16, 569, 60, 2, RED, PINK);
	_snakebox[35] = Box(16, 16, 569, 76, 2, GOLD, YELLOW);
	_snakebox[36] = Box(16, 16, 569, 92, 2, GOLD, YELLOW);
	_snakebox[37] = Box(16, 16, 569, 108, 2, GOLD, YELLOW);
	_snakebox[38] = Box(16, 16, 521, 124, 2, GOLD, YELLOW);
	_snakebox[39] = Box(16, 16, 537, 124, 2, GOLD, YELLOW);
	_snakebox[40] = Box(16, 16, 553, 124, 2, GOLD, YELLOW);
	_snakebox[41] = Box(16, 16, 521, 92, 2, GOLD, YELLOW);
	_snakebox[42] = Box(16, 16, 537, 92, 2, GOLD, YELLOW);
	_snakebox[43] = Box(16, 16, 553, 92, 2, GOLD, YELLOW);
	// K
	_snakebox[44] = Box(16, 16, 595, 60, 2, GOLD, YELLOW);
	_snakebox[45] = Box(16, 16, 595, 76, 2, GOLD, YELLOW);
	_snakebox[46] = Box(16, 16, 595, 92, 2, GOLD, YELLOW);
	_snakebox[47] = Box(16, 16, 595, 108, 2, GOLD, YELLOW);
	_snakebox[48] = Box(16, 16, 595, 124, 2, GOLD, YELLOW);
	_snakebox[49] = Box(16, 16, 659, 60, 2, GOLD, YELLOW);
	_snakebox[50] = Box(16, 16, 643, 76, 2, GOLD, YELLOW);
	_snakebox[51] = Box(16, 16, 627, 92, 2, GOLD, YELLOW);
	_snakebox[52] = Box(16, 16, 643, 108, 2, GOLD, YELLOW);
	_snakebox[53] = Box(16, 16, 659, 124, 2, RED, PINK);
	_snakebox[54] = Box(16, 16, 611, 92, 2, GOLD, YELLOW);
	// E
	_snakebox[55] = Box(16, 16, 685, 60, 2, GOLD, YELLOW);
	_snakebox[56] = Box(16, 16, 701, 60, 2, GOLD, YELLOW);
	_snakebox[57] = Box(16, 16, 717, 60, 2, GOLD, YELLOW);
	_snakebox[58] = Box(16, 16, 733, 60, 2, GOLD, YELLOW);
	_snakebox[59] = Box(16, 16, 749, 60, 2, RED, PINK);
	_snakebox[60] = Box(16, 16, 685, 76, 2, GOLD, YELLOW);
	_snakebox[61] = Box(16, 16, 685, 92, 2, GOLD, YELLOW);
	_snakebox[62] = Box(16, 16, 701, 92, 2, GOLD, YELLOW);
	_snakebox[63] = Box(16, 16, 717, 92, 2, GOLD, YELLOW);
	_snakebox[64] = Box(16, 16, 733, 92, 2, GOLD, YELLOW);
	_snakebox[65] = Box(16, 16, 749, 92, 2, GOLD, YELLOW);
	_snakebox[66] = Box(16, 16, 685, 108, 2, GOLD, YELLOW);
	_snakebox[67] = Box(16, 16, 685, 124, 2, GOLD, YELLOW);
	_snakebox[68] = Box(16, 16, 701, 124, 2, GOLD, YELLOW);
	_snakebox[69] = Box(16, 16, 717, 124, 2, GOLD, YELLOW);
	_snakebox[70] = Box(16, 16, 733, 124, 2, GOLD, YELLOW);
	_snakebox[71] = Box(16, 16, 749, 124, 2, GOLD, YELLOW);

}

// Destructor
Menu::~Menu()
{
	// free data structures
	free(_background);
	free(_scorebox);
	free(_scoretext);
	free(_scorenumber);
	free(_highscorebox);
	free(_highscoretext);
	free(_highscorenumber);
	free(_snakebox);
}

void Menu::ResetScore()
{
	_score = 0;
}

void Menu::SetHighScore(int score)
{
	_highscore = score;
}

void Menu::IncrementScore()
{
	if (_highscore < ++_score)
		SetHighScore(_score);
}

// Rendering method
void Menu::Draw()
{
	_SetScoreNumber();
	_SetHighScoreNumber();

	_background->Draw(0, 600);
	_scorebox->Draw(0, 600);
	_scoretext->Draw(0, 600);
	_scorenumber->Draw(0, 600);
	_highscorebox->Draw(0, 600);
	_highscoretext->Draw(0, 600);
	_highscorenumber->Draw(0, 600);
	for (int i = 0; i < 72; i++)
		_snakebox[i].Draw(0, 600);
}

// Helper methods
void Menu::_SetScoreNumber()
{
	char score[7] = { 0 };
	sprintf_s(score, sizeof(score), "%6d", _score % 1000000);

	string text = string(score);
	_scorenumber->SetText(text);
}

void Menu::_SetHighScoreNumber()
{
	char score[7] = { 0 };
	sprintf_s(score, sizeof(score), "%6d", _highscore % 1000000);

	string text = string(score);
	_highscorenumber->SetText(text);
}
