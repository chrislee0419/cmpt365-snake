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

// Starting position
glm::ivec2 head = glm::ivec2(20, 15);

// board[x][y] represents whether the cell (x, y) is occupied
int board[39][29];

// Constructor
Game::Game()
{
	Init();
}

// Destructor
Game::~Game()
{
	free(_board_init);
	free(_snake_init);
}

// Game functions
void Game::Init()
{
	_InitBoard();
	_InitStart();
}

int Game::UpdatePosition()
{
	// checks if it hits a occupied block (i.e. apart of the snake body)
	if (board[(head[0])][(head[1])] == BOARD_OCCUPIED)
		return MOVE_HIT;
	
	// checks if it has hit the left and right boundaries
	else if ((head[0]) < 0 || (head[0]) > 40)
		return MOVE_HIT;
	
	// checks if it has hit the top and bottom boundaries
	else if ((head[1]) < 0 || (head[1]) > 30)
		return MOVE_HIT;

	// checks if it has hit a fruit
	else if (board[(head[0])][(head[1])] == BOARD_FRUIT)
		return MOVE_GROW;

	// else the block should be ok
	else
		return MOVE_OK;
}

void Game::UpdateDirection(glm::ivec2 direction)
{
	_current_direction = direction;
}

void Game::GenerateFruit()
{
	int x = rand() % 39;
	int y = rand() % 29;

	while (board[x][y] == BOARD_OCCUPIED)
	{
		x = rand() % 39;
		y = rand() % 29;
	}

	// set as fruit
	board[x][y] = BOARD_FRUIT;

	// colour the fruit location
	_board_init[x + y * 39].SetOuterColour(YELLOW);
	_board_init[x + y * 39].SetInnerColour(YELLOW);
}

// Rendering method
void Game::Draw()
{
	// draw board
	for (int i = 0; i < 29 * 39; i++)
		_board_init[i].Draw(0, 0);

	// draw snake head
	_snake_init[0].Draw(0, 0);
}

// Private helper methods
void Game::_InitBoard()
{
	_board_init = (Box*)malloc(sizeof(Box) * (29 * 39));
	int k = 0;

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 39; j++)
		{
			_board_init[k] = Box(20, 20, 20 * j, 20 * i, BLACK, BLACK);
			k++;
		}
	}

	// default game board to be good
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 39; j++)
			board[i][j] = BOARD_GOOD;
}

void Game::_InitStart()
{
	_snake_init = (Box*)malloc(sizeof(Box) * 1);
	_snake_init[0] = Box(20, 20, head[0], head[1], RED, RED);

	// seed the time function
	srand(time(NULL));

	// generate random fruit
	GenerateFruit();
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