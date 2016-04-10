/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

/*
	NOTES FOR SELF:
	- game board should be wider than its height (room for top bar)
	- 800 x 600

	- 10 pixel grey border around
	- game area - 780 x 580
	- black background

	- game blocks = 39 x 29
	- block size = 20 x 20

	- player head is red
	- player body is yellow


*/

#include "Game.h"
#include "..\test.h"
#include "..\_util.h"

using namespace std;

// Globals 

// Window size
float xsize = 800.0;
float ysize = 600.0;

glm::vec2 tilepos = glm::vec2(20, 15);

// board[x][y] represents whether the cell (x, y) is occupied
bool board[39][29];

// Constructor
Game::Game()
{
	Init();
}

// Destructor
Game::~Game()
{

}

void Game::Init()
{
	_InitBoard();
	_InitStart();
}

void Game::Move(glm::vec2 direction)
{

}

// Private helper methods
void Game::_InitBoard()
{
	Box *board_init = (Box*)malloc(sizeof(Box) * (29 * 39));
	int k = 0;

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 39; j++)
		{
			board_init[k] = Box(20, 20, 20 * j, 20 * i, BLACK, BLACK);
			k++;
		}
	}

	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 39; j++)
			board[i][j] = false;

	for (int i = 0; i < 29 * 39; i++)
		board_init[i].Draw(0, 0);
}

void Game::_InitStart()
{
	Box *snake_init = (Box*)malloc(sizeof(Box) * 1);
	snake_init[0] = Box(20, 20, 20 * tilepos[0], 20 * tilepos[1], RED, RED);
	snake_init[0].Draw(0, 0);
}

//void Test::_CreateGameTest()
//{
//
//}
//
//void Test::_DisplayGameTest()
//{
//
//}