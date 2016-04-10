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
using glm::ivec2;

// Globals 
// Starting position

// Constructor
Game::Game()
{
	// seed rand - only done once
	srand(time(NULL));

	_InitBoard();
	_InitStart();
}

// Destructor
Game::~Game()
{
	delete _background;
	free(_board_box);
}

// Game functions
void Game::Restart()
{
	// makes board all good
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 39; j++)
			_board[i][j] = BOARD_GOOD;

	_InitStart();
}

void Game::UpdateDirection(glm::ivec2 direction)
{
	// cannot move in reverse direction
	if ( !(-_current_direction == direction) )
		_current_direction = direction;
}

int Game::UpdatePosition()
{
	ivec2 new_head = _head + _current_direction;

	// checks if it hits a occupied block (i.e. apart of the snake body)
	if (_board[new_head.x][new_head.y] == BOARD_OCCUPIED)
		return MOVE_HIT;

	// checks if it has hit the left and right boundaries
	else if (new_head.x < 0 || new_head.x > 39)
		return MOVE_HIT;

	// checks if it has hit the top and bottom boundaries
	else if (new_head.y < 0 || new_head.y > 29)
		return MOVE_HIT;

	// checks if it has hit a fruit
	else if (_board[new_head.x][new_head.y] == BOARD_FRUIT)
	{
		_UpdateSnake(new_head, true);
		_GenerateFruit();
		return MOVE_GROW;
	}

	// else the block should be ok
	else
	{
		_UpdateSnake(new_head, false);
		return MOVE_OK;
	}
}

// Rendering method
void Game::Draw()
{
	// draw board
	for (int i = 0; i < 29 * 39; i++)
	{
		if (_board[i % 39][i / 39] != BOARD_GOOD)
			_board_box[i].Draw(0, 0);
	}
}

// Private helper methods
void Game::_InitBoard()
{
	_background = new Box(800, 600, 0, 0, 10, DARKGREY, BLACK);

	_board_box = (Box*)malloc(sizeof(Box) * (29 * 39));

	// every block is coloured like the snake body
	// only draw if snake is on block
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 39; j++)
			_board_box[i*39 + j] = Box(20, 20, 20 * j, 20 * i, GOLD, YELLOW);
	}

	// default game board to be good
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 39; j++)
			_board[i][j] = BOARD_GOOD;
}

void Game::_InitStart()
{
	// empties the snake for new game
	while (!_snake.empty())
		_snake.pop();

	// snake starts at length 3
	_head = ivec2(20, 15);
	_snake.push(_head);
	_snake.push(ivec2(21, 15));
	_snake.push(ivec2(22, 15));
	_board[20][15] = BOARD_OCCUPIED;
	_board[21][15] = BOARD_OCCUPIED;
	_board[22][15] = BOARD_OCCUPIED;
	_board_box[20 + 15 * 39].SetColour(RED, PINK);

	// start moving left
	_current_direction = ivec2(-1, 0);

	// generate random fruit
	_GenerateFruit();
}

void Game::_GenerateFruit()
{
	int x = rand() % 39;
	int y = rand() % 29;

	while (_board[x][y] == BOARD_OCCUPIED)
	{
		x = rand() % 39;
		y = rand() % 29;
	}

	// set as fruit
	_board[x][y] = BOARD_FRUIT;

	// colour the fruit location
	_board_box[x + y * 39].SetColour(DARKGREEN, LIGHTGREEN);
}

void Game::_UpdateSnake(ivec2 new_head, bool grow)
{
	// set current head to body
	_board_box[_head.x + _head.y * 39].SetColour(GOLD, YELLOW);

	// set new head to occupied
	_head = new_head;
	_board[_head.x][_head.y] = BOARD_OCCUPIED;
	_board_box[_head.x + _head.y * 39].SetColour(RED, PINK);
	_snake.push(_head);

	// if snake did not grow, pop tail
	if (!grow)
	{
		ivec2 tail = _snake.front();
		_board[tail.x][tail.y] = BOARD_GOOD;
		_snake.pop();
	}
}
